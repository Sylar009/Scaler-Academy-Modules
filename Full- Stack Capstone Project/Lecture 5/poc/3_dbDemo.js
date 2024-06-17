const express = require("express");
const dotenv = require("dotenv");
const path = require("path");
const mongoose = require("mongoose");
// it adds all the enviornment variables to processe.env
dotenv.config({ path: path.join(__dirname, "../", ".env") });
/**********************connect with your DB***********************/
const { DB_USER, DB_PASSWORD, LOCAL_PORT } = process.env;
// connection with the DB
const dbURL =
    `mongodb+srv://${DB_USER}:${DB_PASSWORD}@cluster0.drcvhxp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;
mongoose.connect(dbURL)
    .then(function (connection) {
        // console.log(connection);
        console.log("connected to DB")
    }).catch(err => { console.log(err) });
/***************models****************/
const ProductModel = require("./ProductModel");
const UserModel = require("./UserModel");
const { createResourceFactory, getAllResourceFactory, getResourceByIdFactory, deleteResourceByIdFactory, updateResourceByIdFactory } = require("./utils");

// create a server
const app = express();
// any request has something in it's body -> add it to req.body
app.use(express.json());

// handler method

const createProduct = createResourceFactory(ProductModel);
const getAllProducts = getAllResourceFactory(ProductModel);
const getproductById = getResourceByIdFactory(ProductModel);
const deleteProductById = deleteResourceByIdFactory(ProductModel);
const updateProductById = updateResourceByIdFactory(ProductModel);
/****user***/
/*****handler*/
// hanlder method
const createUser = createResourceFactory(UserModel);
const getAllUser = getAllResourceFactory(UserModel);
const updateUserById = updateResourceByIdFactory(UserModel);
const getUserById = getResourceByIdFactory(UserModel);
const deleteUserById = deleteResourceByIdFactory(UserModel);

//api/v1/product/:id  , PATCH
// const appRouter = express.Router();
const productRouter = express.Router();
const userRouter = express.Router();
/****post request -> /api/v1/product**/

// app.use("/api/v1", appRouter);

/****post request -> /product**/
app.use("/api/v1/product", productRouter);
app.use("/api/v1/user", userRouter);
/*************product*********/
/****create product**/
productRouter.route("/")
    .post(createProduct)
    .get(getAllProducts);
/*****get a product by it's ****/
productRouter.route("/:id")
    .get(getproductById)
    .delete(deleteProductById)
    .patch(updateProductById);

/*****create user***/
userRouter
.route("/")
.post(createUser)
    .get(getAllUser);
userRouter.route("/:id")
    .get(getUserById)
    .delete(deleteUserById)
    .patch(updateUserById);

/*********************************/
const PORT = process.env.PORT || LOCAL_PORT;
app.listen(PORT, function () {
    console.log("server is running at port " + LOCAL_PORT);
})

/**
 * 1. users
 * 2. products
 * 3. orders,
 * 4. reviews
 * **/ 