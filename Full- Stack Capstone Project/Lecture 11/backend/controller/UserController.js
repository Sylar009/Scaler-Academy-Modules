const UserModel = require("../model/UserModel");
const { createResourceFactory,
    getAllResourceFactory, getResourceByIdFactory,
    deleteResourceByIdFactory, updateResourceByIdFactory } = require("../utils/resourceFactory");
const createUser = createResourceFactory(UserModel);
const getAllUser = getAllResourceFactory(UserModel);
const updateUserById = updateResourceByIdFactory(UserModel);
const getUserById = getResourceByIdFactory(UserModel);
const deleteUserById = deleteResourceByIdFactory(UserModel);
module.exports = {
    createUser,
    getAllUser,
    updateUserById,
    getUserById,
    deleteUserById
}