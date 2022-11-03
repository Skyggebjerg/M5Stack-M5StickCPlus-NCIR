/*
    Description:
    Use UNIT PoESP32 to create HTTP request
    UNIT PoESP32 Connect to M5StickCPlus PORT-A (G32/33)
    before compiling:
    M5StickCPlus: https://github.com/m5stack/M5StickC
    M5GFX: https://github.com/m5stack/M5GFX
    UNIT_PoESP32: https://github.com/m5stack/UNIT_PoESP32
*/

#include "UNIT_PoESP32.h"
#include "M5GFX.h"
#include "M5StickCPlus.h"

UNIT_PoESP32 eth;
String readstr;

M5GFX display;
M5Canvas canvas(&display);

void setup() {
    M5.begin();
    display.begin();
    display.setRotation(1);
    canvas.setColorDepth(1);  // mono color
    canvas.setPaletteColor(1, GREEN);
    canvas.createSprite(display.width(), display.height());
    canvas.setTextScroll(true);
    eth.Init(&Serial2, 9600, 33, 32);
    delay(10);
    canvas.println("wait device connect");
    canvas.pushSprite(0, 0);
    while (!eth.checkDeviceConnect()) {
        delay(10);
    }

    canvas.println("device connected");
    canvas.println("wait ethernet connect");
    canvas.pushSprite(0, 0);
    while (!eth.checkETHConnect()) {
        delay(10);
    }
    canvas.println("ethernet connected");
    canvas.pushSprite(0, 0);

    readstr = eth.createHTTPClient(HEAD, APPLICATION_X_WWW_FORM_URLENCODED,
                                   "http://httpbin.org/get");
    Serial.println(readstr);
    canvas.println(readstr);
    canvas.pushSprite(0, 0);

    readstr = eth.createHTTPClient(GET, APPLICATION_X_WWW_FORM_URLENCODED,
                                   "http://httpbin.org/get");
    Serial.println(readstr);
    canvas.println(readstr);
    canvas.pushSprite(0, 0);

    readstr = eth.createHTTPClient(POST, APPLICATION_X_WWW_FORM_URLENCODED,
                                   "http://httpbin.org/post",
                                   "field1=value1&field2=value2");
    Serial.println(readstr);
    canvas.println(readstr);
    canvas.pushSprite(0, 0);

    readstr = eth.createHTTPClient(PUT, APPLICATION_X_WWW_FORM_URLENCODED,
                                   "http://httpbin.org/put");
    Serial.println(readstr);
    canvas.println(readstr);
    canvas.pushSprite(0, 0);

    readstr = eth.createHTTPClient(DELETE, APPLICATION_X_WWW_FORM_URLENCODED,
                                   "http://httpbin.org/delete");
    Serial.println(readstr);
    canvas.println(readstr);
    canvas.pushSprite(0, 0);
}

void loop() {
    if (Serial.available()) {
        char ch = Serial.read();
        Serial2.write(ch);
    }
    if (Serial2.available()) {
        char ch = Serial2.read();
        Serial.write(ch);
    }
}