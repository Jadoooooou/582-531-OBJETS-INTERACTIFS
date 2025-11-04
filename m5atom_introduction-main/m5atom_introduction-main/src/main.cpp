#include <Arduino.h>

#include <FastLED.h>
CRGB monPixel;

void setup()
{
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);
  monPixel = CRGB(255, 0, 0);
  FastLED.show();
}

void loop()
{
  monPixel = CRGB(255, 0, 0);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(213, 0, 255);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(60, 0, 255);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(0, 255, 247);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(85, 255, 0);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(213, 0, 255);
  FastLED.show();
  delay(1000);

  monPixel = CRGB(255, 255, 0);
  FastLED.show();
  delay(1000);
}