#ifndef ONEKO
#define ONEKO

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1    // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C

class Oneko
{
private:
    Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
    bool is_moving;
    bool new_sleep = true;
    void animate(int frame1,
                 int frame2,
                 int frame_duration);

public:
    void init();
    bool continue_with_error(int warning_duration = 5000);
    void not_oriented(int frame_duration = 100);
    void face(int face);
    void scratch_ears(int frame_duration = 75);
    void sleep(int frame_duration = 400);
    void stay(
        long avg_wave_duration = 5000,
        long avg_sleep_duration = 60000,
        long wave_duration_offset = 2000,
        long sleep_duration_offset = 30000,
        long avg_wave_frequency = 60000,
        long avg_sleep_frequency = 30000,
        long wave_frequency_offset = 10000,
        long sleep_frequency_offset = 20000);
    void go_to_sleep(int yawn_duration = 1200,
                     int scratch_ears_duration = 3550);
    void move(int direction, int frame_duration = 100);
    void wave(int frame_duration = 200);
};

#endif