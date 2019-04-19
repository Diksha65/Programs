(function(){function r(e,n,t){function o(i,f){if(!n[i]){if(!e[i]){var c="function"==typeof require&&require;if(!f&&c)return c(i,!0);if(u)return u(i,!0);var a=new Error("Cannot find module '"+i+"'");throw a.code="MODULE_NOT_FOUND",a}var p=n[i]={exports:{}};e[i][0].call(p.exports,function(r){var n=e[i][1][r];return o(n||r)},p,p.exports,r,e,n,t)}return n[i].exports}for(var u="function"==typeof require&&require,i=0;i<t.length;i++)o(t[i]);return o}return r})()({1:[function(require,module,exports){
'use strict';

Object.defineProperty(exports, "__esModule", {
    value: true
});

var _createClass = function () { function defineProperties(target, props) { for (var i = 0; i < props.length; i++) { var descriptor = props[i]; descriptor.enumerable = descriptor.enumerable || false; descriptor.configurable = true; if ("value" in descriptor) descriptor.writable = true; Object.defineProperty(target, descriptor.key, descriptor); } } return function (Constructor, protoProps, staticProps) { if (protoProps) defineProperties(Constructor.prototype, protoProps); if (staticProps) defineProperties(Constructor, staticProps); return Constructor; }; }();

var _wsClient = require('./ws-client');

var _wsClient2 = _interopRequireDefault(_wsClient);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function _classCallCheck(instance, Constructor) { if (!(instance instanceof Constructor)) { throw new TypeError("Cannot call a class as a function"); } } /*
                                                                                                                                                              ES6 classes provide a shorter syntax for constructor functions and prototype methods
                                                                                                                                                          */

var ChatApp =
//constructor is a meqthod that is run whenever a new instance of the class is created.
function ChatApp() {
    _classCallCheck(this, ChatApp);

    _wsClient2.default.init('ws://localhost:3001');
    _wsClient2.default.registerOpenHandler(function () {
        var message = new ChatMessage({ message: 'pow!' });
        _wsClient2.default.sendMessage(message.serialize());
    });
    _wsClient2.default.registerMessageHandler(function (data) {
        console.log(data);
    });
};

//This class represents an individual chat message


var ChatMessage = function () {
    function ChatMessage(_ref) {
        var m = _ref.message,
            _ref$user = _ref.user,
            u = _ref$user === undefined ? 'batman' : _ref$user,
            _ref$timestamp = _ref.timestamp,
            t = _ref$timestamp === undefined ? new Date().getTime() : _ref$timestamp;

        _classCallCheck(this, ChatMessage);

        this.message = m;
        this.user = u;
        this.timestamp = t;
    }

    _createClass(ChatMessage, [{
        key: 'serialize',
        value: function serialize() {
            return {
                user: this.user,
                message: this.message,
                timestamp: this.timestamp
            };
        }
    }]);

    return ChatMessage;
}();

//This specifies that ChatApp is a default value available from the app module


exports.default = ChatApp;

},{"./ws-client":3}],2:[function(require,module,exports){
'use strict';

var _app = require('./app');

var _app2 = _interopRequireDefault(_app);

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

new _app2.default(); //It imports the chatapp exported by app.js

},{"./app":1}],3:[function(require,module,exports){
'use strict';

Object.defineProperty(exports, "__esModule", {
    value: true
});
//variable for web socket handling
//This declaration uses new way of defining variables in ES6, called let scoping.
var socket = void 0;

//This function connects to the web sockets server.
function init(url) {
    socket = new WebSocket(url);
    console.log('connecting...');
}

//These are arrow funcitions or shorthand for anonymous functions.
function registerOpenHandler(handlerFunction) {
    socket.onopen = function () {
        console.log('open');
        handlerFunction();
    };
}

//function to handle messages that come in over the web sockets connection.
function registerMessageHandler(handlerFunction) {
    socket.onmessage = function (e) {
        console.log('message', e.data);
        var data = JSON.parse(e.data);
        handlerFunction(data);
    };
}

function sendMessage(payload) {
    socket.send(JSON.stringify(payload));
}

//This feature of ES6 to not specify the property name is called enhanced object literal
exports.default = {
    init: init,
    registerOpenHandler: registerOpenHandler,
    registerMessageHandler: registerMessageHandler,
    sendMessage: sendMessage
};

},{}]},{},[2])
//# sourceMappingURL=data:application/json;charset=utf-8;base64,eyJ2ZXJzaW9uIjozLCJzb3VyY2VzIjpbIm5vZGVfbW9kdWxlcy9icm93c2VyLXBhY2svX3ByZWx1ZGUuanMiLCJhcHAvc2NyaXB0cy9zcmMvYXBwLmpzIiwiYXBwL3NjcmlwdHMvc3JjL21haW4uanMiLCJhcHAvc2NyaXB0cy9zcmMvd3MtY2xpZW50LmpzIl0sIm5hbWVzIjpbXSwibWFwcGluZ3MiOiJBQUFBOzs7Ozs7Ozs7QUNJQTs7Ozs7OzBKQUpBOzs7O0lBTU0sTztBQUNGO0FBQ0EsbUJBQWM7QUFBQTs7QUFDVix1QkFBTyxJQUFQLENBQVkscUJBQVo7QUFDQSx1QkFBTyxtQkFBUCxDQUEyQixZQUFNO0FBQzdCLFlBQUksVUFBVSxJQUFJLFdBQUosQ0FBZ0IsRUFBQyxTQUFTLE1BQVYsRUFBaEIsQ0FBZDtBQUNBLDJCQUFPLFdBQVAsQ0FBbUIsUUFBUSxTQUFSLEVBQW5CO0FBQ0gsS0FIRDtBQUlBLHVCQUFPLHNCQUFQLENBQThCLFVBQUMsSUFBRCxFQUFVO0FBQ3BDLGdCQUFRLEdBQVIsQ0FBWSxJQUFaO0FBQ0gsS0FGRDtBQUdILEM7O0FBR0w7OztJQUNNLFc7QUFDRiwrQkFBd0Y7QUFBQSxZQUFqRSxDQUFpRSxRQUEzRSxPQUEyRTtBQUFBLDZCQUE5RCxJQUE4RDtBQUFBLFlBQXZELENBQXVELDZCQUFuRCxRQUFtRDtBQUFBLGtDQUF6QyxTQUF5QztBQUFBLFlBQTdCLENBQTZCLGtDQUF4QixJQUFJLElBQUosRUFBRCxDQUFhLE9BQWIsRUFBeUI7O0FBQUE7O0FBQ3BGLGFBQUssT0FBTCxHQUFlLENBQWY7QUFDQSxhQUFLLElBQUwsR0FBWSxDQUFaO0FBQ0EsYUFBSyxTQUFMLEdBQWlCLENBQWpCO0FBQ0g7Ozs7b0NBQ1c7QUFDUixtQkFBTztBQUNILHNCQUFNLEtBQUssSUFEUjtBQUVILHlCQUFTLEtBQUssT0FGWDtBQUdILDJCQUFXLEtBQUs7QUFIYixhQUFQO0FBS0g7Ozs7OztBQUdMOzs7a0JBQ2UsTzs7Ozs7QUNwQ2Y7Ozs7OztBQUNBLElBQUksYUFBSixHLENBRkE7Ozs7Ozs7O0FDQUE7QUFDQTtBQUNBLElBQUksZUFBSjs7QUFFQTtBQUNBLFNBQVMsSUFBVCxDQUFjLEdBQWQsRUFBbUI7QUFDZixhQUFTLElBQUksU0FBSixDQUFjLEdBQWQsQ0FBVDtBQUNBLFlBQVEsR0FBUixDQUFZLGVBQVo7QUFDSDs7QUFFRDtBQUNBLFNBQVMsbUJBQVQsQ0FBNkIsZUFBN0IsRUFBOEM7QUFDMUMsV0FBTyxNQUFQLEdBQWdCLFlBQU07QUFDbEIsZ0JBQVEsR0FBUixDQUFZLE1BQVo7QUFDQTtBQUNILEtBSEQ7QUFJSDs7QUFFRDtBQUNBLFNBQVMsc0JBQVQsQ0FBZ0MsZUFBaEMsRUFBaUQ7QUFDN0MsV0FBTyxTQUFQLEdBQW1CLFVBQUMsQ0FBRCxFQUFPO0FBQ3RCLGdCQUFRLEdBQVIsQ0FBWSxTQUFaLEVBQXVCLEVBQUUsSUFBekI7QUFDQSxZQUFJLE9BQU8sS0FBSyxLQUFMLENBQVcsRUFBRSxJQUFiLENBQVg7QUFDQSx3QkFBZ0IsSUFBaEI7QUFDSCxLQUpEO0FBS0g7O0FBRUQsU0FBUyxXQUFULENBQXFCLE9BQXJCLEVBQThCO0FBQzFCLFdBQU8sSUFBUCxDQUFZLEtBQUssU0FBTCxDQUFlLE9BQWYsQ0FBWjtBQUNIOztBQUVEO2tCQUNlO0FBQ1gsY0FEVztBQUVYLDRDQUZXO0FBR1gsa0RBSFc7QUFJWDtBQUpXLEMiLCJmaWxlIjoiZ2VuZXJhdGVkLmpzIiwic291cmNlUm9vdCI6IiIsInNvdXJjZXNDb250ZW50IjpbIihmdW5jdGlvbigpe2Z1bmN0aW9uIHIoZSxuLHQpe2Z1bmN0aW9uIG8oaSxmKXtpZighbltpXSl7aWYoIWVbaV0pe3ZhciBjPVwiZnVuY3Rpb25cIj09dHlwZW9mIHJlcXVpcmUmJnJlcXVpcmU7aWYoIWYmJmMpcmV0dXJuIGMoaSwhMCk7aWYodSlyZXR1cm4gdShpLCEwKTt2YXIgYT1uZXcgRXJyb3IoXCJDYW5ub3QgZmluZCBtb2R1bGUgJ1wiK2krXCInXCIpO3Rocm93IGEuY29kZT1cIk1PRFVMRV9OT1RfRk9VTkRcIixhfXZhciBwPW5baV09e2V4cG9ydHM6e319O2VbaV1bMF0uY2FsbChwLmV4cG9ydHMsZnVuY3Rpb24ocil7dmFyIG49ZVtpXVsxXVtyXTtyZXR1cm4gbyhufHxyKX0scCxwLmV4cG9ydHMscixlLG4sdCl9cmV0dXJuIG5baV0uZXhwb3J0c31mb3IodmFyIHU9XCJmdW5jdGlvblwiPT10eXBlb2YgcmVxdWlyZSYmcmVxdWlyZSxpPTA7aTx0Lmxlbmd0aDtpKyspbyh0W2ldKTtyZXR1cm4gb31yZXR1cm4gcn0pKCkiLCIvKlxuICAgIEVTNiBjbGFzc2VzIHByb3ZpZGUgYSBzaG9ydGVyIHN5bnRheCBmb3IgY29uc3RydWN0b3IgZnVuY3Rpb25zIGFuZCBwcm90b3R5cGUgbWV0aG9kc1xuKi9cblxuaW1wb3J0IHNvY2tldCBmcm9tICcuL3dzLWNsaWVudCdcblxuY2xhc3MgQ2hhdEFwcCB7XG4gICAgLy9jb25zdHJ1Y3RvciBpcyBhIG1lcXRob2QgdGhhdCBpcyBydW4gd2hlbmV2ZXIgYSBuZXcgaW5zdGFuY2Ugb2YgdGhlIGNsYXNzIGlzIGNyZWF0ZWQuXG4gICAgY29uc3RydWN0b3IoKSB7XG4gICAgICAgIHNvY2tldC5pbml0KCd3czovL2xvY2FsaG9zdDozMDAxJylcbiAgICAgICAgc29ja2V0LnJlZ2lzdGVyT3BlbkhhbmRsZXIoKCkgPT4ge1xuICAgICAgICAgICAgbGV0IG1lc3NhZ2UgPSBuZXcgQ2hhdE1lc3NhZ2Uoe21lc3NhZ2U6ICdwb3chJ30pXG4gICAgICAgICAgICBzb2NrZXQuc2VuZE1lc3NhZ2UobWVzc2FnZS5zZXJpYWxpemUoKSlcbiAgICAgICAgfSk7XG4gICAgICAgIHNvY2tldC5yZWdpc3Rlck1lc3NhZ2VIYW5kbGVyKChkYXRhKSA9PiB7XG4gICAgICAgICAgICBjb25zb2xlLmxvZyhkYXRhKVxuICAgICAgICB9KVxuICAgIH1cbn1cblxuLy9UaGlzIGNsYXNzIHJlcHJlc2VudHMgYW4gaW5kaXZpZHVhbCBjaGF0IG1lc3NhZ2VcbmNsYXNzIENoYXRNZXNzYWdlIHtcbiAgICBjb25zdHJ1Y3Rvcih7bWVzc2FnZSA6IG0sIHVzZXIgOiB1ID0gJ2JhdG1hbicsIHRpbWVzdGFtcCA6IHQgPSAobmV3IERhdGUoKSkuZ2V0VGltZSgpfSkge1xuICAgICAgICB0aGlzLm1lc3NhZ2UgPSBtO1xuICAgICAgICB0aGlzLnVzZXIgPSB1O1xuICAgICAgICB0aGlzLnRpbWVzdGFtcCA9IHQ7XG4gICAgfVxuICAgIHNlcmlhbGl6ZSgpIHtcbiAgICAgICAgcmV0dXJuIHtcbiAgICAgICAgICAgIHVzZXI6IHRoaXMudXNlcixcbiAgICAgICAgICAgIG1lc3NhZ2U6IHRoaXMubWVzc2FnZSxcbiAgICAgICAgICAgIHRpbWVzdGFtcDogdGhpcy50aW1lc3RhbXBcbiAgICAgICAgfVxuICAgIH1cbn1cblxuLy9UaGlzIHNwZWNpZmllcyB0aGF0IENoYXRBcHAgaXMgYSBkZWZhdWx0IHZhbHVlIGF2YWlsYWJsZSBmcm9tIHRoZSBhcHAgbW9kdWxlXG5leHBvcnQgZGVmYXVsdCBDaGF0QXBwOyIsIi8vSXQgaW1wb3J0cyB0aGUgY2hhdGFwcCBleHBvcnRlZCBieSBhcHAuanNcbmltcG9ydCBDaGF0QXBwIGZyb20gJy4vYXBwJztcbm5ldyBDaGF0QXBwKCk7IiwiLy92YXJpYWJsZSBmb3Igd2ViIHNvY2tldCBoYW5kbGluZ1xuLy9UaGlzIGRlY2xhcmF0aW9uIHVzZXMgbmV3IHdheSBvZiBkZWZpbmluZyB2YXJpYWJsZXMgaW4gRVM2LCBjYWxsZWQgbGV0IHNjb3BpbmcuXG5sZXQgc29ja2V0O1xuXG4vL1RoaXMgZnVuY3Rpb24gY29ubmVjdHMgdG8gdGhlIHdlYiBzb2NrZXRzIHNlcnZlci5cbmZ1bmN0aW9uIGluaXQodXJsKSB7XG4gICAgc29ja2V0ID0gbmV3IFdlYlNvY2tldCh1cmwpXG4gICAgY29uc29sZS5sb2coJ2Nvbm5lY3RpbmcuLi4nKVxufVxuXG4vL1RoZXNlIGFyZSBhcnJvdyBmdW5jaXRpb25zIG9yIHNob3J0aGFuZCBmb3IgYW5vbnltb3VzIGZ1bmN0aW9ucy5cbmZ1bmN0aW9uIHJlZ2lzdGVyT3BlbkhhbmRsZXIoaGFuZGxlckZ1bmN0aW9uKSB7XG4gICAgc29ja2V0Lm9ub3BlbiA9ICgpID0+IHtcbiAgICAgICAgY29uc29sZS5sb2coJ29wZW4nKVxuICAgICAgICBoYW5kbGVyRnVuY3Rpb24oKTtcbiAgICB9O1xufVxuXG4vL2Z1bmN0aW9uIHRvIGhhbmRsZSBtZXNzYWdlcyB0aGF0IGNvbWUgaW4gb3ZlciB0aGUgd2ViIHNvY2tldHMgY29ubmVjdGlvbi5cbmZ1bmN0aW9uIHJlZ2lzdGVyTWVzc2FnZUhhbmRsZXIoaGFuZGxlckZ1bmN0aW9uKSB7XG4gICAgc29ja2V0Lm9ubWVzc2FnZSA9IChlKSA9PiB7XG4gICAgICAgIGNvbnNvbGUubG9nKCdtZXNzYWdlJywgZS5kYXRhKVxuICAgICAgICBsZXQgZGF0YSA9IEpTT04ucGFyc2UoZS5kYXRhKVxuICAgICAgICBoYW5kbGVyRnVuY3Rpb24oZGF0YSlcbiAgICB9XG59XG5cbmZ1bmN0aW9uIHNlbmRNZXNzYWdlKHBheWxvYWQpIHtcbiAgICBzb2NrZXQuc2VuZChKU09OLnN0cmluZ2lmeShwYXlsb2FkKSlcbn1cblxuLy9UaGlzIGZlYXR1cmUgb2YgRVM2IHRvIG5vdCBzcGVjaWZ5IHRoZSBwcm9wZXJ0eSBuYW1lIGlzIGNhbGxlZCBlbmhhbmNlZCBvYmplY3QgbGl0ZXJhbFxuZXhwb3J0IGRlZmF1bHQge1xuICAgIGluaXQsXG4gICAgcmVnaXN0ZXJPcGVuSGFuZGxlcixcbiAgICByZWdpc3Rlck1lc3NhZ2VIYW5kbGVyLFxuICAgIHNlbmRNZXNzYWdlXG59XG5cblxuIl19
