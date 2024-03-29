#include "Arduino.h"

// 定义 LED 引脚
const int ledPin = LED_BUILTIN;

void setup() {
    // 将 LED 引脚设置为输出模式
    pinMode(ledPin, OUTPUT);
//    pinMode(7, OUTPUT);
    for (int i = 2; i < 10; i++) {
        pinMode(i, INPUT_PULLUP);
    }
}

void loop() {
    int val1 = digitalRead(7);

    if (val1 == 1) {
        // 将 LED 置为高电平（点亮）
        digitalWrite(ledPin, HIGH);
//        delay(300);
    } else {
        digitalWrite(ledPin, LOW);
    }
//    delay(300);
    // 延时一段时间
//    delay(1000);
}
