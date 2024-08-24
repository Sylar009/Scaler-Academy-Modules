const ProductModel = require("../model/ProductModel");
// handler method
// handler method
const { createResourceFactory,
    getAllResourceFactory, getResourceByIdFactory,
    deleteResourceByIdFactory, updateResourceByIdFactory } = require("../utils/resourceFactory");
const createProduct = createResourceFactory(ProductModel);
const getAllProducts = getAllResourceFactory(ProductModel);
const getproductById = getResourceByIdFactory(ProductModel);
const deleteProductById = deleteResourceByIdFactory(ProductModel);
const updateProductById = updateResourceByIdFactory(ProductModel);
/****user***/
/*****handler*/
// hanlder method

module.exports = {
    createProduct,
    getAllProducts,
    getproductById,
    deleteProductById,
    updateProductById,
}