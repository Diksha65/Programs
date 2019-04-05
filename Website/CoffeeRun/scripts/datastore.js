/*
    Javascript does not havhe classes. But it provides us a way to create a custom type of class.

    Object factory functions are called constructors in javascript

    A factory function is any function which is not a class or constructor that returns an object.
    In JS, any function can return an object. When it does so without the 'new' keyword, its called a factory function.

    Naming convention of constructors in JS - start with a capital letter. 

    Difference between a constructor and a normal function - we use the keyword new when we call a constructor function

    Functions in javascript are also objects. which means that they can have properties. 
    All instances created by a constructor have access to a shared storehouse of properties and methods 
                - the prototype property of constructor.
    
    

*/

(function (window) {
    'use strict' 
    /*
        Advantages of strict mode - 
            1. eliminates some silent js errors by changing them to throw errors
            2. can sometimes run faster
        Using it before any statement in the function makes it applicable for the entire function    
    */

    var App = window.App || {}

    function DataStore() { //job of constructor is to create and customize new object. 
        this.data = {}; //new object is referred using 'this'
    }

    DataStore.prototype.add = function(key, val) {
        this.data[key] = val;
    }

    DataStore.prototype.get = function(key) {
        return this.data[key];
    }

    DataStore.prototype.getAll = function() {
        return this.data;
    }

    DataStore.prototype.remove = function(key) {
        delete this.data[key]
    }

    App.DataStore = DataStore;
    window.App = App;
    /*
        Any global variable is a property of the window object. 
        Window contains a DOM document. 
    */
})(window);