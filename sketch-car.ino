#define RG_AV 10
#define RG_AR 11
#define RD_AV 6
#define RD_AR 9

int vitesse =80;
int commande=0;
bool ifNewCommand=false;
void piloterVoiture(int cmd, int commandTime=30000000){
  if(cmd=='c'  && vitesse<=90){vitesse=vitesse+10;}
  else if(cmd=='c'  && vitesse>0){vitesse=vitesse-10;}
  int carSpeed=map(vitesse,0,100,0,255);
  arreterRobot();

  switch(cmd){                  
    case '1':{//avancer
      analogWrite(RD_AV,carSpeed);
      analogWrite(RG_AV,carSpeed);
    }break;
     case '2':{//reculer
      analogWrite(RD_AR,carSpeed);
      analogWrite(RG_AR,carSpeed);
    }break;
     case '3':{//touener a droite
      analogWrite(RD_AR,carSpeed);
      analogWrite(RG_AV,carSpeed);
    }break;
     case '4':{//tourner a gauche
      analogWrite(RD_AV,carSpeed);
      analogWrite(RG_AR,carSpeed);
    }break;
}
delay(commandTime);
arreterRobot();
}
void arreterRobot(){
  analogWrite(RD_AV,0);
  analogWrite(RD_AR,0);
  analogWrite(RG_AV,0);
  analogWrite(RG_AR,0);
}

void setup(){
  Serial.begin(115200);
  Serial.println("Configuration du robot ");
  pinMode(RG_AV,OUTPUT);
  pinMode(RG_AR,OUTPUT);
  pinMode(RD_AV,OUTPUT);
  pinMode(RD_AR,OUTPUT);
  Serial.println("Arret des roues");
  arreterRobot();
  Serial.println("Le robot attend ta commande:");
}
void loop(){
  if(Serial.available()){
    commande =Serial.read();
    ifNewCommand=true;
  }
  if (ifNewCommand){  //vrai
    piloterVoiture(commande);
    ifNewCommand=false;
    }
  }
