const EmailHelper = require("../utils/emailSender");
const UserModel = require("../model/UserModel");
const { JWT_SECRET } = process.env;
const jwt = require("jsonwebtoken");
const promisify = require("util").promisify;

const promisifiedJWTSign = promisify(jwt.sign);
const promisifiedJWTVerify = promisify(jwt.verify);

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
            EmailHelper(
                "welcome.html"
                ,
                newUser.email,
                {
                    name: newUser.name
                });

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

const forgetPasswordController = async function (req, res) {
    try {
        /****
         * 1. You can ask for email
         * 2. check if email is present or not
         *  * if email is not present -> send a response to the user(user not found)
         * 3. if email is present -> create basic otp -> and send to the email 
         * 4. also store that otp
         * 5. to avoid that collison
         *      responase -> unique url with id of the user and that will form your reset password 
         * 
         * ***/
        if (req.body.email) {
            // get the user
            const user = await UserModel.findOne({ email: req.body.email });
            if (user) {
                // otp creation
                const otp = otpCreator();
                user.otp = otp;
                user.otpExpiry = new Date(Date.now() + 1000 * 60 * 10);
                // save the otp and expiry in db as well
                await user.save();
                // send the mail to there email -> otp
                res.status(200).json({
                    status: "success",
                    message: "otp sent to your email",
                    reseturl: `http://localhost:3000/resetPassword/${user["_id"]}`,
                    otp: otp
                });

                await EmailHelper(
                    "otp.html"
                    , user.email,
                    {
                        name: user.name,
                        otp: otp
                    });
            } else {
                res.status(404).json({
                    status: "failure",
                    message: "user not found for this email"
                })
            }

        } else {
            res.status(401).json({
                status: "failure",
                message: "Please enter the email for forget Password"
            })
        }
    } catch (err) {
        res.status(500).json({
            message: err.message,
            status: "failure"
        })
    }
}
const resetPasswordController = async function (req, res, next) {
    try {
        /****
         * 1. get the user via id -> uique user
         * 2. check if otp is expired or not 
         *  3. if expired -> send a response to the user(otp expired) try again
         * 4. if not expired -> check if otp is correct or not
         * 5. update the passwords
         * 
         * ***/
        let resetDetails = req.body;
        // checking for all the inputs
        if (!resetDetails.password == true || !resetDetails.otp == true || !resetDetails.confirmPassword == true) {
            return res.status(401).json({
                status: "failure",
                message: "invalid request"
            })
        }
        // to avoid the collision
        const user = await UserModel.findById(req.params.id);

        if (user) {
            if (user.otp == resetDetails.otp) {
                let currentTime = new Date();
                if (currentTime < user.otpExpiry) {
                    // express level
                    user.password = resetDetails.password;
                    user.confirmPassword = resetDetails.confirmPassword;
                    // remove the otp from the user
                    user.otp = undefined;
                    user.otpExpiry = undefined;
                    // you sending the update user to the db 
                    await user.save();
                    res.status(200).json({
                        status: "success",
                        message: "password reset successfully"
                    })
                } else {
                    res.status(401).json({
                        status: "failure",
                        message: "otp expired"
                    })
                }
            } else {
                res.status(401).json({
                    status: "failure",
                    message: "invalid otp"
                })
            }

        } else {
            res.status(401).json({
                status: "failure",
                message: "invalid request"
            })
        }
    } catch (err) {
        res.status(500).json({
            message: err.message,
            status: "failure"
        })

    }
}

function otpCreator() {
    const otp = Math.floor(100000 + Math.random() * 900000);
    return otp.toString();
}
/************************middleware*********/
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
        console.log(err);
        res.status(500).json({
            message: err.message,
            status: "failure"
        })
    }
}
const isAdminMiddleWare = async function (req, res, next) {
    try {
        const id = req.userId;

        const user = await UserModel.findById(id);
        if (user.role == "admin") {
            next();
        } else {
            res.status(401).json({
                message: "you are not authorized",
                status: "failure"
            })
        }
    } catch (err) {
        res.status(500).json({
            message: err.message,
            status: "failure"
        })
    }
}
// generic middleWare
module.exports = {
    signupController,
    loginController,
    forgetPasswordController,
    resetPasswordController,
    protectRouteMiddleWare,
    isAdminMiddleWare
}