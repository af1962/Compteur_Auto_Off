

#include <SoftwareSerial.h>

SoftwareSerial Serial(4,3); // RX ,TX

#define automaintien 1
#define capteur 2                       // bouton en broche D2
unsigned long currentTime=0;            // Temps millis() en cours
unsigned long previousTime=0;           // Temps passé entre 2 millis() pour minuterie;
int minuterie = 20;                     // Temps de fonctionnement en seconde
int duree = 0;                          // temps minuterie en cours en seconde
unsigned long lastDelayRebond  = 0;     // Temps entre 2 millis() pour anti rebond
unsigned long delayRebond  = 100;       // Durée anti rebond
int compteur=0;                         // Compteur
bool didStatus  = false;                // Etat du capteur pour anti rebond
bool oldDidStatus  = false;             // Ancien état du capteur pour anti rebond
int memoire = HIGH;                     // La mémoire de l'état du bouton pour front
int memoirePlus = 0;                    
String str="";


void setup() 
{  
  Serial.begin(9600);
  Serial.setTimeout(100);
  pinMode(capteur,INPUT_PULLUP);
  pinMode(automaintien,OUTPUT);
  duree=minuterie;
  digitalWrite(automaintien,HIGH);
}


void loop() 
{  
   str=Serial.readString();
   // Raz en appuyant sur l'écran
  if(str=="raz")
  {
    compteur=0;
    Serial.print("cpt.val=");
    Serial.print(compteur);  
    Serial.write(0xFF);
    Serial.write(0xFF);
    Serial.write(0xFF);
  }

// Capteur comptage 
  int reading = digitalRead(capteur);  
  if((reading != memoire) && (reading == LOW) && (reading != oldDidStatus))   // reading == Low pour front descendant
    {     
        lastDelayRebond = millis();
    }
  if ((millis() - lastDelayRebond)>= delayRebond) 
  {
   if((reading != oldDidStatus))
    {
      didStatus = reading;
      compteur++;
      Serial.print("cpt.val=");
      Serial.print(compteur);  
      Serial.write(0xFF);
      Serial.write(0xFF);
      Serial.write(0xFF);   
      duree= minuterie + millis()/(1000);      // Relance la minuterie à chaque passage de palonnier      
    }
  }      
   memoire = reading;      
   oldDidStatus = reading;
    
// Test la fin de la tempo  
    currentTime=millis()/1000;              // Pour avoir le temps en seconde
     if((currentTime)>=duree)
      {
        digitalWrite(automaintien,LOW);
      }      
   
 }  
