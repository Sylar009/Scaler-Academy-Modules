// this module is used to create events 
const EventEmitter = require("events");
// how to create a custom event

// event Emitter instance
const myEmitter = new EventEmitter();


function greetHandler(name) {
    console.log("Hello how are you?", name);

}
// declaration -> listening
myEmitter.on("greet", greetHandler);

// invocation/emittion
myEmitter.emit("greet");
myEmitter.off("greet",greetHandler);
myEmitter.emit("greet", "Jasbir");
console.log("I also works");