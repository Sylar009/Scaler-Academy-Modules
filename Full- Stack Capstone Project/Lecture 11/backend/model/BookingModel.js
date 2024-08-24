/***
 * bookingModel -> 
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

const bookingSchemaRules = {
    bookedAt: {
        type: Date,
        default: Date.now()
    },
    priceAtThatTime: {
        type: Number,
        required: true
    },
    // will be given to you by razorpay 
    payment_order_id: {
        type: String,
    },
    // we are specifying that -> 
    // user is a reference to the UserModel
    user: {
        type: mongoose.Schema.Types.ObjectId,
        ref: "UserModel"
    },
    // we are specifying that -> 
    // product is a reference to the ProductModel
    product: {
        type: mongoose.Schema.ObjectId,
        required: true,
        ref: "ProductModel"
    },
    status: {
        type: String,
        enum: ["pending", "failed", "success"],
        required: true,
        default: "pending"
    },

}
const bookingSchema = new mongoose.Schema(bookingSchemaRules);

const BookingModel = new mongoose.model("bookingModel", bookingSchema);
// place where all the bookings will go while following the schems
module.exports = BookingModel;