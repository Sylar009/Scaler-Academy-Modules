
import './App.css'
function loadScript() {
  return new Promise((resolve) => {
    const script = document.createElement('script');
    script.src = 'https://checkout.razorpay.com/v1/checkout.js';
    // we have a event called -> library is fetched by the client 
    script.onload = () => {
      resolve(true)
    }
    script.onerror = () => {
      resolve(false)
    }
    document.body.appendChild(script);
  })

}
const openRazorpayCheckout = async () => {
  // script should be loaded 
  await loadScript();

  // create the order -> make the request to backend
  const resp = await fetch('http://localhost:3000/checkout', { method: 'POST' });
  const data = await resp.json();
  const { currency, id, amount }=data.message;
  const options = {
    "key": "rzp_test_nYjU13F9fkg7cF", // Enter the public key generated from the Dashboard
    "amount": amount, // Amount is in currency subunits. Default currency is INR. Hence, 50000 refers to 50000 paise
    "currency": currency,
    "name": "sample product",
    "order_id": id, //This is a sample Order ID. Pass the `id` obtained in the response of Step 1
    "handler": function (response) {
      alert(response.razorpay_payment_id);
      alert(response.razorpay_order_id);
      alert(response.razorpay_signature)
    },
    "prefill": {
      "name": "sanyam lawania",
      "email": "sanyamlawania@gmail.com",
      "contact": "846579213"
    },
    "notes": {
      "address": "Razorpay Corporate Office"
    },

  };
  // open the razorpay payment page
  const rzp1 = new Razorpay(options);
  rzp1.open();
  rzp1.on('payment.failed', function (response) {
    alert(response.error.code);
    alert(response.error.description);
    alert(response.error.source);
    alert(response.error.step);
    alert(response.error.reason);
    alert(response.error.metadata.order_id);
    alert(response.error.metadata.payment_id);
  });
}
function App() {

  return (
    <>
      <h1>Payment Demo</h1>
      <a onClick={openRazorpayCheckout}> Pay for 500</a>


    </>
  )
}

export default App