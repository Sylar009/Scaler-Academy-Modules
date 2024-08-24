/***
 * a. Migration -> 
 *  * update, delete, create -> a list of documents 
 *  * it is seperate from your server
 *   
 * b. What are the usual steps
 *  1. you will need connection to the DB 
 *  2. You will need a model to seed the entries
 *  3. you need to have a query method that can do action on multiple entries
 *      *  updateMany 
 *      *  deleteMany
 *      *  insertMany
 * 4. close the connection
 * ***/
const products = require("../../seed_data/products");
const ProductModel = require("../../ProductModel");
/*******************************you will need connection to the DB************************/
function seedData(Model, listOfEntries) {
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
            .then(() => {
                console.log("connected to the DB");
                // ******************insert all the  entries**********************
                return Model.insertMany(listOfEntries);
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

seedData(ProductModel, products);