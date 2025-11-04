#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

#define MA_BROCHE_ANGLE 32
#define MA_BROCHE_BOUTON 39
CRGB monPixel;

void setup() {
  pinMode( MA_BROCHE_BOUTON , INPUT );
  Serial.begin(115200);
  FastLED.addLeds<WS2812, 27, GRB>(&monPixel, 1);
}

void loop() {

  // oscslip_angle
  int maLectureAnalogique = analogRead(MA_BROCHE_ANGLE);
  monOsc.sendInt("/angle", maLectureAnalogique);
  delay(100);

  // couleur_pixel
  monPixel = CRGB(255, 0, 0);
  if (maLectureAnalogique < 1365) {
     monPixel = CRGB(255, 0, 0);
     FastLED.show();
   } else if (maLectureAnalogique > 2730) {
     monPixel = CRGB(0, 0, 255);
     FastLED.show();
   } else {
    monPixel = CRGB(0, 255, 0);
    FastLED.show();
  }
}