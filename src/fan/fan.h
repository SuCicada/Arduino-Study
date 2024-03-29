#include "Arduino.h"

const int sensorPin = 6;
const int fanPin = 9;
const int buttonPin = 10;
const int fanLightPin = 11;

int fanSwitch = 0;
int buttonOnClick = 0;
void setup() {
    Serial.begin(9600);
    pinMode(fanPin, OUTPUT);
    pinMode(sensorPin, INPUT);
    pinMode(buttonPin, INPUT);
    pinMode(fanLightPin, OUTPUT);

    analogWrite(fanPin, 0);
}
void startFun() {
    analogWrite(fanPin, 255);
    digitalWrite(fanLightPin, HIGH);
    fanSwitch = 1;
    Serial.println("Fun started!!!");
}
void stopFun() {
    analogWrite(fanPin, 0);
    digitalWrite(fanLightPin, LOW);
    fanSwitch = 0;
    Serial.println("Fun stopped...");
}
void switchFun() {
    fanSwitch == 0 ? startFun() : stopFun();
}

int flag = 0;
void loop() {
    // int a = analogRead(sensorPin);
    //    Serial.println((byte) a);
    //    Serial.println("analogRead: "+String(a));

    int buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
        if (buttonOnClick == 0) {
            switchFun();
            Serial.println("buttonState clicked");
        }
        buttonOnClick = 1;
    } else {
        Serial.println("button off");
        buttonOnClick = 0;
    }

    if (Serial.available() > 0) {
        // 如果串口缓冲区中有可用数据
        String s = Serial.readString();
        //        char receivedChar = (char)Serial.read(); // 读取字符
        // 在这里可以对接收到的数据进行处理
        s.trim();
        Serial.print("Received: ");  // 发送响应消息
        Serial.println(s);
        if (s == "open" || s == "start") {
            startFun();
            Serial.println(255);
        }
        if (s == "close" || s == "stop") {
            stopFun();
            Serial.println(0);
        }
    }

    //    analogWrite(fanPin, 255);
    flag = !flag;
    flag ? Serial.println("looping...") : Serial.println("^^^^^^^ ");
    delay(500);
}
