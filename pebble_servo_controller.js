// Pebble.js app

var UI = require('ui');
var ajax = require('ajax');
var particleDeviceId = 'YOUR_DEVICE_ID_HERE';
var particleAccessToken = 'YOUR_ACCESS_TOKEN_HERE';
var urlPrefix = 'https://api.spark.io/v1/devices/'+particleDeviceId+'/';

var main = new UI.Card({
  title: 'Servo App',
  icon: 'images/menu_icon.png',
  subtitle: 'Push a Button!',
  body: 'Click Up, Down, or Select to set servo position. Long-click Select for random mode.'
});

var particleCall = function(method, param) {
  var URL = urlPrefix + method;
  var data = {access_token: particleAccessToken};
  if (param) {
    data.params = param;
  }
  ajax({
      //type: 'json',
      url: URL,
      method: 'post',
      data: data
    },
       
    function(json) {
      console.log("Success");
    },
       
    function(error) {
      console.log("Error");
    }
  );
};

var lookCenter = function() {
  particleCall('setpos', '90');
};

var lookLeft = function() {
  particleCall('setpos', '30');
};

var lookRight = function() {
  particleCall('setpos', '150');
};

var toggleRandom = function() {
  particleCall('crazy');
};


main.show();

main.on('click', 'up', function(e) {
  lookLeft();
});

main.on('click', 'select', function(e) {
  lookCenter();
});

main.on('longClick', 'select', function(e) {
  toggleRandom();
});

main.on('click', 'down', function(e) {
  lookRight();
});


