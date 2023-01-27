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
    void animate(int frame1, int frame2, int frame_duration);

public:
    void init();
    bool continue_with_error(int warning_duration = 5000);
    void not_oriented(int frame_duration = 100);
    void face(int face);
    void scratch_ears(int frame_duration = 75);
    void sleep(int frame_duration = 400);
    void go_to_sleep(int yawn_duration = 1200, int scratch_ears_duration = 4000);
    void move(int direction, int frame_duration = 100);
    void wave(int frame_duration = 400);
};

#endif