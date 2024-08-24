/*****create user***/
const express = require("express");
const { createUser, getAllUser, getUserById, deleteUserById, updateUserById } = require("../controller/UserController");
const { protectRouteMiddleWare, isAdminMiddleWare } = require("../controller/AuthController");
const UserRouter = express.Router();
/****create product**/
UserRouter
    .post(createUser)
    .get(protectRouteMiddleWare, isAdminMiddleWare, getAllUser);
/*****get a product by it's ****/
UserRouter.route("/:id")
    .get(protectRouteMiddleWare, getUserById)
    .delete(protectRouteMiddleWare, deleteUserById)
    .patch(protectRouteMiddleWare, updateUserById);

module.exports = UserRouter;