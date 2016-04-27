//Code V4 : Le bouton 1 permet de choisire entre  blanc sur tout la barre de led ou 
//juste derrières les LED qui correspondent à l'ecran de mon ordinateur

// définition pour les neopixel
#include <Adafruit_NeoPixel.h>
#define PIN 6 // broche 6
#define nbled 49 // nombre de led du ruban
Adafruit_NeoPixel led = Adafruit_NeoPixel(nbled, PIN, NEO_GRB + NEO_KHZ800);

// définition des pins des bouton poussoir 
int bouton1 = 2; // couleur blanche
int bouton2 = 3; // couleur alternatif
int bouton3 = 4; // couleur noir

// définition du pin du potentimètre linéaire
int potensLin = A0;
int val = 0;

// def de 2 pin, un en etat haut et un en état bas, pour conecter le potens lineaire au + et au - car, si utilise ceux de l'arduino, la mesure fluctue trop
int potPlus = 8;
int potMoin = 9;

// definition de 2 pin, un en état haut et un en état bas, pour connecter les boutons au + et - sans interférance avec la bande de LED
int bpPlus = 10;
int bpMoin = 11; 

// définition pour le switch/case
int mode = 0;

// définition pour la memoire du bouton poussoire 3
int memoire = HIGH;
int etatBouton;
int colorBP = 0;

// définition de la memoire du bouton poussoire 1
int memoire2 = HIGH;
int etatBouton2;
int dimensionBP = 0;

// définition des couleurs princiopalement utilisé

uint32_t blanc = led.Color(255, 255, 255); 
uint32_t noir = led.Color(0, 0, 0); 
uint32_t rouge = led.Color(250, 0, 0);  
uint32_t vert = led.Color(0, 250, 0);  
uint32_t bleu = led.Color(0, 0, 250); 
uint32_t jaune = led.Color(250, 250, 0); 
uint32_t magenta = led.Color(250, 0, 250); 
uint32_t cyan = led.Color(0, 250, 250); 
uint32_t jade = led.Color(135, 233, 144);
uint32_t orange = led.Color(223, 109, 20);

void setup() 
{ 
  //initialisation des  bouton en sorties
  pinMode(bouton1, INPUT); 
  pinMode(bouton2, INPUT); 
  pinMode(bouton3, INPUT); 

  //initialisation des etat pour le + et - du potentiomètre
  pinMode(potMoin, OUTPUT);
  pinMode(potPlus, OUTPUT);
  digitalWrite(potPlus, HIGH);
  digitalWrite(potMoin, LOW); 

  //initialisation des état pour l'allimentation des bouton
  pinMode(bpPlus, OUTPUT);
  pinMode(bpMoin, OUTPUT);
  digitalWrite(bpPlus, HIGH);
  digitalWrite(bpMoin, LOW);

  //initialisation du rubant de LED
  led.begin();
  led.show();

/*
  //initialisation de l'interuption sur la briche n°2 de l'arduino déclarer comme 0 par l'arduino
  attachInterrupt(0, changement, LOW);
*/ 

}

void loop()
{
  if(digitalRead(bouton1) == LOW)
  {
    mode = 1;
  }

  if(digitalRead(bouton2) == LOW)
  { 
    mode = 2;
  }

  if(digitalRead(bouton3) == LOW)
  {
    mode = 3;
  }

  switch (mode)
  {
  case 1:
    normal();
    break;

  case 2:
    couleurAlternatif();
    break; 

  case 3:
    noire();
    break;
  }
}

void normal()
{
  etatBouton2 = digitalRead(boutonon1);
  if((etatBouton2 != memoire2) && (etatBouton2 == LOW))
  {
    colorBP2++;
  }
  memoire2 = etatBouton2;

  if(dimensionBP > 1)
  {
    dimensionBP = 0;
  }
  taille(dimensionBP);
}

void couleurAlternatif()
{
  etatBouton = digitalRead(bouton3);
  if((etatBouton != memoire) && (etatBouton == LOW))
  {
    colorBP++;
  }
  memoire = etatBouton;

  if(colorBP > 8)
  {
    colorBP = 0;
  }
  affiche(colorBP);
}


