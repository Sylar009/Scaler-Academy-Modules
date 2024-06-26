const express = require("express");
const app = express();
const cookieParser = require("cookie-parser");
/**
 * payload -> req.body (express.json)
 * cookie -> req.cookies (cookie-parser)
 *
 * **/
// home
// products
// clearCookie
app.use(cookieParser());

app.get("/", function (req, res) {
  // header
  res.cookie("prevUrl", "home", {
    // expiry
    maxAge: 1000 * 60 * 60 * 24,
    // so that client level scripts can't access my cookies
    httpOnly: true,
  });
  res.status(200).json({
    message: "thank you for visiting home page",
  });
});

/**** i will use the feature cookies to track my user****/
app.get("/product", function (req, res) {
  console.log("cookies", req.cookies);
  let msgStr = "";
  if (req.cookies.prevUrl) {
    msgStr += "you have already visited " + req.cookies.prevUrl + " page";
  }
  res.status(200).json({
    message: "thank you for visiting product page " + msgStr,
  });
});

/********clear the cookie before expiry****/
app.get("/clearCookies", function (req, res) {
  res.clearCookie("prevUrl", { path: "/" });
  res.status(200).json({
    message: "cookie cleared successfully",
  });
});

app.listen(3000, function () {
  console.log(` server is listening to port 3000`);
});
