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

            $(this).serializeArray().forEach(function (item) {
                data[item.name] = item.value;
            })

            if(data.size == "coffeezilla" && data.strength == "100" && data.flavor != "none") {
                var achieve = ifZilla[data.flavor]
                $('#myModal .modal-title').text(achieve.title)
                $('#myModal .modal-body').text(achieve.body)
                $('#myModal').modal('show');
            }

            /*
            $("#myModal").on("click", "#getPowerUp", function(){
                console.log('pressed')
                var powerUpElement = new CoffeePowerUp()
                
                this.$element.find('id="flavorshot').append(powerUpElement.$element)

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
            })
            */

            fn(data).then(function() {
                this.reset();
                this.elements[0].focus();
            }.bind(this))
        });
    };

    FormHandler.prototype.addInputHandler = function(fn) {
        this.$formElement.on('input','[name="emailAddress"]', function(event) {
            var emailAddress = event.target.value
            var message = ''
            if(fn(emailAddress)) {
                event.target.setCustomValidity('')
            } else {
                message = emailAddress+' is not an authorized email address!'
                event.target.setCustomValidity(message)
            }
        })
    }

    function CoffeePowerUp() {
        var $div = $('<div></div>', {
            'id' : 'coffeepowerup',
            'class' : 'form-group'
        })

        var $label = $('<label></label>', {
            for : 'PowerUp'
        })
        var labelDescription = 'Coffee Power Ups:'

        var $div1 = $('<div></div>', {
            'class' : 'form-check'
        })
        var $input1 = $('<input></input>', {
            'class' :'form-check-input',
            'id' : 'powerUp1',
            type : 'checkbox',
            name : 'powerup',
            value : 'timetravel'
        })
        var $label1 = $('<label></label>', {
            'class' : 'form-check-label',
            'for' : 'powerUp1'
        })
        var label1Description = 'Time Travel'

        var $div2 = $('<div></div>', {
            'class' : 'form-check'
        })
        var $input2 = $('<input></input>', {
            'class' :'form-check-input',
            'id' : 'powerUp2',
            type : 'checkbox',
            name : 'powerup',
            value : 'mindreading'
        })
        var $label2 = $('<label></label>', {
            'class' : 'form-check-label',
            'for' : 'powerUp2'
        })
        var label2Description = 'Mind Reading'

        var $div3 = $('<div></div>', {
            'class' : 'form-check'
        })
        var $input3 = $('<input></input>', {
            'class' :'form-check-input',
            'id' : 'powerUp3',
            type : 'checkbox',
            name : 'powerup',
            value : 'bugfreecode'
        })
        var $label3 = $('<label></label>', {
            'class' : 'form-check-label',
            'for' : 'powerUp3'
        })
        var label3Description = 'Bug Free Code'

        $label3.append(label3Description)
        $div3.append($input3)
        $div3.append($label3)

        $label2.append(label2Description)
        $div2.append($input2)
        $div2.append($label2)

        $label1.append(label1Description)
        $div1.append($input1)
        $div1.append($label1)

        $label.append(labelDescription)

        $div.append($label)
        $div.append($div1)
        $div.append($div2)
        $div.append($div3)

        this.$element = $div
    }

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
