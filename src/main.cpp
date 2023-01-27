#include <Arduino.h>
#include "oneko.h"
#include "ac.h"

Oneko oneko = Oneko();
Accelerometer accelerometer = Accelerometer();

void setup()
{
  Serial.begin(9600);

  delay(100);

  oneko.init();
  accelerometer.init();
}

void loop()
{
  if (oneko.continue_with_error())
  {
    if (accelerometer.check_orientation())
    {
      oneko.move(accelerometer.get_direction());
    }
    else
    {
      Serial.println("Not in orientation");
    }
  }
}