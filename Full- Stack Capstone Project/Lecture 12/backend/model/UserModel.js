/***
 * userModel -> 
 * schema
 *      uniqueID -> mongodb
 *      item name
 *      description 
 *      price
 *      discount
 * ***/
/**
 * rules that an entity should follow
 * **/
const mongoose = require("mongoose");
const bcrypt = require("bcrypt");
/***
 * amazon
 * **/
const userSchemaRules = {
    name: {
        type: String,
        required: true,
    },
    email: {
        type: String,
        required: true,
        unique: true,
    },
    password: {
        type: String,
        required: true,
        minlength: 8,
    },
    confirmPassword: {
        type: String,
        required: true,
        minlength: 8,
        // validate property 
        validate: function () {
            return this.password == this.confirmPassword
        }
    },
    role: {
        type: "String",
        default: "user"
    },
    otp: {
        type: String
    },
    otpExpiry: {
        type: Date
    },
    bookings: {
        // type of array of objectIds
        type: [mongoose.Schema.ObjectId],
        ref: "bookingModel"
    },
}
const userSchema = new mongoose.Schema(userSchemaRules);
userSchema.pre("save", async function (next) {
    this.confirmPassword = undefined;
    this.password=await bcrypt.hash(this.password,10);
    next();
})

// not send password to frontend 
userSchema.pre("findOne", function (next) {
    // filter
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
 * * dynamic set of roles
 * **/