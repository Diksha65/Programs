var path = require('path')

var extractFilePath = function(url) {
    var filePath
    var fileName = "index.html"
    
    //below code checks if the browser is asing for the default index.html file or another file.
    //If it is another file then the first character of the url i.e.. '/' is stripped off and the result is saved in filename
    
    if(url.length > 1) {
        fileName = url.substring(1)
    }
    console.log('The filename is: ' + fileName)
    filePath = path.resolve(__dirname, 'app', fileName)
    return filePath
}

//extracFilePath is assigned to a global variable names module.exports.
//This is a special variable by Node. 
//Whatever value is assigned to it is the value other modules can import.
//Any other variables or modules will not be visible to other modules.
module.exports = extractFilePath