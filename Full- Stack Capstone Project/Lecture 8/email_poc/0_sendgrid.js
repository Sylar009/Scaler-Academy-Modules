// package 
const sgMail = require('@sendgrid/mail');
const dotenv = require('dotenv');
dotenv.config();
// set your API key

sgMail.setApiKey(process.env.SENDGRID_KEY);

// create email object
const msg = {
    to: 'sanyam.lawania@gmail.com', 
    from: 'sanyamlawania@gmail.com', // Change to your verified sender
    subject: 'POC for sending email using sendgrid',
    text: 'Text content of the email will be printed if there is no parser at client level',
    html: '<strong>POC message</strong>',
}
// send email
sgMail
    .send(msg)
    .then(() => {
        console.log('Email sent')
    })
    .catch((error) => {
        console.error(error)
    })