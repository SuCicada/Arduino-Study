#include "Arduino.h"
// 定义 LED 引脚
const int ledPin = LED_BUILTIN;

void setup() {
    // 将 LED 引脚设置为输出模式
    pinMode(ledPin, OUTPUT);
}

void loop() {
    // 将 LED 置为高电平（点亮）
    digitalWrite(ledPin, HIGH);
    // 延时一段时间
    delay(10);
    // 将 LED 置为低电平（熄灭）
    digitalWrite(ledPin, LOW);
    // 延时一段时间
    delay(1000);
}
