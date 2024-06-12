## server vs APIs
### server
It is usually when a user visits a website ->to get some data/webpage. It makes the http request by clicking on a button or by doing some other action . A request will be send to a backend server and then the server will search the content related to the request and return the resp. 

On a Higher level these resp
**Server** : 
* It is used to serves html document , assets like images and data also.
* It is also used to provide authentication ,autorization to the client 


### API(backend dev) : 
backend API -> special kind of server that takes in an HTTP request and returns `data` in a particular format 
    * JSON
    * XML 
#### usecase 
 google drive->  where we have multiple platforms to support (Mobile,web,macos) . we can have 3 servers to support all the platform 
 * **WebAPI:** : Does authentication, has the information of where  particular assets are present, control the access [common]
 * **Files server :** Hold actual assets like docs, video, images[common]
 * **UI server:** for web access we can have a UI server  for browser as a client. 

 * Google Maps API : uber, swiggy, zomato 



 ## HTTP
 `Packet`: head + body
 `Head` -> Request method, Response code 

 In an API
 * where you want to go -> url
 * what you want to do -> Request method

 ### Request Methods
 * GET -> fetch data from the server
 * POST -> create a entry in the server
 * PATCH  -> update
 * DELETE -> delete
 <!-- covered later in detail -->
*  PUT : create / replace an asset completely 
 * OPTION ->  The OPTIONS method is used to request information about the communication options available for a target resource, such as the supported HTTP methods, headers, or origin policies.
 
  * HEAD -> The HEAD method is similar to the GET method, but it retrieves only the headers of the response without the response body. It is useful for checking the headers of a resource without actually downloading the resource's content. [`get only the head part not the body`]

  ### Response code  
  it is numercial code between -> 100 to 599 that indicates the final result of an http request from a server
  * 404 -> assets is not there
  * 200 -> task completed
  * 201 -> enitity is created 
  * 301 -> permanent redirection
  `List of response code` : [link](https://www.iana.org/assignments/http-status-codes/http-status-codes.xhtml)


## Express and API dev
*  express -> to build REST APIs
* Postman -> to test the api


<!-- 
package.json -> every project as a package -> configuration
package-lock.json-> 
 -->

 
    