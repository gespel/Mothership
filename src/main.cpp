#include <Arduino.h>
#include "slang/slang.h"
#include "slang/tokenizer.h"


Tokenizer t;
Slang s(48000);

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
}

void loop() {
    s.interpret(t.tokenize("sinesynth(220); sinesynth(440); fn test { sawtoothsynth(123); } test; test; test;"));
    s.printDebug();
    
    sleep(3);
    s.clear();
}


