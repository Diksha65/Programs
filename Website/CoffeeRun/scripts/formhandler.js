(function (window) {
    'use strict';
    
    var App = window.App || {};
    var $ = window.jQuery;
    
    function FormHandler(selector) {
        if (!selector) {
            throw new Error('No selector provided');
        }
    
        this.$formElement = $(selector);
        if (this.$formElement.length === 0) {
            throw new Error('Could not find element with selector: ' + selector);
        }
    }

    FormHandler.prototype.addSubmitHandler = function (fn) {
        console.log('Setting submit handler for form');
        
        this.$formElement.on('submit', function (event) {
            event.preventDefault();
            var data = {};  //this object is a reference to the form elemment
            $(this).serializeArray().forEach(function (item) {
                if(item.name=="powerup") {
                    data[item.name] = new Array();
                    $("input:checkbox[name=powerup]:checked").each(function() {
                        data[item.name].push($(this).val());
                    });
                } else {
                    data[item.name] = item.value;
                }
            })

            var ifZilla = {
                caramel : {
                    title : 'Bonanza!! Dulce de Leche Unlocked',
                    body : 'WOW! Wanna put some dulce the leche in that coffee?'
                },
                almond: {
                    title: 'Bonanza!! Almond Milk Unlocked',
                    body: 'WOW! Shall we change the order to Almond milk too?'
                },
                mocha: {
                    title: 'Bonanza!! Extra Beans Unlocked',
                    body: 'WOW! Why not rather go with some Kenyan beans?'
                }
            };

            if(data.size == "coffeezilla" && data.strength == "100" && data.flavor != "none") {
                var achieve = ifZilla[data.flavor]
                $('#myModal .modal-title').text(achieve.title)
                $('#myModal .modal-body').text(achieve.body)
                $('#myModal').modal('show');
            }

            fn(data);
            this.reset();
            this.elements[0].focus();
        });
    };

    App.FormHandler = FormHandler;
    window.App = App;
})(window);

/*
    In JS, vatiables can have letters, numbers, underscore and a dollar sign.
    But the  variables can start with only letters, underscore and dollar sign

    jQuery is used for finding elements in DOM.
    
    Prefixing a variable with $ is a sign that the variable refers to elements selected using jQuery. 

    jQuery's $ functions does not return references to DOM elements. 
    It returns a single object which contains references to the selected elements. 
        - This collection of reference is also called 'jQuery-wrapped selection' or 'jQuery-wrapped collection'

    jQuery will return an empty selection if it does not find anything matching teh selector. It will not throw any error. 

*/
