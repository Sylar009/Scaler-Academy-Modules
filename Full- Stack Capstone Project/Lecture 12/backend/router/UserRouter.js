/*****create user***/
const express = require("express");
const { createUser, getAllUser, getUserById, deleteUserById, updateUserById } = require("../controller/UserController");
const { protectRouteMiddleWare, isAdminMiddleWare } = require("../controller/AuthController");
const UserRouter = express.Router();
const rateLimit = require("express-rate-limit");
/****create product**/
const limiter = rateLimit({
    windowMs: 15 * 60 * 1000, // 15 minutes
    limit: 100, // Limit each IP to 100 requests per `window` (here, per 15 minutes).
    keyGenerator: function (req, res) {
        return req.userId;
    }
});
UserRouter
    .post(createUser)
    .get(protectRouteMiddleWare, limiter, isAdminMiddleWare, getAllUser);
/*****get a product by it's ****/
UserRouter.route("/:id")
    .get(protectRouteMiddleWare, getUserById)
    .delete(protectRouteMiddleWare, deleteUserById)
    .patch(protectRouteMiddleWare, updateUserById);

module.exports = UserRouter;