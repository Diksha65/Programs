(function (window) {
    'use strict';

    var FORM_SELECTOR = '[data-coffee-order="form"]'
    var CHECKLIST_SELECTOR = '[data-coffee-order="checklist"]'
    var App = window.App;
    var Truck = App.Truck;
    var DataStore = App.DataStore;
    var FormHandler = App.FormHandler;
    var CheckList = App.CheckList;
    var Validation = App.Validation;

    //local variable is created. Cannot be used to interact outside the function
    //not prefixing App as we created local variables that point to App.{*}
    var coffeeTruck = new Truck('Bacaffe', new DataStore()); 

    //exporting  the truck to global namespace so that it can be interacted with.
    window.coffeeTruck = coffeeTruck; 

    var formHandler = new FormHandler(FORM_SELECTOR)
    var checkList = new CheckList(CHECKLIST_SELECTOR)
    
    checkList.addClickHandler(coffeeTruck.deliverOrder.bind(coffeeTruck))

    formHandler.addSubmitHandler(function(data) {
        coffeeTruck.createOrder.call(coffeeTruck, data)
        checkList.addRow.call(checkList, data)
    });
    
    formHandler.addInputHandler(Validation.isCompanyEmail)

})(window);


