#include <Arduino.h>
#include "slang.h"

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
  Slang s;
  s.tokenize("fn test a 23 ( ) { } ;");
  s.printTokens();
}

void loop() {
}
