/*
*******************************************************************************
* Copyright (c) 2021 by M5Stack
*                  Equipped with M5StickC-Plus sample source code
*                          配套  M5StickC-Plus 示例源代码
* Visit the website for more information：https://docs.m5stack.com/en/core/m5stickc_plus
* 获取更多资料请访问：https://docs.m5stack.com/zh_CN/core/m5stickc_plus
*
* describe：WIFI Multi.  多wifi择优
* date：2021/9/18
*******************************************************************************
 *  Connect to the best AP based on a given wifi list
 *  根据给定wifi的列表连接到最好的AP
 */

#include <M5StickCPlus.h>
#include <WiFi.h>
#include <WiFiMulti.h>

WiFiMulti wifiMulti;

void setup()
{
  M5.begin();
  M5.Lcd.setRotation(3);  //Rotate the screen.  旋转屏幕
  wifiMulti.addAP("wifi1", "213123");  //Storage wifi configuration information 1.  存储wifi配置信息1
  wifiMulti.addAP("M5wifi", "213431241234");
  wifiMulti.addAP("aaa", "sadf");
  M5.Lcd.print("Connecting Wifi..."); //Serial port format output string.  串口格式化输出字符串
}

void loop()
{
  if(wifiMulti.run() == WL_CONNECTED) { //If the connection to wifi is established successfully.  如果与wifi成功建立连接
    M5.lcd.setCursor(0,20);
    M5.lcd.print("WiFi connected\n\nSSID:");
    M5.lcd.println(WiFi.SSID());  //Output Network name.  输出网络名称
    M5.lcd.print("RSSI: ");
    M5.lcd.println(WiFi.RSSI());  //Output signal strength.  输出信号强度
    M5.lcd.print("IP address: ");
    M5.lcd.println(WiFi.localIP()); //Output IP Address.  输出IP地址
    delay(1000);
    M5.lcd.fillRect(0,20,180,300,BLACK);  //It's equivalent to partial screen clearance.  相当于部分清屏
  }else{
    //If the connection to wifi is not established successfully.  如果没有与wifi成功建立连接
    M5.lcd.print(".");
    delay(1000);
  }
}