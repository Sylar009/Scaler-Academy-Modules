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
    title: {
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
        default:0,
        validate: function () {
            return this.price > this.discount;
        }
    },
    brand: String,
    category: {
        type: String,
        required: true
    },
    image:{
        type:String,
        default:"https://picsum.photos/200/300"
    }
}
// checking for valid category
const productSchema = new mongoose.Schema(productSchemaRules);
const ProductModel = new mongoose.model("ProductModel", productSchema);
// place where all the products will go while following the schems
module.exports = ProductModel;