/******
 // [1,2,....100] -> 1st chunk -> send that chunk to res -> 1st chunk

 * [1,2,3,4,5,6......100]-> task  
 * * reading a file
 * * sending a response
 * * compression and decompression 
 * 
 * ## fs->
 *  * reading -> getting the data in chunks -> readStream
 *  *  writing -> set the data in chunks -> writeStream
 * 2. HTTP 
 *  * req -> recivieing data in chunks-> (stream)
 * * res -> recieving the data in chunks
 * 3. zlib 
 *  * compression -> chunks
 *  *  decompression -> chunks
 * 
 * Nodejs 
 *  * Event driven -> events
 *  * stream -> break things into chunks 
 * Streams
 *  * * readable:  form where you can read the data (fs.createReadStream) | req
 * * Writable: from where you can write the data (fs.writeStream) |  res
 * * Duplex: where you read and write also | sockets  
 * * Tranformative : that can change one from to another form | zlib and crypto   
 * 
 * *****/

 const fs = require("fs");
 const path = require("path");
 const streamSource = path.join(__dirname, "../", "problems", "big.file");
 const destPath = path.join(__dirname, "newFile.file");
 // read the files into chunk
 const readStream = fs.createReadStream(streamSource);
 
 
 const writeStream = fs.createWriteStream(destPath);
 
 console.log("starting to read the file");
 // connnected our both the ends
 readStream.pipe(writeStream);
 
 readStream.on("error", function (err) {
     console.log("err", err)
 })
 
 readStream.on("data",function(data){
     console.log("data"+data)
 })
 readStream.on("close", function () {
     console.log("file read");
 })