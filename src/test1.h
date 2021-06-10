//
// Created by peng on 5/26/21.
//

#include "Arduino.h"

int ledPin = 10;
int button = 8;

void SETUP() {
    pinMode(ledPin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(button, INPUT);
    digitalWrite(ledPin, LOW);
}

int ledPinSwitch = LOW;

void change() {
    ledPinSwitch = !ledPinSwitch;
    digitalWrite(LED_BUILTIN,HIGH);
    delay(600);
    digitalWrite(LED_BUILTIN,LOW);
}

int lock = 0;

void LOOP() {
    int flag = digitalRead(button);
    if (flag == HIGH) {
        if (lock == 0) {
            change();
        }
        lock = 1;
        //        digit''/alWrite(ledPin, HIGH);
//        delay(500);
//        delay(500);
    } else {
        lock = 0;
//        change();
//        digitalWrite(ledPin, LOW);
//        digitalWrite(ledPin, HIGH);
//        delay(50);
//        digitalWrite(ledPin, LOW);
//        delay(50);
    }
    if (ledPinSwitch) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
    }else{
//        digitalWrite(ledPin, LOW);
    }
    printf("%s", reinterpret_cast<const char *>(flag));

}

