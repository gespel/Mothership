#include <Arduino.h>
#include "slang/slang.h"

Slang s(48000);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  s.tokenize("sinesynth(220); sinesynth(440); sinesynth(7000);");
  s.interpret();

}

void loop() {
  s.printTokens();
  for(auto s : s.getSineSynths()) {
    Serial.println(s->getSample());
  }
  sleep(3);
}