void noire()
{
  led.setPixelColor(0, noir);
  led.setPixelColor(1, noir);
  led.setPixelColor(2, noir);
  led.setPixelColor(3, noir);
  led.setPixelColor(4, noir);
  led.setPixelColor(5, noir);
  led.setPixelColor(6, noir);
  led.setPixelColor(7, noir);
  led.setPixelColor(8, noir);
  led.setPixelColor(9, noir);
  led.setPixelColor(10, noir);
  led.setPixelColor(11, noir);
  led.setPixelColor(12, noir);
  led.setPixelColor(13, noir);
  led.setPixelColor(14, noir);
  led.setPixelColor(15, noir);
  led.setPixelColor(16, noir);
  led.setPixelColor(17, noir);
  led.setPixelColor(18, noir);
  led.setPixelColor(19, noir);
  led.setPixelColor(20, noir);
  led.setPixelColor(21, noir);
  led.setPixelColor(22, noir);
  led.setPixelColor(23, noir);
  led.setPixelColor(24, noir);
  led.setPixelColor(25, noir);
  led.setPixelColor(26, noir);
  led.setPixelColor(27, noir);
  led.setPixelColor(28, noir);
  led.setPixelColor(29, noir);
  led.setPixelColor(30, noir);
  led.setPixelColor(31, noir);
  led.setPixelColor(32, noir);
  led.setPixelColor(33, noir);
  led.setPixelColor(34, noir);
  led.setPixelColor(35, noir);
  led.setPixelColor(36, noir);
  led.setPixelColor(37, noir);
  led.setPixelColor(38, noir);
  led.setPixelColor(39, noir);
  led.setPixelColor(40, noir);
  led.setPixelColor(41, noir);
  led.setPixelColor(42, noir);
  led.setPixelColor(43, noir);
  led.setPixelColor(44, noir);
  led.setPixelColor(45, noir);
  led.setPixelColor(46, noir);
  led.setPixelColor(47, noir);
  led.setPixelColor(48, noir);
  led.show();
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return led.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return led.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return led.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

void affiche(int valeurRecu)
{
  if(valeurRecu == 0)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, vert);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 1)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, rouge);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 2)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, bleu);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 3)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, jaune);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 4)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, cyan);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 5)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, magenta);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 6)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, jade);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 7)
  {
    for(int i=0;i<49;i++){
      led.setPixelColor(i, orange);
      led.show();  
      delay(10);
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();
    } 
  }

  if(valeurRecu == 8)
  {    
    uint16_t i, j;

    for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
      for(i=0; i< led.numPixels(); i++) {
        led.setPixelColor(i, Wheel(((i * 256 / led.numPixels()) + j) & 255));
      }
      val = analogRead(potensLin);
      val = map(val, 0, 1023, 0, 255);
      led.setBrightness(val);
      led.show();

  
      
      delay(100); //vitesse de l'animation
    }
  }

    //test des entrée
      if(digitalRead(bouton1) == LOW)
      {
        mode = 1;
      }
      if(digitalRead(bouton2) == LOW)
      { 
        mode = 2;
      }
      if(digitalRead(bouton3) == LOW)
      { 
        mode = 3;
      }
}

void taille(int tailleRecu)
{
  if(tailleRecu == 1)
  {
      val = analogRead(potensLin);
  val = map(val, 0, 1023, 0, 255);
  led.setBrightness(val);
  led.setPixelColor(0, blanc);
  led.setPixelColor(1, blanc);
  led.setPixelColor(2, blanc);
  led.setPixelColor(3, blanc);
  led.setPixelColor(4, blanc);
  led.setPixelColor(5, blanc);
  led.setPixelColor(6, blanc);
  led.setPixelColor(7, blanc);
  led.setPixelColor(8, blanc);
  led.setPixelColor(9, blanc);
  led.setPixelColor(10, blanc);
  led.setPixelColor(11, blanc);
  led.setPixelColor(12, blanc);
  led.setPixelColor(13, blanc);
  led.setPixelColor(14, blanc);
  led.setPixelColor(15, blanc);
  led.setPixelColor(16, blanc);
  led.setPixelColor(17, blanc);
  led.setPixelColor(18, blanc);
  led.setPixelColor(19, blanc);
  led.setPixelColor(20, blanc);
  led.setPixelColor(21, blanc);
  led.setPixelColor(22, blanc);
  led.setPixelColor(23, blanc);
  led.setPixelColor(24, blanc);
  led.setPixelColor(25, blanc);
  led.setPixelColor(26, blanc);
  led.setPixelColor(27, blanc);
  led.setPixelColor(28, blanc);
  led.setPixelColor(29, blanc);
  led.setPixelColor(30, blanc);
  led.setPixelColor(31, blanc);
  led.setPixelColor(32, blanc);
  led.setPixelColor(33, blanc);
  led.setPixelColor(34, blanc);
  led.setPixelColor(35, blanc);
  led.setPixelColor(36, blanc);
  led.setPixelColor(37, blanc);
  led.setPixelColor(38, blanc);
  led.setPixelColor(39, blanc);
  led.setPixelColor(40, blanc);
  led.setPixelColor(41, blanc);
  led.setPixelColor(42, blanc);
  led.setPixelColor(43, blanc);
  led.setPixelColor(44, blanc);
  led.setPixelColor(45, blanc);
  led.setPixelColor(46, blanc);
  led.setPixelColor(47, blanc);
  led.setPixelColor(48, blanc);
  led.show();
  }
  
  if(tailleRecu == 0)
  {
      val = analogRead(potensLin);
  val = map(val, 0, 1023, 0, 255);
  led.setBrightness(val);
  led.setPixelColor(15, blanc);
  led.setPixelColor(16, blanc);
  led.setPixelColor(17, blanc);
  led.setPixelColor(18, blanc);
  led.setPixelColor(19, blanc);
  led.setPixelColor(20, blanc);
  led.setPixelColor(21, blanc);
  led.setPixelColor(22, blanc);
  led.setPixelColor(23, blanc);
  led.setPixelColor(24, blanc);
  led.setPixelColor(25, blanc);
  led.setPixelColor(26, blanc);
  led.setPixelColor(27, blanc);
  led.setPixelColor(28, blanc);
  led.setPixelColor(29, blanc);
  led.setPixelColor(30, blanc);
  led.setPixelColor(31, blanc);
  led.setPixelColor(32, blanc);
  led.setPixelColor(33, blanc);
  led.setPixelColor(34, blanc);
  led.setPixelColor(35, blanc);
  led.setPixelColor(36, blanc);
  led.setPixelColor(37, blanc);
  led.setPixelColor(38, blanc);
  led.setPixelColor(39, blanc);
  led.show();
  }
  
}

/*
void changement ()
{
  mode = 1;
}
*/
