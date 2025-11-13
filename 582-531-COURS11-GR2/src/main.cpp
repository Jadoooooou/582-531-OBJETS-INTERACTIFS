#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

// gestion du hub
#include <M5_PbHub.h>
M5_PbHub myPbHub;

#define BROCHE_ATOM_PIXEL 27

// channel du hub où il est utilisé
#define KEY_CHANNEL_KEY 0

// CRGB keyPixel;
CRGB atomPixel;

// algorithme d'intervalle
unsigned long monChronoDepart ; 

// FONCTION QUI SERA APPELÉE LORSQU'UN N'IMPORTTE QUEL MESSAGE OSC EST REÇU
void myOscMessageParser(MicroOscMessage & receivedOscMessage) { // receivedOscMessage est le message reçu
  // Ici, un if et receivedOscMessage.checkOscAddress() est utilisé pour traiter les différents messages
  if (receivedOscMessage.checkOscAddress("/pixel")) {  // MODIFIER /pixel pour l'adresse qui sera reçue
      int premierArgument = receivedOscMessage.nextAsInt(); // Récupérer le premier argument du message en tant que int
      int deuxiemerArgument = receivedOscMessage.nextAsInt(); // Récupérer le deuxième argument du message en tant que int
      int troisiemerArgument = receivedOscMessage.nextAsInt(); // Récupérer le troisième argument du message en tant que int

      // UTILISER ici les arguments récupérés
      myPbHub.setPixelColor(KEY_CHANNEL_KEY, 0, premierArgument, deuxiemerArgument, troisiemerArgument);
      

   // SI NÉCESSAIRE, ajouter d'autres if pour recevoir des messages avec d'autres adresses
   } else if (receivedOscMessage.checkOscAddress("/autre")) {  // MODIFIER /autre une autre adresse qui sera reçue
       // ...
   }
}

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

  // TEMPS DE DÉPART
  monChronoDepart = millis(); 

}

void loop() {

  // déclencher la réception des messages
  monOsc.onOscMessageReceived(myOscMessageParser);

  if ( millis() - monChronoDepart >= 20 ) { 
    monChronoDepart = millis(); 

    // oscslip key unit
    int press = myPbHub.digitalRead(KEY_CHANNEL_KEY);
    monOsc.sendInt("/key", press);

  }

}