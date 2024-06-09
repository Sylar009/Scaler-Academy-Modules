// //fs -> file system -> play with files 

const fs=require("fs");

//write a file 
//iut first create the file and then write the response 
fs.writeFileSync("f1.txt","I jave added this sentence from Nodejs");

// write the response 
fs.writeFileSync("f1.txt","I have added this sentence from Nodejs");
console.log("writing response");

//append the content 
fs.appendFileSync("f1.txt","\nNow i am appending a sentence");

//read the contents of a file 
let data=fs.readFileSync("f1.txt","utf-8");
console.log("content of file -> ",data);




// const str1="Hello";
// const str2=" World";

// //converting to buffer
// const myBuffer1=new Buffer(str1);
// const myBuffer2=new Buffer(str2);
// console.log(myBuffer1);
// console.log(myBuffer2);

// const concattedBuffer=Buffer.concat([myBuffer1,myBuffer2]);
// //convert buffer back to string 
// console.log(concattedBuffer.toString());

//to create a folder
// fs.mkdirSync("learningNodejs");


//asynchronous method

//callback method 
fs.writeFile("f2.txt","I am written using async cb method",function(err,data){
    if(err) console.log(err)
    else console.log("data written successfully");
})

console.log("before");
const filePromise=fs.promises.writeFile("f3.txt","I am written using async promise method");

filePromise.then(function(err,data){
    if(err) console.log(err)
    else console.log("data written successfully");
})
console.log("after");