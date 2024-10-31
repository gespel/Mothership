#include <Arduino.h>
#include "slang.h"

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  Slang s(48000);
  s.tokenize("sinesynth(220); sinesynth(440);");
  s.printTokens();
  s.interpret();
}

void loop() {
}
