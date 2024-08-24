const express = require('express');

const http = require('http');
const socketTemplate = require('socket.io').Server;
const app = express();
// in publicFolder we will keep all the static files
app.use(express.static('publicFolder'));
// http server -> 
const nodeServer = http.createServer(app);
// socket server
const socketServer = new socketTemplate(nodeServer);

let room;
socketServer.on('connection', (socket) => {
    // whenever a new connection is made -> it will console it 
    console.log('New Connection', socket.id);
    // message is sedn to the client
    // setInterval(() => {
    //     socket.emit("message", `message from server ${socket.id}`);
    // }, 1000);
    socket.on("disconnect", () => {
        console.log('disconnected ', socket.id);
    })
    socket.on("message", (data) => {
        console.log(`message from client : ${data}`);
        // broadcast the message to all the clients -> except the sender
        socket
            .broadcast
            .emit("broadCastMessage", data);
    })
    socket.on("private", ({ message, recieverSocket }) => {
        console.log("message", message);
        socket.broadcast
            // send a private message
            .to(recieverSocket)
            .emit("personal", message)
    })
    socket.on("createGroup", function (groupId) {
        room = groupId;
        socket.join(room);
    })
    socket.on("joingroup", function () {
        console.log("You are added to group");
        socket.join(room)
    })
    socket.on("groupmessage", function (message) {
        socket.to(room).emit("serv_grp_message", message)
    })
});

// responds to http requests
app.get("/", (req, res) => {
    res.send("<h1>Socket Server</h1>");
})
// listen through node server
nodeServer.listen(3000, () => {
    console.log('Server is running on http://localhost:3000');

})


/***
 * 1. client
 *  "emit" -> to send data to server
 *  "on" -> to receive the data  from the server
 * 2. emit and on are there(server)
 *  * "on" -> to get data fro client
 *  * "emit" to send the events -> data will be send  -> 
 *      * broadcast
 *      * Private message
 *      * group message 
 * 
 * 
 * 
 * **/ 