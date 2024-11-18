#include <Arduino.h>
#include "slang/slang.h"
#include "slang/tokenizer.h"


Tokenizer t;
Slang s(48000, t.tokenize("sinesynth(220); sinesynth(440); fn test { sten lina } sinesynth(7000); sawtoothsynth(200); fn asd { x y } fn asda { x y }"));

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
}

void loop() {
    s.interpret();
    s.printDebug();
    
    sleep(3);
    s.clear();
}


