# particle-servo-control

This is firmware that lets a Spark Core (from http://particle.io) control a single servo, along with source code for two apps to interact with that firmware remotely, over the internet.

So far, this code has powered these two robotics projects:

- https://www.youtube.com/watch?v=vaxy4inpFsQ
- https://www.youtube.com/watch?v=hKDVSJ7b8DQ


## The Files

### servo-control.ino

The firmware for the Spark Core.  By default, the connected servo will go to a
new random position every 200-1000ms.

### web_servo_controller.html

A simple web page that uses JQuery to send commands to the Spark Core

### pebble_servo_controller.js

A simple Pebble.js app for CloudPebble that will allow you to control the servo
using your Pebble Smartwatch.  It has been tested on the original Pebble -- if
it works on other versions, consider that a nice bonus!
