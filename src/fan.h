#include "Arduino.h"

// const byte OC1A_PIN = 9;
const byte OC1B_PIN = 10;
int SensorPin = 6;
const byte fanPin = 9;
// const word PWM_FREQ_HZ = 20000; //Adjust this value to adjust the frequency
// word TCNT1_TOP = 16000000 / (2 * PWM_FREQ_HZ); //  TCNT1_TOP = 400


// void setPwmDuty(byte duty) {
//     TCNT1_TOP = 400;
//     word a = (word) (duty * TCNT1_TOP) / 100;
// //    Serial.println("OCR1A:" + String(a));
// //    Serial.println(a);
// //    OCR1A = a;
// //    OCR1A = duty;
//     analogWrite(fanPin, duty);
// }

void setup() {
    Serial.begin(9600);
    pinMode(fanPin, OUTPUT);
    pinMode(SensorPin, INPUT);

    // Clear Timer1 control and count registers
//    TCCR1A = 0;
//    TCCR1B = 0;
//    TCNT1 = 0;

    // Set Timer1 configuration
    // COM1A(1:0) = 0b10   (Output A clear rising/set falling)
    // COM1B(1:0) = 0b00   (Output B normal operation)
    // WGM(13:10) = 0b1010 (Phase correct PWM)
    // ICNC1      = 0b0    (Input capture noise canceler disabled)
    // ICES1      = 0b0    (Input capture edge select disabled)
    // CS(12:10)  = 0b001  (Input clock select = clock/1)

//    TCCR1A |= (1 << COM1A1) | (1 << WGM11);
//    TCCR1B |= (1 << WGM13) | (1 << CS10);
//    ICR1 = TCNT1_TOP;
    analogWrite(fanPin, 0);

}
//https://www.aeq-web.com/arduino-pc-lufter-drehzahl-messen-uber-tachosignal/?lang=en
int InterruptCounter,rpm = 0;
void countup() {
    InterruptCounter++;
}
void meassure() {
    InterruptCounter = 0;
    attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
    delay(1000);
    detachInterrupt(digitalPinToInterrupt(SensorPin));
    rpm = (InterruptCounter / 2) * 60;
//    display_rpm();

    Serial.println("rmp: "+String(rpm));
}


void loop() {
//    setPwmDuty(0);
//    for (int i =1000; i < 2000; i += 200) {
//        for (int i =500; i < 1000; i += 100) {
//for(int i=0;i<255;i+=10){
//        Serial.println(i);
//        setPwmDuty(i);
//        delay(2000);
//    }
//    analogWrite(fanPin, 0);
//    Serial.println(0);
//    delay(5000);

//    setPwmDuty(0);
//    analogWrite(fanPin, 128);
//    Serial.println(128);
//    delay(5000);
//    attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
//    meassure();
    int a = analogRead(SensorPin);
//    Serial.println((byte) a);
//    Serial.println("analogRead: "+String(a));
    if (Serial.available() > 0) {
        // 如果串口缓冲区中有可用数据
        String s = Serial.readString();
//        char receivedChar = (char)Serial.read(); // 读取字符
        // 在这里可以对接收到的数据进行处理
        s.trim();
        Serial.print("Received: "); // 发送响应消息
        Serial.println(s);
        if (s == "open" || s == "start") {
            analogWrite(fanPin, 255);
            Serial.println(255);
        }
        if (s == "close" || s == "stop") {
            analogWrite(fanPin, 0);
            Serial.println(0);
        }
    }

//    analogWrite(fanPin, 255);
    delay(1000);

    // analogWrite(fanPin, 355);
    // Serial.println(355);
    // delay(5000);
//    setPwmDuty(50);
//    delay(20000);
//    setPwmDuty(75);
//    delay(20000);
//    setPwmDuty(100);
//    delay(20000);
}
