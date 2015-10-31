# particle-servo-control

This is firmware that lets a Spark Core (from http://particle.io) control a single servo, along with source code for two apps to interact with that firmware remotely, over the internet.

So far, this code has powered these two robotics projects:

- https://www.youtube.com/watch?v=vaxy4inpFsQ
- https://www.youtube.com/watch?v=hKDVSJ7b8DQ


## The Files

### servo-control.ino

The firmware for the Spark Core.  By default, the Core will start offline and
the servo will go to a new random position every 200-1000ms.

*IMPORTANT* To go online, short out the D0 pin by connecting it to the 3v3 pin
on the Core.  It might seem obvious, but if you don't put the Core online, you
can't re-flash the firmware or communicate with it wirelessly.

### web_servo_controller.html

A simple web page that uses JQuery to send commands to the Spark Core

### pebble_servo_controller.js

A simple Pebble.js app for CloudPebble that will allow you to control the servo
using your Pebble Smartwatch.  It has been tested on the original Pebble -- if
it works on other versions, consider that a nice bonus!
