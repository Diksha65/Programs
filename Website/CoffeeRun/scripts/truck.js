(function (window) {
    'use strict'
    var App = window.App || {}
    
    function Truck(truckId, db) {
        this.truckId = truckId;
        this.db = db;
    }

    Truck.prototype.createOrder = function(order) {
        console.log('Adding order for ' + order.emailAddress)
        this.db.add(order.emailAddress, order)
    }

    Truck.prototype.deliverOrder = function(customerId) {
        console.log('Deliverign order for ' + customerId)
        this.db.remove(customerId)
    }

    Truck.prototype.printOrders = function() {
        var customerIdArray = Object.keys(this.db.getAll())

        console.log('Truck #' + this.truckId + ' has pending orders:');
        customerIdArray.forEach(function (id) {
            console.log(this.db.get(id));
            /*
                For constructors and prototype functions, value of 'this' is the instance object. Instance is the owner of fn call.
                For callback functions, this is not automatically assigned to an object. 
                We can manually assign what object should be the owner by using a function's bind method.
                Inside the forEach callback, this is undefined as the callback has no owner
            */
        }.bind(this));
    };

    App.Truck = Truck;
    window.App = App;

})(window);