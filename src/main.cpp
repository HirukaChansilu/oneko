#include <Arduino.h>
#include "oneko.h"

Oneko oneko = Oneko();

void setup()
{
  Serial.begin(9600);

  oneko.init();
}

void loop()
{
  // oneko.scratch_ears();
  // oneko.sleep();
  // oneko.face(32);
  // oneko.go_to_sleep();
  // oneko.move(2);
  oneko.wave();
}
