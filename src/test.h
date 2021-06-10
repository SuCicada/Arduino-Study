#include <time.h>
#include "Arduino.h"
#include "stdlib.h"


int ledPin1 = 9;
int ledPin2 = 10;
int ledPin3 = 8;

void SETUP() {
    // initialize digital pin LED_BUILTIN as an output.
//    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
}

// the loop function runs over and over again forever
int random(int min, int max) {
    static bool first = true;
    if (first) {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

void LOOP() {
//    srand(time(NULL));
    int time = 110;
    digitalWrite(ledPin1, HIGH);
    delay(time);
    digitalWrite(ledPin2, HIGH);
    delay(time);
    digitalWrite(ledPin3, HIGH);
    delay(time);
    digitalWrite(ledPin1, LOW);
    delay(time);
    digitalWrite(ledPin2, LOW);
    delay(time);
    digitalWrite(ledPin3, LOW);
    delay(time);
}
