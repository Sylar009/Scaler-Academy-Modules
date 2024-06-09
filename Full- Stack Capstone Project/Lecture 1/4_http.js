const { log } = require("console");
const http=require("http");
const fs=require("fs");
const server=http.createServer();
//user db
const userData=[{name:"Abhishek",age:35},{name:"Kunal",age:23},{name:"Sree",age:12}];
server.on("request",function(req,res){
    console.log("request has been made");
    console.log(req.url);
    console.log(req.method);
    let path="./views"
    //send data from server 
    if(req.url=="/user"){
        if(req.method=="GET"){
            console.log("send all user details");
            res.end(JSON.stringify(userData));
        }else if(req.method=="DELETE"){
            console.log("a user is deleting it's profile");
            res.end("profile deleted");
        }
    }
    // else if(req.url=="/profile"){
    //     if(req.method=="GET"){
    //         console.log("send all user details");
    //         res.end(JSON.stringify(userData));
    //     }else if(req.method=="DELETE"){
    //         console.log("a user is deleting it's profile");
    //         res.end("profile deleted");
    //     }
    // }
    //Send ui from server 
    else if(req.url=="/"){
        path+="/index.html";
        fs.readFile(path,(err,data)=>{
            if(err) console.log(err);
            else{
                //server is sending this file to client(postman)
                res.statusCode=200;
                res.write(data);
                //this is used to end the req res cycle 
                res.end();
            }
        })
    }
    else{
        path+="/404.html";
        fs.readFile(path,(err,data)=>{
            if(err) console.log(err);
            else{
                //server is sending this file to client(postman)
                res.statusCode=404;
                res.write(data);
                //this is used to end the req res cycle 
                res.end();
            }
        })
    }
    // res.end("Thanks for sending the request")
})

server.listen(3000,function(){
    console.log("started listening on port number 3000");
});