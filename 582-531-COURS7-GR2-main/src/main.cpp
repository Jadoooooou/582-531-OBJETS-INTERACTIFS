#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define BROCHE_ATOM_FIL_BLANC 32
#define BROCHE_ATOM_FIL_JAUNE 26
#define BROCHE_ATOM_BOUTON 39
#define BROCHE_ATOM_PIXEL 27

// channel du hub où il est utilisé
#define KEY_CHANNEL 0

//CRGB keyPixel;
CRGB atomPixel;


void setup() {

  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);

  pinMode( BROCHE_ATOM_FIL_BLANC , INPUT_PULLUP );

  Wire.begin();
  myPbHub.begin();

}

void loop() {

  // oscslip key unit
  int press = myPbHub.digitalRead(KEY_CHANNEL);
  monOsc.sendInt("/decollage", press);
  delay(100);
  
}