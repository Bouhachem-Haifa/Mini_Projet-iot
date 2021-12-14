/*********************************************************************************************
   Contrôle de deux moteurs cc avec un L298N
   http://electroniqueamateur.blogspot.com/2016/06/controle-dun-ou-deux-moteurs-cc-avec.html
 *********************************************************************************************/

// définition des pins de l'Arduino qui contrôlent le 1er moteur
#define pinIN1 2
#define pinIN2 3
#define pinENA 9 // doit être une pin PWM 




void setup() {

  // toutes ces pins sont des sorties

  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);

  

}

void loop() {

  // le premier moteur tourne en marche avant, lentement

  analogWrite(pinENA, 60); // vitesse lente (entre 0 et 255)
  // si le moteur ne tourne pas du tout, augmentez la valeur
  digitalWrite(pinIN1, true);
  digitalWrite(pinIN2, false);

 

  // on les laisse tourner comme ça pendant 2 secondes

  delay(2000);

  // le premier moteur tourne en marche arrière, rapidement

  analogWrite(pinENA, 255); // vitesse maximale
  digitalWrite(pinIN1, false); // le contraire de ce qu'on avait en marche avant
  digitalWrite(pinIN2, true);

  

  // on les laisse tourner comme ça pendant 2 secondes

  delay(2000);

}
