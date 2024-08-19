const nodemailer = require('nodemailer');
const fs = require("fs");
const dotenv = require("dotenv");
dotenv.config();

const { SENDGRID_KEY } = process.env;

function replaceContent(content, name) {
    content = content.replace("#{user}", name);
    return content;
}
async function welcomeEmailHelper
(reciverEmail, name) {
    try {
        
        let content = await fs.promises.readFile("welcome.html", "utf-8");
        const emailDetails = {
            to: reciverEmail,
            from: 'sanyam.lawania@gmail.com', // Change to your verified sender
            subject: 'Welcome to our platform',
            text: `welcome to our platform ${name}`,
            html: replaceContent(content, name),
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
       await  transporter.sendMail((emailDetails))
        console.log("email sent")
    } catch (err) {
        console.log(err)
    }

}

module.exports = welcomeEmailHelper;