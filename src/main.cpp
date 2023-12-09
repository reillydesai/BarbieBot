#include <Arduino.h>
#include "Behaviors.h"

Behaviors Barbie;

void setup() {
  Barbie.Init();
}

void loop() {
  Barbie.Run();
}