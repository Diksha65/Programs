(function(window) {
    'use strict'

    var App = window.App || {}

    // it is used for organizing functions so no need of a constructor
    var Validation = {
        isCompanyEmail: function(email) {
            return /.+@gmail\.com$/.test(email) //literal regular expression as the pattern is put between the forward slashes.
        }
    }

    //event triggered when user removes focus from the fiels is called blur event
    App.Validation = Validation
    window.App = App
})(window);