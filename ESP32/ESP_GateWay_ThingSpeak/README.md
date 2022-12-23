# ESP32 | Gateway | ThingSpeak

In this module, DHTxx sensor is interfaced with ESP32 and ESP32 is connected to Gateway via serial port[UART]. 

Gateway code is written in nodeJs and can be implemented on any device which supports nodeJs.[Desktop/RPI]

ThingSpeak is used as an IoT platform.

--------------------------------------------------------------------------------

Implementation and testing is done on __Ubuntu__ device.

---------------------------------------------------------------------------------

<h2>Do the needful changes as per your configuration</h2>

For successful compilation of please run following commands:

        npm init --yes

----------------------------------------------------------------------------------

<h2>DHT11.ino</h2>

* DHTxx sensor
* BAUDRATE
* Install '__Adafruit DHT__' library.

----------------------------------------------------------------------------------
<h2>client.js</h2>

* Change URL
* Change Request body[API key, Fields]
* Install axios

        npm install axios

---------------------------------------------------------------------------------

<h2>esp32.js</h2>

* PORT
* BAUDRATE

-----------------------------------------------------------------------------------

__Steps to 'Run a program' after all the changes has been done:__

* Do the changes required.
* Compile and Upload __.ino__ file on ESP board.
* Initialize node
* Run 'client.js'

        sudo node ./client.js

* Monitor console.
* Login to ThingSpeak and verify data.

----------------------------------------------------------------------------------

&copy; 2022, Rohit Akurdekar&trade;