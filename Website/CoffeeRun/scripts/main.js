(function (window) {
    'use strict';

    var FORM_SELECTOR = '[data-coffee-order="form"]'
    var CHECKLIST_SELECTOR = '[data-coffee-order="checklist"]'
    var SERVER_URL = 'http://coffeerun-v2-rest-api.herokuapp.com/api/coffeeorders';

    var App = window.App;
    var Truck = App.Truck;
    var DataStore = App.DataStore;
    var RemoteDataStore = App.RemoteDataStore;
    var FormHandler = App.FormHandler;
    var CheckList = App.CheckList;
    var Validation = App.Validation;

    var formHandler = new FormHandler(FORM_SELECTOR)
    var checkList = new CheckList(CHECKLIST_SELECTOR)
    var remoteDS = new RemoteDataStore(SERVER_URL)

    //local variable is created. Cannot be used to interact outside the function
    //not prefixing App as we created local variables that point to App.{*}
        //var coffeeTruck = new Truck('Bacaffe', new DataStore()); 
    var coffeeTruck = new Truck('Bacaffe', remoteDS)

    //exporting  the truck to global namespace so that it can be interacted with.
    window.coffeeTruck = coffeeTruck; 
    
    checkList.addClickHandler(coffeeTruck.deliverOrder.bind(coffeeTruck))

    formHandler.addSubmitHandler(function(data) {
        return coffeeTruck.createOrder.call(coffeeTruck, data)
        .then(function() {
            checkList.addRow.call(checkList, data)
        })
    });
    
    formHandler.addInputHandler(Validation.isCompanyEmail)

    coffeeTruck.printOrders(checkList.addRow.bind(checkList))

})(window);


