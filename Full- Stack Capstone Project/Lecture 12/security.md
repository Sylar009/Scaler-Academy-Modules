## Security measure
## Password :
 *  Usecase : uniquely identify a user (Authenticate user)
 *  What's the best place to store your original password : in your mind 
 *  Server check whether password that client enter is equal to the the password stored in the db   
    * Password comparison simple example : value 10 example
    * we as a server can do it without even knowing the actual password 
## how do you store password on the server
**Encryption Algorithm**-> SHA256,MD5
* Encryption-> input(Password)[key] -> output (random text) 
* Decryption-> (random text)[key] -> output (password) 
**Challenges**
1. user is lazy -> easy passwords
2. for a given input there will be same output
<!-- Dictonary search
abcd ->ajafgadsbfbdsb
1234-> asdjhfgdsgjbdsfh
password -> akjfhdsjhf
 -->
 **Solution**
 1. We use Hashing algorithm : use a algorithm that always create different hash for a given password[no one should be able to decrypt] -> hash -> that is one way
 2. it should be slow
 3. we will not be storing original password anywhere
`We will be using bcrypt that will give us the solution` 