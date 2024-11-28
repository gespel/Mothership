#include <Arduino.h>
#include "microslang/microslang.h"
#include "microslang/tokenizer.h"
#include "bluetooth.h"

//Bluetooth bt;
Tokenizer t;
MicroSlang s(48000);
BluetoothSerial SerialBT;
String currentProgramm = "sinesynth(220); sinesynth(440); fn test { sawtoothsynth(123); } test; test; test;";

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    SerialBT.begin("Stenni liebt Lina");
}

void loop() {
    s.interpret(t.tokenize(currentProgramm));
    s.printDebug();
    if(SerialBT.available()) {
        Serial.println("============= Detected new Slang script! =============");
        String rcv = "";
        rcv = rcv + (char)SerialBT.read();
        while(SerialBT.available()) {
            rcv = rcv + (char)SerialBT.read();
        }
        Serial.println(rcv);
        SerialBT.println("Thanks for the new program. Nom nom...");
        currentProgramm = rcv;
    }
    sleep(1);
    s.clear();
}


