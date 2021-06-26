#include "Arduino.h"

void setup() {
// initialize the serial communication:
    Serial.begin(9600);
    pinMode(9, OUTPUT); // Led
    pinMode(10, INPUT); // Setup for leads off detection LO +
    pinMode(11, INPUT); // Setup for leads off detection LO -
}

/*
观察的结果：
 平静心跳:  0 - 350
 工作心跳:  330 - 370

 */
int heart = 0;
int lastHeart = 0;
int lightLoop = 0;

void light() {
//    if (lightLoop++ == 1000 / 20) {
//        lightLoop = 0;
//        int max = 600, min = 300;
//        int blink = int((heart + 0.0 - min) / (max - min) * 255);
//        Serial.println(blink);

//    analogWrite(9,0);
//    }
}

void loop() {
    if ((digitalRead(10) == 1) || (digitalRead(11) == 1)) {
//        Serial.println('!');
    } else {
// send the value of analog input 0:
        lastHeart = heart;
        heart = analogRead(A0);
    }
//Wait for a bit to keep serial data from saturating
//    light();
//    int blink = heart - 200;
//    int blink = lastHeart - heart;
    int max = 600, min = 200;
    int blink = int((heart + 0.0 - min) / (max - min) * 255);
    blink = lastHeart - heart;
    blink = blink < 10 ? (blink < 0 ? 0 : 0) : 255;
    Serial.println(lastHeart - heart);
    analogWrite(9, blink);
//    analogWrite(9, heart);
    delay(20);
}
