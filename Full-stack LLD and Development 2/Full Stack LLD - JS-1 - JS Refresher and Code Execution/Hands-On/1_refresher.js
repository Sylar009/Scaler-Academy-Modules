console.log("hello!!!!!");

// JS statistically/dynamically ?


// JS is a dynamic typed language and type is defined during runtime.
var a = 5;
a = 4;

// statistical language
//int x = 5;
// string


// JS in browser and outside browser






// Fact-1 default of JS -> always -> undefined

var xyz;
console.log(xyz,"xyz");

var myVar;
console.log("value of ", myVar);


// primitive
// non-primitive







// Datatypes in JS

// immutable
// Primitive types -> number, boolean, string, undefined, null
// number => -2^53 - 1 to 2^53 - 1
// New Types -> BigInt,Symbol

// mutable
// Non-primitve types  ->  object, functions and arrays
// homework
// New Types -> map ,set, weakmap and weakset


// pass by value and also immutable.
var a = 5; // number
var b = a;
a = a + 1;
console.log("a is " + a + " and b is " + b);

var a = 6.5454;
var b;
console.log(a + b); // NaN





// ********** number -> similar to mathematical  ->
// console.log(5 / 2);


//  *********strings ********

// Strings in javascript follow 0-based indexing, 
// i.e., the first element of the string is considered at the 0th position, 
// the second in the 1st position, and so on.

let age = 28;
// no difference between single quotes and double quotes
var a = "Hello World";
let str1 = 'I am ' + age + " years old." + a; // concatenation.
console.log(str1);

var a1 = 'Hello World';
a = a.toUpperCase();
console.log(a);
// Problem : JS '' and "" doen't support multiple line strings;


var houses = 3;

let templateString = `I am 
1-  ${age} years old
2- and healthy. I have ${houses}`;
console.log(templateString);


//****************null************//
// null is - absense of a definition

var a = null; // user defined talking about absense of a value.

// undefined -> empty -> undefined -> default js

var a;

// null -> empty value -> user defined

// boolean

var a1 = true; // 1
var a1 = false; // 0


// === and ==


// ***********typeof Operator***********************

var a = 10;
console.log("55", typeof a);
a = "string";
console.log("57", typeof a);
a = true;
console.log("59", typeof a);

a = { "name" : "Jasbir" };
console.log("59", typeof a);

console.log(typeof typeof a);




var a1 = { age : 46 }
var b1 = a1;
b1.age = 48;
console.log(a1, b1, "objects");



// Fact-2 : JS -> just 10days -> netscape

//  it is a bug 
console.log(typeof null , "null type");

// typeof array -> object
console.log(typeof [1, 2, 3, 4]);


// object are key-value pairs.
var person = {
    name : 'vishal',
    age: 28
}

// person.age
// person.name

// stored as key-value pairs starting from 0th indexing and 
// array is contigously written. thus next address is known.

var arr1 = [1,2,3,4];

arr1[0];
arr1[1];




// correct way to check whether you are recieving array or object
var arr = [1, 2, 3, 4];
console.log(Array.isArray(arr));