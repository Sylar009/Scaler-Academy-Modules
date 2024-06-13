const express = require("express");

// create a server
const app = express();

/****pre-defined/third party middleware**/
app.use(express.json());
/*******user defined middleWares**/
// use will always execute for every method
app.use((req, res, next) => {
    console.log("first use middleWare");

    console.log("in first middleware", req.body);
    next();
})
app.post('/', function (req, res, next) {
    console.log("i am a post route")
    console.log("in the post ", req.body);
    next();
})
app.use((req, res) => {
    console.log("second use");
    console.log("in third middleware", req.body);
    res.json({
        message: "Thanks for the request"
    })
})
app.get('/', function (req, res) {
    console.log("i am a get route")
    res.json({
        message: "Thanks for the get request"
    })
})

/**
 * 0. when you res.json the data -> it is send to  postman/client and when you console it is printed on the server
 *   1. app.use it ->will work for every request method , GET POST PATCH -> will work for there resepctive middleware
 * 
 *  2. All the  handler are nothing but a middleware that always work in serial order
 * 
 *  3. if any of the middleware returns the reponse the the further middleware will not be excuted
 **/
const PORT = process.env.PORT || 3000;
app.listen(PORT, function () {
    console.log("server is running at port 3000");
})