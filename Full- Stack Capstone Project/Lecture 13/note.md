1. **Launch an EC2 Instance:**
   - Log in to your AWS Management Console.
   - search the EC2 dashboard.
   - Click on "Launch Instance".
   - Choose an `Ubuntu AMI`.
   - Select an instance type and configure other settings as needed. -> micro small
   - Create or choose an existing key pair for SSH access. -> key pair 
   - Launch the instance.
2. **Connect to your EC2 Instance:**
   - Once the instance is launched, 
   - Open your terminal in the same folder where key is downlaoded 
   - Use SSH to connect to your instance -> go tot connect and enter the required command 
     - chmod 400 "<key_name>"
     - ssh -i "key_name" ubuntu@ec2-3-94-76-68.compute-1.amazonaws.com

3. **Update Ubuntu:**
   - Once connected to the instance, update the package lists for upgrades and install new versions of software:
  
     ```
     sudo apt update
     sudo apt upgrade
     ```
4. **Install Node.js:**
    - linux : https://github.com/nodesource/distributions
   - Install Node.js and npm using the following commands:
     ```
     curl -sL https://deb.nodesource.com/setup_18.x | sudo -E bash -
     sudo apt-get install -y nodejs
     ```

5. **Create Your Express Application:** -> fetch it from github
   - Create a new directory for your project and navigate into it:
     ```
     mkdir my-express-app
     cd my-express-app
     ```
   - Initialize a new Node.js project:
     ```
     npm init -y
     ```
   - Install Express:
     ```
     npm install express
     ```
   - Create a file named `app.js` and define your Express server in it:
     ```javascript
     const express = require('express');
     const app = express();
     
     app.get('/', (req, res) => {
         res.send('Hello World!');
     });
     
     const port = process.env.PORT || 3000;
     app.listen(port, () => {
         console.log(`Server running on port ${port}`);
     });
6. **Install PM2:**
   - Install PM2 globally to manage your Node.js application:
     ```
     sudo npm install -g pm2
    ```


7. **Start Your Express Server with PM2:**
   - Start your Express server with PM2:
     ```
     pm2 start app.js
     ```

8. **Set PM2 to Start on Boot:**
   - To ensure that your Node.js application starts automatically on system boot, you can use PM2's startup command:
     ```
     pm2 startup systemd
     ```
9. update the inbound for http protocol with the post of your serevr 
 - aws will allow the end client to access you server  on the given port