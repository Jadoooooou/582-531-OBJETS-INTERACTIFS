#include <Arduino.h>
#include <FastLED.h>

#define MA_BROCHE_ANGLE 32

CRGB monPixel;

void setup() {
  Serial.begin(115200);
  delay(5000);
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);
  monPixel = CRGB(255, 0, 0);
}

void loop() {

  int maLectureAnalogique;
  maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);

  Serial.print(maLectureAnalogique);
  Serial.println();
  delay(100);

  // Exercice 1
  // if (maLectureAnalogique > 2000) {
    // monPixel = CRGB(255, 0, 0);
    // FastLED.show();
  // } else if (maLectureAnalogique < 2000) {
    // FastLED.clear(true);
    // monPixel = CRGB(0, 0, 0);
    // FastLED.show();
  // }

  int result ( (maLectureAnalogique*255) / 4095);
  monPixel = CRGB(result, 0, 0);
  FastLED.show();
}
