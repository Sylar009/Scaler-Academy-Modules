/***
 * ProductModel -> 
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
const productSchemaRules = {
    name: {
        type: String,
        required: true,
    },
    description: {
        type: String,
        required: true
    },
    price: {
        type: Number,
        required: true,
        min: 1
    },
    discount: {
        type: Number,
        validate: function () {
            return this.price > this.discount;
        }
    },
    brand: String,
    category: {
        type: String,
        required: true
    }
}
// checking for valid category
const productSchema = new mongoose.Schema(productSchemaRules);
const ProductModel = new mongoose.model("ProductModel", productSchema);
// place where all the products will go while following the schems
module.exports = ProductModel;