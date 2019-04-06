(function (window) {
    'use strict';

    var FORM_SELECTOR = '[data-coffee-order="form"]'
    var App = window.App;
    var Truck = App.Truck;
    var DataStore = App.DataStore;
    var FormHandler = App.FormHandler;

    //local variable is created. Cannot be used to interact outside the function
    //not prefixing App as we created local variables that point to App.{*}
    var coffeeTruck = new Truck('Bacaffe', new DataStore()); 

    //exporting  the truck to global namespace so that it can be interacted with.
    window.coffeeTruck = coffeeTruck; 

    var formHandler = new FormHandler(FORM_SELECTOR)
    formHandler.addSubmitHandler(coffeeTruck.createOrder.bind(coffeeTruck));
    
    console.log(formHandler)

})(window);


