(function(window) {
    'use strict'

    var App = window.App || {};
    var $ = window.jQuery;

    function CheckList(selector) {
        if (!selector) {
            throw new Error('No selector provided');
        }
        
        this.$element = $(selector);
        if (this.$element.length === 0) {
            throw new Error('Could not find element with selector: ' + selector);
        }
    }

    /*
        'click' is the event name, 'input' is the filtering selector. 
        Filtering selector tells the event handler to run the callback fn only if the event was triggered by an <input> element.
        This pattern is called event delegation
    */
    CheckList.prototype.addClickHandler = function(fn) {
        this.$element.on('click', 'input', function(event) {
            var email = event.target.value
            this.removeRow(email)
            fn(email)
        }.bind(this))
    }

    CheckList.prototype.addRow = function(coffeeOrder) {
        //Remove any existing row that match the email address
        this.removeRow(coffeeOrder.emailAddress)

        //Creating a new instance of row by using the coffee order info
        var rowElement = new Row(coffeeOrder)

        //Add the new row instance's $element property to the checklist
        this.$element.append(rowElement.$element)
    }

    CheckList.prototype.removeRow = function(email) {
        this.$element   
            .find('[value="' + email + '"] ')
            .closest('[data-coffee-order="checkbox"]')
            .remove();
    }

    /*
        This constructor is in charge of creating the DOM elementsnecessary to create a single coffee order. 
        But it will not be exported to the app namespace. it will only be used internally by one of the checklist prototype functions
        Constructors never have a return statement
        JS automatically returns a value when we use a keyword new with the constructor
    */
    function Row(coffeeOrder) {
        var $div = $('<div></div>', {
            'data-coffee-order' : 'checkbox',
            'class' : 'checkbox'
        })

        var $label = $('<label></label>')

        var $checkbox = $('<input></input>', {
            type : 'checkbox',
            value : coffeeOrder.emailAddress
        })

        var description = coffeeOrder.size + ', ';
        if(coffeeOrder.flavor) {
            description += coffeeOrder.flavor + ', ';
        }
        description += coffeeOrder.coffee + ', (' + coffeeOrder.emailAddress + ') [' + coffeeOrder.strength + 'x]';

        var backgroundColor = ""
        switch(coffeeOrder.flavor) {
            case 'caramel': backgroundColor = '#F5F5DC'; break;
            case 'almond': backgroundColor = '#DEB887'; break;
            case 'mocha': backgroundColor = '#D2691E'; break;
        }
        if(backgroundColor) {
            $label.css('background', backgroundColor)
        }

        $label.append($checkbox)
        $label.append(description)
        $div.append($label)

        this.$element = $div
    }

    App.CheckList = CheckList;
    window.App = App;
})(window);