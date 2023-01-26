#include <Arduino.h>
// #include "oneko.h"
#include "ac.h"

// Oneko oneko = Oneko();
Accelerometer accelerometer = Accelerometer();

void setup()
{
  Serial.begin(9600);

  delay(100);

  // oneko.init();
  accelerometer.init();
}

void loop()
{
  // oneko.scratch_ears();
  // oneko.sleep();
  // oneko.face(32);
  // oneko.go_to_sleep();
  // oneko.move(2);
  // oneko.wave();
  if (accelerometer.check_orientation())
  {
    // Serial.print("Direction: ");
    // Serial.println(accelerometer.get_direction());
  }
  else
  {
    Serial.println("Not in orientation");
  }
}