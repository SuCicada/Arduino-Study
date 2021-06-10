#include "Arduino.h"

//项目四 – 呼吸灯
int ledPin = 10;

void fadeOn(unsigned int time, int increament) {
    for (byte value = 0; value <= 255; value += increament) {
        analogWrite(ledPin, value);
        delay(time / (255 / increament));
    }
}

void fadeOff(unsigned int time, int decreament) {
    for (byte value = 255; value >= 0; value -= decreament) {
        analogWrite(ledPin, value);
        delay(time / (255 / decreament));
    }
}

void setup() {
    pinMode(ledPin, OUTPUT);
}

void loop() {
    int f = (int) random(255);
    analogWrite(ledPin, f);
//    fadeOn(1000, 5);
//    delay(100);
//    fadeOff(1000, 5);
//    random()
    //    delay(100);
}