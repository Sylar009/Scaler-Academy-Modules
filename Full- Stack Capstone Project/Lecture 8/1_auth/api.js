
const express = require("express");

const dotenv = require("dotenv");
const mongoose = require("mongoose");

// including env variables
dotenv.config();
const { JWT_SECRET } = process.env;



const cookieParser = require("cookie-parser");
const jwt = require("jsonwebtoken");
const promisify = require("util").promisify;

const promisifiedJWTSign = promisify(jwt.sign);
const promisifiedJWTVerify = promisify(jwt.verify);


/**********************connection to our DB********************************/

const { MONGO_URI, LOCAL_PORT } = process.env;
// connection with the DB
const dbURL = MONGO_URI;
    // `mongodb+srv://${DB_USER}:${DB_PASSWORD}@cluster0.drcvhxp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;
    
mongoose.connect(dbURL)
    .then(function (connection) {
        // console.log(connection);
        console.log("connected to DB")
    }).catch(err => { console.log(err) });
const UserModel = require("./model/UserModel");
const welcomeEmailHelper = require("./emailSender");

/*************************************************/
const app = express();
/***to get the data in req.body **/
app.use(express.json());
/*******to get the cookie in req.cookies**/
app.use(cookieParser());

const signupController = async function (req, res) {
    try {
        // 1. get the data from the client -> req.body
        const userObject = req.body;
        // 2. create the user in the DB
        let newUser = await UserModel.create(userObject);
        // 3. send the response to the client
        res.status(201).json({
            "message": "user created successfully",
            user: newUser,
            status: "success"
        })

        await 
        welcomeEmailHelper(newUser.email, 
            newUser.name);

    } catch (err) {
        console.log(err);
        res.status(500).json({
            message: err.message,
            status: "success"
        })
    }
}
const loginController = async function (req, res) {
    try {
        let userDetails = req.body;
        const email = userDetails.email;
        const password = userDetails.password;
        if (email == undefined || password == undefined) {
            return res.status(401).json({
                status: "failure",
                message: "pleae enter email to login"
            })
        }

        if (email) {
            // it get's you the first matched entry
            const user = await UserModel.findOne({ email: email });
            if (user) {
                // if user is found with that email
                if (password == user.password) {
                    //  for that user ->create the token
                    const authToken = await promisifiedJWTSign({ id: user._id }, JWT_SECRET);
                    // put that token in the cookie
                    res.cookie("jwt", authToken, { httpOnly: true, maxAge: 1000 * 60 * 60 * 24 });
                    res.status(200).json({
                        message: "user logged in successfully",
                        authToken: authToken,
                    })

                } else {
                    // if password does not match
                    res.status(401).json({
                        status: "failure",
                        message: "email or password is incorrect"
                    })
                }
            } else {
                // if email does not match for any user
                res.status(401).json({
                    status: "failure",
                    message: "email or password is incorrect"
                })
            }
        }
        /****
         * 1. check if email is present or not
         *  2. -> if not present -> send a response to the user(email or password is incorrect)
         *  3. -> if present -> check password 
         *  4a-> if password is incorrect -> send a response to the user(email or password is incorrect)
         * 4. -> if password is correct -> create a token and send it to the user(jwt.sign)
         * 5. put that token in the cookie
         * 6. send the response to the client
         * ***/

    } catch (err) {
        console.error(err);
        res.status(500).json({
            status: "failure",
            message: err.message
        })
    }
}

const protectRouteMiddleWare = async function (req, res, next) {
    try {
        // check for the cookie -> jwt or not
        // if not present -> send a response to the user(you need to be logged in)
        // if present -> verify the token(jwt.verify)
        // if token is not valid -> invalid token(login again)
        // if token is value  -> next()
        const token = req.cookies.jwt;
        if (token == undefined) {
            return res.status(401).json({
                status: "failure",
                message: "you need to be logged in"
            })
        } else {
            const payload = await promisifiedJWTVerify(token, JWT_SECRET);
            const id = payload.id;
            req.userId = id;
            next();
        }
    } catch (err) {
        res.status(500).json({
            message: err.message,
            status: "failure"
        })
    }
}

const getUserData = async function (req, res) {
    try {
        const id = req.userId;
        const user = await UserModel.findById(id);
        res.status(200).json({
            "message": "user data retrieved  successfully",
            user: user
        })
    } catch (err) {
        res.status(200).json({
            message: err.message
        })
    }
}
/************routes***************/
// signup -> create a user
app.post("/signup", signupController);

app.post("/login", loginController);
app.get("/allowIfLoggedIn", protectRouteMiddleWare, getUserData);


/******************handler functions ***************/
// 404 route not found
app.use(function cb(req, res) {
    // console.log("");
    // response 
    res.status(404).json({
        status: "failure",
        message: " route not found"
    })
})
// server -> run on a port 
app.listen(LOCAL_PORT, function () {
    console.log(` server is listening to port ${LOCAL_PORT}`);
})

/***
 * 1. payload -> normal data
 * 2. secret -> secret key
 * 3. algorithm -> HS256(optional)
 * 
 * **/ 