/*
    Creating a remoteDataStore module which sends a request to the server and handles the response.
    It does so in the background by using Ajaxwithout causing the browser to reload.
    Ajax is a technique to communicate with the remote sever via javascript.
    Ajax  -  Asynchronous Javascript and XML
    At the core of Ajax is XMLHttpRequest Api


    This talks to the server oon behalf of the rest of the application.
    RemoteDataStore's methods communicate asynchronously with the server by sending a network request in the background.
    When browser receives a response from the server, it has an opportunity to invole a callback.

    Promises and Deferreds-
    Promises provide a way to architect very complex asnchronous code in a manageable way. 
    Executing next step if the currennt one exceeds is made simple with the use of promises. 
    Promises objects are always stored in one of these 3 states - pending, fulfilled or rejected
    Every promise has a then method which is fulfilled when the promise becomes fulfilled. Then is called and a callback can be passed.
    We can also chain many then calls together.

    jQuery's Deferred object work similarl to Promise for simple use case.
    jQuery's $.ajax returns a Deferred. Deferred objects have methods(then) that let us register callbacks for 2 of their states: fulfilled and rejected.

    then accepts a second arguement which is invoked when the Deferred shifts to rejected state. 

    Using then to register callbacks maps onto the way Promise s work. 
    If the Promise changes state to fulfilled, one set of callbacks is run. 
    If the Promise changes state to rejected, the other set of callbacks is run.

    When we register a callback function with .then, that callback has a new scope. 
    We need to .bind that anonymous function so that the value of this is set to the class's instance.
    
*/

(function (window) {
    'use strict';
    var App = window.App || {};
    var $ = window.jQuery;
    
    function RemoteDataStore(url) {
        if (!url) {
            throw new Error('No remote URL supplied.');
        }
        this.serverUrl = url;
    }

    RemoteDataStore.prototype.add = function(key, val) {
        return $.post(this.serverUrl, val, function(serverResponse) { //3 parameters are; whom to talk to, what to say and what to do with the information it gets back as response
            console.log(serverResponse)
        })
    }

    RemoteDataStore.prototype.getAll = function(cb) {
        return $.get(this.serverUrl, function(serverResponse) {
            if(cb) {
                console.log(serverResponse)
                cb(serverResponse)
            }
        })
    }

    RemoteDataStore.prototype.get = function(key, cb) {
        return $.get(this.serverUrl+'/'+key, function(serverResponse) {
            if(cb) {
                console.log(serverResponse)
                cb(serverResponse)
            }
        })
    }

    RemoteDataStore.prototype.remove = function(key) {
        return $.ajax(this.serverUrl + '/' + key, {
            type : 'DELETE'
        })
    }

    App.RemoteDataStore = RemoteDataStore;
    window.App = App;

})(window);