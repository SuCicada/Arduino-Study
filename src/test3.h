#include "Arduino.h"

//项目五 – 炫彩RGB灯
int redPin = 9;
int greenPin = 10;
int bluePin = 11;

const int OUTPUT_PIN[] = {redPin, greenPin, bluePin, LED_BUILTIN};

void setup() {
    for (int i = 0; i < sizeof(OUTPUT_PIN) / sizeof(int); i++) {
        pinMode(OUTPUT_PIN[i], OUTPUT);
        analogWrite(OUTPUT_PIN[i], 255);
    }
}

void debug() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(600);
    digitalWrite(LED_BUILTIN, LOW);
    delay(600);
}

void fade(int pin, int low, int high, int step, int mode, int delayTime) {
//    for (int j = 1; j == -1 || j == 1; j -= 2) {
//    int j = constrain(mode, -1, 1);
    int j = mode;
    for (int i = (j == 1 ? low : high);
         (j == 1 ? (i <= high) : (i >= low));
        //         i != (j == 1 ? high + step : low - step);
         i += (j * step)) {
        analogWrite(pin, i);
        delay(delayTime);
    }
//    }
}

void colorRGB(int red, int green, int blue) {
    int step = 1;
//    int d = 1000 / (red / step);
    int d = 5;
    int high = 255;
    for (int i = 1; i == -1 || i == 1; i -= 2) {
        fade(redPin, red, high, step, i, d);
        fade(greenPin, green, high, step, i, d);
        fade(bluePin, blue, high, step, i, d);
        debug();
    }
    //    analogWrite(redPin, constrain(red, 0, 255));
//    analogWrite(greenPin, co
//    nstrain(green, 0, 255));
//    analogWrite(bluePin, constrain(blue, 0, 255));
}

void fade1(int pin, int high, int mode) {
    fade(pin, 0, high, 1, mode, 10);
}

int first = 1;

void loop() {
    //R:0-255 G:0-255 B:0-255
    if (first == 1) {
//        int red = random(0, 255);
//        int red = 255;
        colorRGB(random(0, 255), random(0, 255), random(0, 255));
//        fade1(redPin, red, -1);
//        fade1(redPin, red, 1);

//        first = 0;
    }
//    debug();
}
