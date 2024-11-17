#include <Arduino.h>
#include "slang/slang.h"
#include "slang/tokenizer.h"


Tokenizer t;
Slang s(48000, t.tokenize("sinesynth(220); sinesynth(440); sinesynth(7000); sawtoothsynth(200);"));

void setup() {
    Serial.begin(115200);
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    s.interpret();

}

void loop() {
    //s.printTokens();
    for(auto sy : s.getSineSynths()) {
        //Serial.println(sy->getSample());
    }
  
    sleep(3);
}

void printDebug() {
    String pre_sine = "Number of SineSynths: ";
    String pre_saw = " Number of SawtoothSynths: ";
    Serial.println(pre_sine + s.getSineSynths().size() + pre_saw + s.getSawtoothSynths().size());
}
