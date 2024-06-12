const express = require("express");
const fs = require("fs");
const short = require("short-uuid");
// create a servr
const app = express();
// get -> home -> reply
// app.get("/", function (req, res) {
//     console.log("Hello got the request")
//     res.status(200).json({
//         result: "ok",
//         data: "recieved the request"
//     })
// })
// reading the content
const strContent = fs.readFileSync("./dev-data.json", "utf-8");
const userDataStore = JSON.parse(strContent);

//-> you want to execute this function on every request

// it simply add the data send to the api to req.body property
app.use(express.json());
// check for post
app.use(function (req, res, next) {
  // post then checl
  if (req.method == "POST") {
    // check if the body is empty or not
    const userDetails = req.body;
    const isEmpty = Object.keys(userDetails).length == 0;
    if (isEmpty) {
      res.status(400).json({
        status: "failure",
        message: "userDetails are empty",
      });
    } else {
      next();
    }
  } else {
    // send to next guy
    next();
  }
});
/****************get all the users*************/
app.get("/api/user", function (req, res) {
  try {
    console.log("got the request for getting all users");
    if (userDataStore.length == 0) {
      throw new Error("No users are present");
    }
    // final result from the server
    res.status(200).json({
      status: "success",
      message: userDataStore,
    });
  } catch (err) {
    res.status(404).json({
      status: "failure",
      message: err.message,
    });
  }
});
/****************create the user*********************/
app.post("/api/user", function (req, res) {
  try {
    // adding the id
    const userDetails = req.body;
    const id = short.generate();
    userDetails.id = id;
    // adding it to the whole list
    userDataStore.push(userDetails);
    // adding user to the file
    const struserStore = JSON.stringify(userDataStore);
    fs.writeFileSync("./dev-data.json", struserStore);
    res.status(200).json({
      status: "successfull",
      message: `update the user with ${id}`,
    });
  } catch (err) {
    res.status(502).json({
      status: "failure",
      message: err.message,
    });
  }
});
app.get("/myroute", function (req, res) {
  res.status(200).json({
    message: "returning the resp",
  });
});
/*********getUserById******/
// template route
app.get("/api/user/:id/", function (req, res) {
  try {
    const id = req.params.id;
    const userDetails = getUserId(id);
    if (userDetails == "no user found") {
      throw new Error(`user with ${id} not found`);
    } else {
      res.status(200).json({
        status: "successfull",
        message: userDetails,
      });
    }
  } catch (err) {
    res.status(404).json({
      status: "failure",
      message: err.message,
    });
  }
});

/***
 * 404 route not
 * */

app.use(function cb(req, res) {
  // console.log("");
  // response
  res.status(404).json({
    status: "failure",
    message: " route not found",
  });
});

function getUserId(id) {
  const user = userDataStore.find((userObj) => {
    return userObj.id == id;
  });
  return user;
}
/***
 * 1. getalltheUser -> return the whole data array  [get] -> done
 * 2. add a user -> send the data point [post]
 * on the server level we want to give the
 * unique id
 * 3. get a particular user -> id [get]
 * 4. delete a user -> id [delete] -> HW
 * 5. update -> (property and id) [patch] -> update
 *
 *  routes -> /api/user
 *  methods->
 * **/

// /listen to the server
const PORT = process.env.PORT || 3000;
app.listen(PORT, function () {
  console.log("server is running at port 3000");
});
