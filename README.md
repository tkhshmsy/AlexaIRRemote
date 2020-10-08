# AlexaIRRemote
IR Remote Controller for use via Alexa with M5StickC/ESP32

## What's this
This device behaves as an infrared remote controller for Toshiba REGZA TV.
It is able to be operated with the Alexa voice assistant.

It's recognized by Alexa as a 'Philips Hue' lighting device,
You can select the command to send to the TV by setting the brightness.

In this code, it is set as follow.

|brightness(%)|REGZA command|
|-------------|-------------|
|1| Power|
|2| InputSelect|
|5| Sound Volume Up|
|6| Sound Volume Up|
|8| Sound Volume Down|
|9| Sound Volume Down|
|11| Channel 1|
|12| Channel 2|
|14| Channel 4|
|15| Channel 5|
|16| Channel 6|
|17| Channel 7|
|18| Channel 8|
|19| Channel 9|

## Requires
this project is for platformio.

- devices
  - M5StickC
  - physical Alexa device on your network
    - (e.g.) Echo 3nd Generation
- libraries
  - M5Stick-C
    - https://github.com/m5stack/M5StickC
  - IRRemoteESP8266
    - https://github.com/crankyoldgit/IRremoteESP8266
  - Espalexa
    - https://github.com/Aircoookie/Espalexa

## Author
tkhshmsy@gmail.com