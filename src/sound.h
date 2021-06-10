//项目六 报警器
#include "Arduino.h"

float sinVal;
int toneVal;
int pin = 10;
int ledPin = 8;

void setup() {
    pinMode(pin, OUTPUT);
    pinMode(ledPin, OUTPUT);
}

void loop() {
//    for (int x = 0; x < 180; x++) {
    int x = int(random(60));
    //将sin函数角度转化为弧度
    sinVal = float(sin(x * (PI / 180)));
    //用sin函数值产生声音的频率
    toneVal = 2000 + (int(sinVal * 1000));
    //给引脚8一个
    tone(pin, toneVal);
    analogWrite(ledPin, toneVal);
    int d;
    if (random(3) == 1) {
        d = 300;
    } else {
        d = 200;
    }
    delay(d);
    noTone(pin);
    delay(d);
//    }
}