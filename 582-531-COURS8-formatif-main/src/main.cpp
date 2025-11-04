#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define BROCHE_ATOM_ANGLE 32
#define BROCHE_ATOM_LIGHT 32
#define BROCHE_ATOM_BOUTON_ROUGE 32
#define BROCHE_ATOM_PIXEL_BOUTON_ROUGE 26
#define BROCHE_ATOM_BOUTON 39
#define BROCHE_ATOM_PIXEL 27

// channel du hub où il est utilisé
#define KEY_CHANNEL_ANGLE 1
#define KEY_CHANNEL_LIGHT 5

//CRGB keyPixel;
CRGB atomPixel;


void setup() {

  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);

  Wire.begin();
  myPbHub.begin();

}

void loop() {

  // oscslip angle unit 
  int valueAngle = myPbHub.analogRead(KEY_CHANNEL_ANGLE);
  monOsc.sendInt("/angle", valueAngle);

  // oscslip light unit 
  int valueLight = myPbHub.analogRead(KEY_CHANNEL_LIGHT);
  monOsc.sendInt("/light", valueLight);

  delay(100);
  
}