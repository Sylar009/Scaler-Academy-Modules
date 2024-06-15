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
    }
}
const userSchema = new mongoose.Schema(userSchemaRules);
const UserModel = new mongoose.model("UserModel", userSchema);
// place where all the users will go while following the schems
module.exports = UserModel;

/****
 * * not saving confirmPassword
 * * dynamic set of roled
 * 
 * **/ 