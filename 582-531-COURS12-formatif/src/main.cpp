#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

// gestion du encoder
#include <M5_Encoder.h>
M5_Encoder myEncoder;

#define BROCHE_ATOM_PIXEL 27

// channel du hub où il est utilisé
#define KEY_CHANNEL_KEY 0

// CRGB keyPixel;
CRGB atomPixel;

// algorithme d'intervalle
unsigned long monChronoDepart ; 

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
  myPbHub.begin();

  // Enconder
  myEncoder.begin();

  // TEMPS DE DÉPART
  monChronoDepart = millis(); 

}

void loop() {

  if ( millis() - monChronoDepart >= 20 ) { 
    monChronoDepart = millis(); 

    // Mise à jour des valeurs de l'encodeur, doit être appelé avant de lire les valeurs.
  myEncoder.update();

  // Lecture de la rotation de l'encodeur
  int valeurEncodeur = myEncoder.getEncoderRotation();

  // Lecture du changement depuis la dernière lecture
  int changementEncodeur = myEncoder.getEncoderChange();

  // Lecture du bouton 
  int etatBouton = myEncoder.getButtonState();

  // Couleur des deux pixels
  //myEncoder.setLEDColorBoth( 0, 0, 0 );
  // Couleur pixel gauche
  //myEncoder.setLEDColorLeft( 0, 0, 0 );
  // Couleur pixel droite
  //myEncoder.setLEDColorRight( 0, 0, 0 );

    if (changementEncodeur > 0 ) {
      myEncoder.setLEDColorLeft( 0, 255, 0 );
      myEncoder.setLEDColorRight( 0, 0, 0 );
    } else if (changementEncodeur < 0 ){
      myEncoder.setLEDColorRight( 0, 255, 0 );
      myEncoder.setLEDColorLeft( 0, 0, 0 );
    }

    // oscslip rotation encoder
    monOsc.sendInt("/encoder", changementEncodeur);

    // oscslip bouton du encoder
    monOsc.sendInt("/bouton", etatBouton);

  }

}