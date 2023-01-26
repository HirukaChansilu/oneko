#include "ac.h"

#define G_SLIDE_VALUE 7.00
#define SLIDE_VALUE 1.50

void Accelerometer::init()
{
    // Try to initialize!
    if (!mpu.begin())
    {
        Serial.println("Failed to find MPU6050 chip");
        for (;;)
            ;
    }
    Serial.println("MPU6050 Found!");

    mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

bool Accelerometer::check_orientation()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    return (a.acceleration.z >= G_SLIDE_VALUE || a.acceleration.x <= -G_SLIDE_VALUE);
}

bool Accelerometer::is_vertical()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    return (a.acceleration.z >= G_SLIDE_VALUE);
}

int Accelerometer::get_direction()
{
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);

    if (is_vertical())
    {
        if (a.acceleration.x >= SLIDE_VALUE && a.acceleration.y <= -SLIDE_VALUE)
        {
            return 2;
        }
        else if (a.acceleration.x <= -SLIDE_VALUE && a.acceleration.y <= -SLIDE_VALUE)
        {
            return 4;
        }
        else if (a.acceleration.x <= -SLIDE_VALUE && a.acceleration.y >= SLIDE_VALUE)
        {
            return 6;
        }
        else if (a.acceleration.x >= SLIDE_VALUE && a.acceleration.y >= SLIDE_VALUE)
        {
            return 8;
        }
        else if (a.acceleration.x >= SLIDE_VALUE)
        {
            return 1;
        }
        else if (a.acceleration.y <= -SLIDE_VALUE)
        {
            return 3;
        }
        else if (a.acceleration.x <= -SLIDE_VALUE)
        {
            return 5;
        }
        else if (a.acceleration.y >= SLIDE_VALUE)
        {
            return 7;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        if (a.acceleration.y <= -SLIDE_VALUE && a.acceleration.z >= SLIDE_VALUE)
        {
            return 2;
        }
        else if (a.acceleration.z <= -SLIDE_VALUE && a.acceleration.y <= -SLIDE_VALUE)
        {
            return 4;
        }
        else if (a.acceleration.y >= SLIDE_VALUE && a.acceleration.z <= -SLIDE_VALUE)
        {
            return 6;
        }
        else if (a.acceleration.z >= SLIDE_VALUE && a.acceleration.y >= SLIDE_VALUE)
        {
            return 8;
        }
        else if (a.acceleration.z >= SLIDE_VALUE)
        {
            return 1;
        }
        else if (a.acceleration.y <= -SLIDE_VALUE)
        {
            return 3;
        }
        else if (a.acceleration.z <= -SLIDE_VALUE)
        {
            return 5;
        }
        else if (a.acceleration.y >= SLIDE_VALUE)
        {
            return 7;
        }
        else
        {
            return 0;
        }
    }
}