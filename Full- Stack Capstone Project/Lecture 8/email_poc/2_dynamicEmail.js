
const nodemailer = require('nodemailer');
const fs = require("fs");
const dotenv = require("dotenv");
dotenv.config();

const { SENDGRID_KEY } = process.env;
console.log(SENDGRID_KEY);

let content = fs.readFileSync("otp.html", "utf-8");
function replaceContent(username, otp) {
    content = content.replace("#{USER_NAME}", username);
    content = content.replace("#{OTP}", otp);
    return content;
}


/******************code for sending******************/
// enter the details of the service that you want to use -> tech details -> transport service
// deatils about sendgrid

const emailDetails = {
    to: 'sanyam.lawania@gmail.com', 
    from: 'sanyamlawania@gmail.com', // Change to your verified sender
    subject: 'OTP for forget password',
    text: `your otp for reset is 1234`,
    html: replaceContent("Sanyam", "1234"),
}

const transportDetails = {
    host: 'smtp.sendgrid.net',
    port: 587,
    auth: {
        user: "apikey",
        pass: SENDGRID_KEY
    }
}
const transporter = nodemailer.createTransport(transportDetails);

transporter.sendMail((emailDetails)).then(() => {
    console.log("email sent")
}).catch((err) => {
    console.log(err)

})
