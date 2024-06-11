## Foundational facts
* Javascript Engine-> only gives you logic
* Enviornment -> give you features->
    * Frontend : Browser-> (console, setTimout, Fetch , ajax)
    * Backend : Nodejs (console,setTimout,)
* Enviornment exposes all those features in the form of an object

## Build a netflix server -> ??
### nodejs  -> runtime -> enviornment (2009)
* ability to write the logic -> javascript laguage 
* Different modules for different features 

### Imp modules
* work with the files  -> fs
* to issue with path -> path
* Network calls -> http 
* access that os as well -> os 


<!-- created -> 
* UNIX(proprietry)(AT&T BELL)
    * Linux -> open source version unix , macos -> similar
    "/Users/apple/Documents/Projects_module_march/lecture_1/readme.md"
* DOS ->
    * windows -> "\Users\apple\Documents\Projects_module_march\lecture_1\readme.md" -->

## HTTP packets

### HTTP headers
#### Req header
*  Req method
    * GET  -> get some data from the server
    * POST  -> submit some data to the server
    * PATCH  -> update the data from the server
    * DELETE -> delet the data from the server
* Req.url
        -> it is an exposed path from the server that indicates a particular functionality

#### Response Header

* Res content-type ->which type of data are we sending to the frontend
    * video
    * HTML doc
    * images
    * json
* Res code 
        -> 100-600
