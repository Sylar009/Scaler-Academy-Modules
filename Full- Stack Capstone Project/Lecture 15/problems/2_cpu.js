// /****
//  * usually there are few cpu intensive tasks 
//  *  * image processing
//  *  * video processing
//  *  *  encryption and descryption 
//  * ***/

// /***
//  * dos service attack -> make the request of big numbers
//  * **/



// const express = require('express');
// const app = express();
// const cors = require("cors");
// app.use(cors());

// // fib calculator
// function calculateFibonacci(number) {
//     if (number <= 1) {
//         return number;
//     }
//     return calculateFibonacci(number - 1) + calculateFibonacci(number - 2);
// }

// app.get('/fib', (req, res) => {
//     const { number, time } = req.query;
//     console.log("received req", time, Date.now());
//     if (!number || isNaN(number) || number <= 0) {
//         return res.status(400).json({ error: 'Please provide a valid positive number.' });
//     }
//     const answer = calculateFibonacci(number);
//     console.log(answer);
//     res.status(200).json({
//         status: "success",
//         message: answer
//     })
// });

// app.listen(3000, function () {
//     console.log("server is running at port 3000");
// })
console.log(process);