/*
    ws module gives Node.js an esy way to communicate via WebSockets.
    Websockets enable sending and receiving messages via a single connection.
*/

var WebSocket = require('ws')

//Needed to create a working websocket server
var WebSocketServer = WebSocket.Server
var port = 3001

//when this is executed, new websocketserver is established and bound to the port 3001
var ws = new WebSocketServer({
    port : port
})

console.log('websockets server started')

//establishing callback for any connections event for the websockets server
ws.on('connection', function(socket) {
    console.log('client connection established')
})

