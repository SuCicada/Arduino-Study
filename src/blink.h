//
// Created by Administrator on 2021/6/11.
//
#include "Arduino.h"

int pin10 = 10;
int pin11 = 11;

void setup() {
    // initialize digital pin LED_BUILTIN as an output.
    pinMode(LED_BUILTIN, OUTPUT);
//    pinMode(pin10, OUTPUT);
//    pinMode(pin11, OUTPUT);
    Serial.begin(9600);
    pinMode(9, OUTPUT);
}

// the loop function runs over and over again forever
int d = 300;

void test1() {
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(pin10, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(pin11, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(d);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(pin10, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(pin11, LOW);    // turn the LED off by making the voltage LOW
    delay(d);                       // wait for a second
    Serial.println(d);
}

void loop() {
    int f = (int) random(255);
    analogWrite(9, f);
    Serial.println(f);
    delay(300);

}
