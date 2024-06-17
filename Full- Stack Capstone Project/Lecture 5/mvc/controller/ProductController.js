const ProductModel = require("../model/ProductModel");
// handler method
async function createProduct(req, res) {
    try {
        const productDetails = req.body;
        // adding thr product to mongodb
        const product = await ProductModel.create(productDetails);
        res.status(201).json({
            status: "successfull",
            message: `added  the product `,
            product: product
        })

    } catch (err) {
        res.status(502).json({
            status: "failure",
            message: err.message
        })
    }
}
async function getAllProducts(req, res) {
    try {
        // -> if you don't pass anything -> return you the whole collection
        // -> if want to filter -> parameter -> an object
        const listOfProduct = await ProductModel.find();
        res.status(200).json({
            status: "successfull",
            message: `list of the product `,
            ProductList: listOfProduct
        })
    } catch (err) {
        res.status(404).json({
            status: "failure",
            message: err.message
        })
    }
}
async function getproductById(req, res) {
    try {
        const id = req.params.id
        const product = await ProductModel.findById(id);
        if (product) {
            res.status(200).json({
                status: "successfull",
                message: `got the product `,
                product: product
            })
        } else {
            throw new Error("Product not found");
        }
    } catch (err) {
        res.status(404).json({
            status: "failure",
            message: err.message
        })
    }
}
async function deleteProductById(req, res) {
    try {
        const id = req.params.id;
        const product = await ProductModel.findByIdAndDelete(id);
        if (product) {
            res.status(200).json({
                status: "successfull",
                message: `product is deleted`,
                product: product
            })
        } else {
            throw new Error("Product not found");
        }
    } catch (err) {
        res.status(404).json({
            status: "failure",
            message: err.message
        })
    }
}
async function updateProductById(req, res) {
    try {
        /***
         * 1. you will need -> id 
         * 2. you have pass the keys that they want to update
         * **/
        const id = req.params.id;
        const toUpdateObject = req.body;
        /**
         * some sanitation
         * *  should not be any keys that are not following our schema, _id
         * **/
        const product = await ProductModel.findByIdAndUpdate(id, toUpdateObject, { new: true });
        if (product) {
            res.status(200).json({
                status: "successfull",
                message: `product was updated`,
                product: product
            })
        } else {
            throw new Error("Product not found");
        }

    } catch (err) {
        res.status(404).json({
            status: "failure",
            message: err.message
        })
    }
}
module.exports={
    createProduct,
    getAllProducts,
    getproductById,
    deleteProductById,
    updateProductById,
}