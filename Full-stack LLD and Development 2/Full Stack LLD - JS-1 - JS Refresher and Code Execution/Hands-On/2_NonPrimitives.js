// function


// defintion
function fn(param1) {
    console.log("Hello world!", param1);
    return "Returned value";
}

console.log(fn(1));
// // fn call
let fn2 = fn();

console.log(typeof fn);

// object ->  collection of key:value pairs

// key -> number, string
//value -> any valid JS data type

// JS object -> represent an entity
let cap = {
    name: "Steve",
    'last Name': "Rogers",
    isAvenger: true,
    address: {
        city: "manhatten",
        state: "Newyork"
    },
    sayHi: function () {
        console.log("Cap say's HI");
    },
    movies: ["Avenger", "civile War"]
}


// //  JSON-> Javascript object Notation 
// // **********get******************
// // .operator
console.log("name is ", cap.name);


cap.sayHi();


var cap1 = {
    name: "Steve",
    age: 34,
    isAvenger: true,
    greet: "hello"
}


console.log("----------------------")
console.log(cap1.name);

// for in
for (let eachKey in cap1) {
    // EACHKEY is a variable
    console.log(eachKey, " ", cap1[eachKey]);
}

// name   
// age   
// isAvenger   
// key   


// .operator -> literal operator 
// cap.key























// [] -> search for the value of the variable inside it 