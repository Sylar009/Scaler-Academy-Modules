const nodemailer = require('nodemailer');
const dotenv = require("dotenv");
dotenv.config();

const { SENDGRID_KEY } = process.env;
console.log(SENDGRID_KEY);
// enter the details of the service that you want to use -> tech details -> transport service
// deatils about sendgrid
const transportDetails = {
    host: 'smtp.sendgrid.net',
    port: 587,
    auth: {
        user: "apikey",
        pass: SENDGRID_KEY
    }
}
// gmail 
// const gmailTransportDetails = {
//     host: 'smtp.gmail.com',
//     port: 465,
//     secure: true,
//     auth: {
//         user: "api_key",
//         pass: SENDGRID_KEY
//     }
// }
// details about the email
const emailDetails = {
    to: 'sanyam.lawania@gmail.com', 
    from: 'sanyamlawania@gmail.com', // Change to your verified sender
    subject: 'POC for sending email using sendgrid',
    text: 'Text content of the email will be printed if there is no parser at client level',
    html: '<strong>POC message with nodemailer</strong>',
}

const transporter = nodemailer.createTransport(transportDetails);

transporter.sendMail((emailDetails)).then(() => {
    console.log("email sent")
}).catch((err) => {
    console.log(err)

})