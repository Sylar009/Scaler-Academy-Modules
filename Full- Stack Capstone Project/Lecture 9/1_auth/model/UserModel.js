const mongoose = require("mongoose");
// ecommerce -> Amazon 
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
    }
    ,
    confirmPassword: {
        type: String,
        required: true,
        minlength: 8,
        // validate property 
        validate: function () {
            return this.password == this.confirmPassword
        }
    },
    createdAt: {
        type: Date,
        default: Date.now()
    },
    // role 
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
}

// schema-> structure and validation 
const userSchema = new mongoose.Schema(userSchemaRules);
// check for the user that is currentky created does it belong to a valid role or not
let roles = ["admin", "user", "vendor", "buyers"];
userSchema.pre("save", function (next) {
    if (roles.includes(this.role)) {
        next()
    }
    else {
        next("role is not defined");
    }
});
// this model -> will have queries 
const UserModel = mongoose.model("UserModel", userSchema);
module.exports = UserModel;