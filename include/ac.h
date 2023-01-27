#ifndef AC_H
#define AC_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

class Accelerometer
{
private:
    Adafruit_MPU6050 mpu;
    bool is_vertical();

public:
    bool is_init = false;
    void init();
    bool check_orientation();
    int get_direction();
};

#endif