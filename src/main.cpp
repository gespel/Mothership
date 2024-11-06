#include <Arduino.h>
#include "slang.h"

Slang s(48000);

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  s.tokenize("sinesynth(220); sinesynth(440);");
}

void loop() {
  s.interpret();
  s.printTokens();
  sleep(3);
}
