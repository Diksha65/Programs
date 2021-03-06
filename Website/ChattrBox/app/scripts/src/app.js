/*
    ES6 classes provide a shorter syntax for constructor functions and prototype methods
*/

import socket from './ws-client'

class ChatApp {
    //constructor is a meqthod that is run whenever a new instance of the class is created.
    constructor() {
        socket.init('ws://localhost:3001')
        socket.registerOpenHandler(() => {
            let message = new ChatMessage({message: 'pow!'})
            socket.sendMessage(message.serialize())
        });
        socket.registerMessageHandler((data) => {
            console.log(data)
        })
    }
}

//This class represents an individual chat message
class ChatMessage {
    constructor({message : m, user : u = 'batman', timestamp : t = (new Date()).getTime()}) {
        this.message = m;
        this.user = u;
        this.timestamp = t;
    }
    serialize() {
        return {
            user: this.user,
            message: this.message,
            timestamp: this.timestamp
        }
    }
}

//This specifies that ChatApp is a default value available from the app module
export default ChatApp;