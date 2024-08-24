const express = require("express");
const {
    signupController, loginController, forgetPasswordController, resetPasswordController
} = require("../controller/AuthController");

const AuthRouter = express.Router();
AuthRouter.post("/signup",
    signupController);
AuthRouter.post("/login",
    loginController);
AuthRouter.patch("/forgetPassword", forgetPasswordController);
AuthRouter.patch("/resetPassword/:id", resetPasswordController);
module.exports = AuthRouter;