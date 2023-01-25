#include <Arduino.h>
#include "oneko.h"

Oneko oneko = Oneko();

void setup()
{
  Serial.begin(9600);

  oneko.init();
  oneko.face(26);
}

void loop()
{
}
