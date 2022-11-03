/*
*******************************************************************************
* Copyright (c) 2022 by M5Stack
*                  Equipped with M5StickC Plus sample source code
*                          配套  M5StickC Plus 示例源代码
* Visit the website for more information:
* 获取更多资料请访问:
*
* describe: Limit.
* date: 2022/6/1
*******************************************************************************
*/

#include <M5StickCPlus.h>

#define KEY_PIN 33  // Define Limit Pin.  定义Limit连接引脚

void setup() {
    M5.begin();  // Init M5Stack  初始化M5Stack
    M5.Lcd.setCursor(0, 25, 2);
    M5.Lcd.print((" UNIT-LIMIT\n   Example\n\n"));

    pinMode(KEY_PIN, INPUT_PULLUP);  // Init Limit pin.  初始化Limit引脚.
}

void loop() {
    if (!digitalRead(KEY_PIN)) {  // If Limit was hit.  如果触碰了Limit.
        M5.Lcd.setCursor(0, 100);
        M5.Lcd.print(("  Hit limit!"));
    } else {
        M5.Lcd.setCursor(0, 100);
        M5.Lcd.println(("            "));
    }
    delay(100);
}
