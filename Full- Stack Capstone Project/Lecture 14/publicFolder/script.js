console.log("I am working");
// then you connect with the server
const socket = io();

const sendBtn = document.querySelector(".send");
const messageInput = document.querySelector(".msg");
const messageContainer = document.querySelector(".messages");

const grpBtn = document.getElementById("createGrp");
const joinGrp = document.getElementById("joinGrp");
const stg = document.getElementById("stg");
// const leaveRoomBtn = document.getElementById("leave");

/***********group******/
grpBtn.addEventListener("click", function () {

    socket.emit("createGroup", Math.floor(Math.random(0, 1) * 1000))
})

joinGrp.addEventListener("click", function () {
    socket.emit("joingroup");
})
stg.addEventListener("click", function () {
    socket.emit("groupmessage", messageInput.value);
    messageInput.value = "";
})


// /broad cast message
sendBtn.addEventListener("click", () => {
    // add message to UI
    if (messageInput.value == "") return;
    const sender = document.createElement("div");
    sender.setAttribute("class", "sender");
    sender.innerHTML = "You:" + messageInput.value;
    // send the message to the server
    messageContainer.appendChild(sender);
    socket.emit("message", messageInput.value);
    messageInput.value = "";

});







/**************private messaging***************/
const recieverSocket = document.querySelector(".reciversocket");
const addSocketBtn = document.querySelector(".addsocket");

addSocketBtn.addEventListener("click", () => {
    if (messageInput.value == "") return;
    if (recieverSocket.value == "") return;
    socket.emit("private", {
        message: messageInput.value,
        recieverSocket: recieverSocket.value
    });
    messageInput.value = "";
    recieverSocket.value = "";
});


/*******socket listeneers****/

socket.on("personal", function (data) {
    const reciever = document.createElement("div");
    reciever.setAttribute("class", "reciever");
    reciever.innerHTML = "sender:" + data;
    messageContainer.appendChild(reciever);
})

socket.on("broadCastMessage", function (data) {
    const reciever = document.createElement("div");
    reciever.setAttribute("class", "reciever");
    reciever.innerHTML = "sender:" + data;
    messageContainer.appendChild(reciever);
})
socket.on("serv_grp_message", function (data) {
    const reciever = document.createElement("div");
    reciever.setAttribute("class", "reciever");
    reciever.innerHTML = "sender:" + data;
    messageContainer.appendChild(reciever);
})


socket.on("message", (data) => {
    console.log(`message from server : ${data}`)
});