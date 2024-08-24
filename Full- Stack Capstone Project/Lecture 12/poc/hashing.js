const bcrypt = require("bcrypt");
const password = "abcd";

async function fn() {
    /*********generation of random salt**********/
    console.time();
    const randomSalt = await bcrypt.genSalt(10);
    console.log("randomSalt", randomSalt);
    // blowfish algo
    const hash = await bcrypt.hash(password, randomSalt);
    const isTheSameorNot = await bcrypt.compare(password,hash);
console.log("result",isTheSameorNot)
    console.timeEnd();

}
fn();

/**
 *  1. We use Hashing algorithm : use a algorithm that always create different hash for a given password[no one should be able to decrypt] -> hash -> that is one way
    2. it should be slow
    3. how do you verify-> equality but we are not able to know the password 
 * 
 * **/

/****
 * 1. password ="abcd"
 *              randomSalt $2b$10$UzFi/hkE/HDZhm1pUaou0e
                hash $2b$10$UzFi/hkE/HDZhm1pUaou0eFfQGdO24W1377nLlB3V7jbD/dSacxpq
 
 * 
                user-2 
 * 2. password="abcd"
 *              randomSalt $2b$15$H1SefI7DW3JygmGT27eqAO
                hash : $2b$15$H1SefI7DW3JygmGT27eqAOJMdAWjcp1cKL8z.y07XS3wWVvZmqSIG [db]
 * **/


                 