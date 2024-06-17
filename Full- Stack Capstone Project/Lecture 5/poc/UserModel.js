/***
 * userModel -> 
 * schema
 *      uniqueID -> mongodb
 *      item name
 *      description 
 *      price
 *      discount
 *      
 * 
 * 
 * ***/
/**
 * rules that an entity should follow
 * **/
const mongoose = require("mongoose");
/***
 * amazon
 * **/
const userSchemaRules = {
    name: {
        type: String,
        required: [true,"Name is required for the user"],
    },
    email: {
        type: String,
        required: [true,"Email is required for the user"],
        unique: true
    },
    password: {
        type: String,
        required: [true,"Password is required for the user"],
        minlength: [8,"Password should be atleast 8 characters long"],
    },
    confirmPassword: {
        type: String,
        required: [true,"Confirm Password is required for the user"],
        minlength: [8,"confirm should be atleast 8 characters long"],
        // validate property 
        validate: [function () {
            return this.password == this.confirmPassword
        },"Password and Confirm Password should be same"]
    },
    role: {
        type: "String",
        default: "user"
    }
}
const userSchema = new mongoose.Schema(userSchemaRules);
// hooks -> remove confirm Password before saving the user in the db 
userSchema.pre("save", function (next) {
    this.confirmPassword = undefined;
    next();
})

// not send password to frontend 
userSchema.pre("findOne", function (next) {
    // filter
    this.select("-password");
    this.select("-__v");
    next();
});

// dynamic list of roles 
let roles = ["admin", "user", "vendor", "buyers"];
userSchema.pre("save", function (next) {
    if (roles.includes(this.role)) {
        next()
    }
    else {
        next("role is not defined");
    }
});
const UserModel = new mongoose.model("UserModel", userSchema);
// place where all the users will go while following the schems
module.exports = UserModel;
/****
 * * not saving confirmPassword
 * * dynamic set of roled
 * 
 * **/