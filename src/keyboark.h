#include <Arduino.h>
//#include <USBKeyboard.h>
#include <Keyboard.h>

int val1;

void setup() {
    // put your setup code here, to run once:
//    Keyboard.init();
    Keyboard.begin();
//    Keyboard.print("space");

    for (int i = 2; i < 10; i++) {
        pinMode(i, INPUT_PULLUP);
    }
}

void loop() {
    // put your main code here, to run repeatedly:
    val1 = digitalRead(7);

    if (val1 ==1) {
        Keyboard.press(KEY_UP_ARROW);
//    Keyboard.print("space");
//        Keyboard.sendKeyStroke(KEY_SPACE, 0);
        delay(100);
    }else{
        Keyboard.release(KEY_UP_ARROW);
        delay(100);
    }
}
