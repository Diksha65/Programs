/*
    Creating a remoteDataStore module which sends a request to the server and handles the response.
    It does so in the background by using Ajaxwithout causing the browser to reload.
    Ajax is a technique to communicate with the remote sever via javascript.
    Ajax  -  Asynchronous Javascript and XML
    At the core of Ajax is XMLHttpRequest Api


    This talks to the server oon behalf of the rest of the application.
    RemoteDataStore's methods communicate asynchronously with the server by sending a network request in the background.
    When browser receives a response from the server, it has an opportunity to invole a callback.
    
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
        $.post(this.serverUrl, val, function(serverResponse) { //3 parameters are; whom to talk to, what to say and what to do with the information it gets back as response
            console.log(serverResponse)
        })
    }

    App.RemoteDataStore = RemoteDataStore;
    window.App = App;

})(window);