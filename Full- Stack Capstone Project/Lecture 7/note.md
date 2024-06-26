## HTTP packet
* Header : metadata about the packet
* cookies -> part of header 
* Body : contains actual data that is being

## cookies
* cookie is a client side storage[it will store in the browser]
* It stores data in the format `key : value` pairs . These pair should be of type string.
* Server sends these cookies to the client
*  on the client side these cookies are stored and mapped to the server that has send the cookies 
*   For the next request -> client will automatically share this cookie with the server

## usecase 
* giving personalize experience
* widely used for user tracking

### Learning : 
* used to share some data to the client that server can access later 


## Identification vs Authentication vs Authorization
* **Identification** : Identification is the process of stating or claiming who you are. It's the initial step where a user asserts an identity, but it doesn't validate the authenticity of the claim. **Application** ->   User perferences are solved 
  
* **Authentication**: is the process of verifying whether the claimed identity is valid and accurate.It ensures that the user's identity is genuine before granting access to protected resources or functionalities. 
 * login ,otp , bometric 
 * web token

* * **Authorization** is the process of determining what actions or resources an authenticated user is permitted to access within a system or application.

## JWT -> json web token

### Design constraints
* it should be secure
* we need to design a stateless token 
  
## steps of JWT creation and validation
To prevent tampering
1. JSON token creation :
JSON web token is built out of three component
  * `Payload` : plain text 
  *  `Algorithm`: in plain text name of the algorithm
  * `signature`: encryped text that is build using ecrypting  three texts
        * payload+ algorithm name+ secret key 
2. Secret key is only known by the server
3. validation 
      1. server get's JWT token inside cookies
      2. token will contains -> [payload+algorithm](plaintext) + signature(encrypted)
      3. server takes -> payload from incoming token + algorithm from incoming token + `secret from the server` and builds a fresh signature 
      4.  compare  signature of incoming token and signature that is build in the above step
      5.   validation fails if signature coming from the client does not match with freshely prepared signature
* Vulnerability  : Secret store in the server