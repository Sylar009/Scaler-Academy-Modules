const UserModel = require("../model/UserModel");
/****user***/
/*****hadler*/
// hanlder method
async function createUser(req, res) {
    try {
        const userDetails = req.body;
        // adding thr product to mongodb
        const user = await
            UserModel.create(userDetails);
        res.status(201).json({
            status: "successfull",
            message: `added  the product `,
            product: user
        })

    } catch (err) {
        res.status(502).json({
            status: "failure",
            message: err.message
        })
    }
}
async function getAllUser(req, res) {
    try {
        // -> if you don't pass anything -> return you the whole collection
        // -> if want to filter -> parameter -> an object
        const listOfUser = await UserModel.find();
        res.status(200).json({
            status: "successfull",
            message: `list of the user `,
            UserList: listOfUser
        })
    } catch (err) {
        res.status(404).json({
            status: "failure",
            message: err.message
        })
    }
}