//built in 'require' function can access the http module included with Node.
var http = require('http')

//importing Node.js file system module 'fs'
var fs = require('fs')

//importing the extractFilePath function created in extract.js
var extract = require('./extract')

var wwss = require('./websockets-server')

var handleError = function(err, res) {
    res.writeHead(404)
    res.end()
}

var server = http.createServer(function(req, res) {
    console.log('Responding to the request')
    
    //request object's url property and call the extractfilepath function of extract.js.
    var filePath = extract(req.url)
    fs.readFile(filePath, function(err, data) {
        if(err) {
            handleError(err, res)
            return
        } else {
            res.end(data)
        }
    })
})
server.listen(3000) //binding a port

/*
Node.js -> open source project that lets write javascript outside the browser.

When JS is written for the browser, we get acces to global objects like window and document and other APIs.
With Node, our code can access the harddrive, databases and the network.

npm - node package manager

The package.json file acts as Node project's manifest.

npm init -> this command creates a default package.json file for the project.

"node index.js" -> lets us start the Node server by running npm start at the beginning of the command line.

wscat npm module - tool for connecting to and communicating with a websockets server

*/