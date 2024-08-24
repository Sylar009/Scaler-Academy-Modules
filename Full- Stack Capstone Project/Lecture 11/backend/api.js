const express = require("express");
const dotenv = require("dotenv");
const mongoose = require("mongoose");
const cookieParser = require("cookie-parser");
const helmet = require("helmet");
// it adds all the enviornment variables to processe.env
dotenv.config();
const { DB_USER, DB_PASSWORD, LOCAL_PORT } = process.env;
// connection with the DB
const dbURL =
    `mongodb+srv://${DB_USER}:${DB_PASSWORD}@cluster0.drcvhxp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;
mongoose.connect(dbURL)
    .then(function (connection) {
        // console.log(connection);
        console.log("connected to DB")
    }).catch(err => { console.log(err) });
//********************** */ 


// create a server
const app = express();
// any request has something in it's body -> add it to req.body
app.use(helmet());
app.use(express.json());
app.use(cookieParser());
const appRouter = express.Router();
app.use("/api/v1", appRouter);

/****post request -> /product**/
const ProductRouter = require("./router/ProductRouter");
appRouter.use("/product", ProductRouter);

const UserRouter = require("./router/UserRouter");
appRouter.use("/user", UserRouter);

const AuthRouter = require("./router/AuthRouter");
appRouter.use("/auth", AuthRouter);
const BookingRouter = require("./router/BookingRouter");
const { protectRouteMiddleWare } = require("./controller/AuthController");
const ReviewModel = require("./model/ReviewModel");
const ProductModel = require("./model/ProductModel");

appRouter.use("/booking", BookingRouter);

appRouter.post("/review", protectRouteMiddleWare, async function createReview(req, res) {

    //    chekc for login
    // check whether the user has bought that product or not -> if true
    try {
        const { rating,
            review_title,
            review_desc,
            product_id } = req.body;

        const userId = req.userId;
        //form the object to work with schema
        let reviewObj = {
            rating,
            review_title,
            review_desc,
            product: product_id,
            user: userId
        }
        // add the review
        // update the average ratings
        const review = await ReviewModel.create(reviewObj);
        // find the product
        const product = await ProductModel.findById(product_id);
        // add reviews to it
        product.reviews.push(review["_id"]);
        await product.save();

        res.status(200).json({
            status: "success",
            review
        })

    } catch (err) {
        console.log(err);
        res.status(500).json({
            message: "server error",
            err: err.message
        })
    }
})
// appRouter.get("/review/:productId",getAllReviewsOfAPRoduct);
// appRouter.get("/review/",getAllReviews);





/************routes***************/
// signup -> create a user


/***
 * should only be allowed to be accessed by admin
 * 
 * **/

/*************product*********/
/*********************************/
const PORT = process.env.PORT || LOCAL_PORT;
app.listen(PORT, function () {
    console.log("server is running at port 3000");
})