#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define BROCHE_ATOM_PIXEL 27
#define BROCHE_ATOM_ANGLE 32

// channel du hub où il est utilisé
#define KEY_CHANNEL_ANGLE 0

// CRGB keyPixel;
CRGB atomPixel;

// Tof key
#include <VL53L0X.h>
VL53L0X  myTOF;



void setup() {

  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);

  // Initialiser FastLED pour contrôler le pixel RGB du M5Atom
  FastLED.addLeds<WS2812, BROCHE_ATOM_PIXEL , GRB>(&atomPixel, 1); 
  atomPixel = CRGB(255,255,255); // BLANC

  atomPixel = CRGB(255,0,0); // ROUGE
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(255,255,0); // JAUNE
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(0,255,0); // VERT
  FastLED.show();
  delay(1000); // PAUSE 1 SECONDE
  atomPixel = CRGB(0,0,0);
  FastLED.show(); 

  // PBHUB
  Wire.begin();
  myTOF.init();
  myPbHub.begin();

}

void loop() {

  // oscslip angle unit 
  //int valueAngle = myPbHub.analogRead(KEY_CHANNEL_ANGLE);
  //monOsc.sendInt("/angle", valueAngle);

  // obtenir la mesure en millimètres
  int mesure = myTOF.readRangeSingleMillimeters();
  monOsc.sendInt("/mesure", mesure);

  delay(20);
}