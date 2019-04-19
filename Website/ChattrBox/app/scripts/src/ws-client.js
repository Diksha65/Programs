//variable for web socket handling
//This declaration uses new way of defining variables in ES6, called let scoping.
let socket;

//This function connects to the web sockets server.
function init(url) {
    socket = new WebSocket(url)
    console.log('connecting...')
}

//These are arrow funcitions or shorthand for anonymous functions.
function registerOpenHandler(handlerFunction) {
    socket.onopen = () => {
        console.log('open')
        handlerFunction();
    };
}

//function to handle messages that come in over the web sockets connection.
function registerMessageHandler(handlerFunction) {
    socket.onmessage = (e) => {
        console.log('message', e.data)
        let data = JSON.parse(e.data)
        handlerFunction(data)
    }
}

function sendMessage(payload) {
    socket.send(JSON.stringify(payload))
}

//This feature of ES6 to not specify the property name is called enhanced object literal
export default {
    init,
    registerOpenHandler,
    registerMessageHandler,
    sendMessage
}


