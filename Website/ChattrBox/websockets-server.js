/*
    ws module gives Node.js an esy way to communicate via WebSockets.
    Websockets enable sending and receiving messages via a single connection.
    websockets keep track of the connected users for us via its clients features. It is an array that you can iterate through.
        This feature can help us to send the new message to all the connected users.
*/

var WebSocket = require('ws')

//Needed to create a working websocket server
var WebSocketServer = WebSocket.Server
var port = 3001

//when this is executed, new websocketserver is established and bound to the port 3001
var ws = new WebSocketServer({
    port : port
})

//to keep old messages 
var messages = []

console.log('websockets server started')

//establishing callback for any connections event for the websockets server
ws.on('connection', function(socket) {
    console.log('client connection established')

    //sends out old messages to each new connection as it arrives
    messages.forEach(function(msg) {
        socket.send(msg)
    })

    socket.on('message', function(data) {
        console.log('message received: ' + data)
        //adds each msg to an array
        messages.push(data)
        ws.clients.forEach(function(clientSocket) {
            clientSocket.send(data)
        })
    })
})

