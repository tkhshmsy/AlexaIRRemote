#include <Arduino.h>
#include <M5StickC.h>
#include <Espalexa.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "ir_regza.h"

#define SSID "" // set your WiFi SSID
#define SSID_PASSPHRASE "" // set your WiFi Passphrase
#define ALEXA_DEVICE_NAME "AlexaIRRemote" // Device name for Alexa

Espalexa alexaDevice;
IRsend irsend(9);
IRRegza irRegza(&irsend);

void callback(uint8_t brightness, uint8_t rgb);

void setup() {
    Serial.begin(115200);
    M5.begin();

    M5.Lcd.setRotation(1);
    M5.Lcd.setTextFont(2);
    M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0, 0);

    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID, SSID_PASSPHRASE);

    M5.Lcd.print("connecting");
    while(WiFi.status() != WL_CONNECTED) {
        Serial.print('.');
        delay(3000);
    }
    Serial.print("connected\n");
    M5.Lcd.setCursor(0, 0);
    M5.Lcd.print(WiFi.localIP());

    irsend.begin();
    alexaDevice.addDevice(ALEXA_DEVICE_NAME,
                            callback);
    alexaDevice.begin();
}

void loop() {
    alexaDevice.loop();
    delay(1);
}

void callback(uint8_t brightness, uint8_t rgb)
{
    int data = alexaDevice.toPercent(brightness);
    Serial.printf("CallBack b(%d)->d(%d) rgb(%d)\n", brightness, data, rgb);
    M5.Lcd.setCursor(0, 16);
    M5.Lcd.printf("%02x %03d %02x", brightness, data, rgb);

    int count = 3;
    IRRegza::Command command = IRRegza::Command::Invalid;
    switch(data) {
    case 1:
        command = IRRegza::Command::Power;
        break;
    case 2:
        count = 1;
        command = IRRegza::Command::InputSelect;
        break;
    case 5:
        count = 1;
    case 6:
        command = IRRegza::Command::VolumeUp;
        break;
    case 8:
        count = 1;
    case 9:
        command = IRRegza::Command::VolumeDown;
        break;
    case 11:
        // NHK
        command = IRRegza::Command::Channel1;
        break;
    case 12:
        // NHK-ETV
        command = IRRegza::Command::Channel2;
        break;
    case 14:
        // NTV(AX)
        command = IRRegza::Command::Channel4;
        break;
    case 15:
        // Asahi(EX)
        command = IRRegza::Command::Channel5;
        break;
    case 16:
        // TBS(TBS)
        command = IRRegza::Command::Channel6;
        break;
    case 17:
        // TVTokyo(TX)
        command = IRRegza::Command::Channel7;
        break;
    case 18:
        // Fuji(CX)
        command = IRRegza::Command::Channel8;
        break;
    case 19:
        // TokyoMX(MX)
        command = IRRegza::Command::Channel9;
        break;
    default:
        break;
    }
    M5.Lcd.setCursor(0, 32);
    M5.Lcd.printf("%12s", irRegza.toString(command).c_str());
    if (command != IRRegza::Command::Invalid) {
        for (int i = 0; i < count; i++) {
            irRegza.send(command);
            delay(10);
        }
    }
}