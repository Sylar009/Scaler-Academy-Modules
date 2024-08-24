

const UserModel = require("../../model/UserModel");
const bcrypt = require("bcrypt");
/*******************************you will need connection to the DB************************/
function encryptPasswordHelper(Model) {
    {
        const dotenv = require("dotenv");
        const path = require("path");
        const mongoose = require("mongoose");
        // it adds all the enviornment variables to processe.env
        dotenv.config({ path: path.join(__dirname, "../", "../", ".env") });
        /**********************connect with your DB***********************/
        const { DB_USER, DB_PASSWORD, } = process.env;

        // ******************connection with the DB**********************
        const dbURL =
            `mongodb+srv://${DB_USER}:${DB_PASSWORD}@cluster0.drcvhxp.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0`;
        mongoose.connect(dbURL)
            .then(async () => {
                console.log("connected to the DB");
                // ******************insert all the  entries**********************
                const allUser = await Model.find();
                for (let i = 0; i < allUser.length; i++) {
                    let user = allUser[i];
                    user.password = await bcrypt.hash(user.password, 10);
                    // validate before false 
                    await user.save({ validateBeforeSave: false });
                }
                // console.log("Alluser", allUser)
            }).then(() => {
                console.log("inserted all the entries");
            })
            .catch(err => { console.log(err) })
            .finally(() => {
                mongoose.disconnect();
                console.log("disconect from   DB");
            })


    }
}

encryptPasswordHelper(UserModel);