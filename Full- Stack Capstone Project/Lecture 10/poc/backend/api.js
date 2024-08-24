const express = require('express');
const dotenv = require('dotenv');
const Razorpay = require('razorpay');
const crypto = require("crypto");
const ShortUniqueId = require('short-unique-id');
const uid = new ShortUniqueId({ length: 10 });
dotenv.config({ path: '../../.env' });
const app = express();
const cors = require('cors');
app.use(express.json());
app.use(cors());
// on server to start the razorpay integartaion -> instatntiate 
const razorpayInstance = new Razorpay({
    key_id: process.env.RAZORPAY_PUBLIC_KEY,
    key_secret: process.env.RAZORPAY_PRIVATE_KEY,
});

app.get("/", (req, res) => {
    res.send("Hello World");
});

// bookings route
app.post("/checkout", async (req, res) => {
    try {
        const amount = 500;
        const currency = 'INR';
        const receiept = `rec_${uid.rnd()}`;
        const payment_capture = 1;
        const options = {
            amount: amount * 100,
            currency: currency,
            receipt: receiept,
            payment_capture: payment_capture
        };
        // order creation 
        const orderObject = await
            razorpayInstance.orders.create(options);

        res.status(200).json({
            status: 'success',
            message: orderObject
        });
    } catch (err) {
        res.
            status(500)
            .json({ message: err.message });
    }
})
// you haven't verified the payment
app.post("/verify", async (req, res) => {
    try {
        // on  payment gateway-> req.body + webhook -> hash
        const razorPaySign = req.headers["x-razorpay-signature"];

        // this object -> sha256+webhook_secret
        const shasum = crypto.createHmac("sha256", process.env.WEBHOOK_SECRET);
        // whatevere data is send by you razorpay
        shasum.update(JSON.stringify(req.body));
        const freshSignature = shasum.digest("hex");
        console.log("evrefied payment");
        if (freshSignature === razorPaySign) {
            console.log("Payment is verified");
            console.log(req.body)
            const orderId = req.body.payload.payment.entity.order_id;

            res.status(200).json({ message: "OK" });
        } else {
            // there some tempering 
            res.status(403).json({ message: "Invalid" });
        }


    } catch (err) {
        res.status(500).json({ message: err.message });

    }
})
const port = 3000;
app.listen(port, () => {
    console.log(`Server is running on port ${port}`);
});