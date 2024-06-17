## Rest APIs

1. **Client-Server Separation**:
- Clear separation between client and server responsibilities.
- Clients handle the user interface, while servers manage data storage and processing.

2. **Resource-Based Routing**:
- Data is exposed as resources (e.g., `/users`, `/products`).
- Each resource is uniquely identified by a route.

3.  **Actions are done by HTTP method** 
- **GET**: Retrieve a resource.
- **POST**: Create a new resource.
- **PUT**: Update an existing resource.
- **DELETE**: Delete a resource.
- **PATCH** : update a part of resource.

4. **Statelessness**: [Authentciation,pagination]
- Each request from the client to the server must contain all the necessary information for the server to fulfil it .
- The server doesn’t store any client state between requests. That makes  request is independent and  reducing coupling b/w client and server .
<!-- /goForward ->🚫 -->
<!-- /page/:pageNumber ->👍 -->


### Benefits 
* **Scalability**: REST APIs are scalable and can handle a large number of clients.
* **Simplicity**: Easy to understand and use due to the use of standard HTTP methods and URLs.
* **Independence** : tech stack of client/server 





## Bonus Points
always add versoning to your API


## Pain points
* We need to find a way to effecticely organize our code -> MVC architecture
* We are not following DRY Principle -> lot of repetion (CRUD) -> [factory design pattern]