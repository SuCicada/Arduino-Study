#include "Arduino.h"

void setup() {
// initialize the serial communication:
    Serial.begin(9600);
    pinMode(9, OUTPUT); // Led
    pinMode(10, INPUT); // Setup for leads off detection LO +
    pinMode(11, INPUT); // Setup for leads off detection LO -
    pinMode(LED_BUILTIN, OUTPUT); // Setup for leads off detection LO -
}

/*
观察的结果：
 平静心跳:  0 - 350
 工作心跳:  330 - 370

 */
int heart = 0;
int lastHeart = 0;
int lastSubtract = 0;

void light() {
//    if (lightLoop++ == 1000 / 20) {
//        lightLoop = 0;
//        int max = 600, min = 300;
//        int blink = int((heart + 0.0 - min) / (max - min) * 255);
//        Serial.println(blink);

//    analogWrite(9,0);
//    }
}

int noBlinkNum = 0;
int blinkNum = 0;
int loopNum = 0;
int blinkFlags[] = {10, 20, 30, 40, 50, 100};
int blinkFlag = 30;
int blinkFlagIndex = 2;

void changeBlinkFlag(int level) {
    int maxIndex = sizeof(blinkFlags) / sizeof(int);
    int newIndex = blinkFlagIndex + level;
    int index;
    if (newIndex < 0 || newIndex > maxIndex) {
        index = random(0, maxIndex);
    } else {
        index = newIndex;
    }
    blinkFlag = blinkFlags[index];
    blinkFlagIndex = index;
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
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
    int blink;
//    int blink = int((heart + 0.0 - min) / (max - min) * 255);
    int subtract;
    subtract=heart- lastHeart ;
    subtract = lastHeart -heart ;
    blink = subtract;
    double rate = subtract * 1.0 / lastSubtract;
    rate = abs(rate);
    lastSubtract = subtract;
//    blink = blink < 0 ? 0 : blink;
    blink = blink < blinkFlag ? (blink < 0 ? 0 : 0) : 255;
    if (blink != 255) {
        blinkNum = 0;
        noBlinkNum++;
        if (noBlinkNum >= 5000 / 20) {
//            changeBlinkFlag(-1);
        }
    } else {
        noBlinkNum = 0;
        blinkNum++;
        if (loopNum >= 5000 / 20) {
            loopNum = 0;
            if (blinkNum > 10) {
//                changeBlinkFlag(1);
            }
        }
    }
    loopNum++;
    //    blink = rate > 3?255:0;
    blink = subtract;
    blink = subtract < 50 ? 0 : 255;
    Serial.println(subtract);
    //    blink=255;
    analogWrite(9, blink);
//    analogWrite(9, heart);
    delay(20);
}
