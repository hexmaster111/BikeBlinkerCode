

int RUNNING = 13;
int BLINKERBUTTENRIGHT = 12;
int BLINKERBUTTENLEFT = 11;
int BLINKERRIGHTLIGHT = 10;
int BLINKERLEFTLIGHT = 9;
int BLINKERSTOP = 6;
int BRAKEBUTTEN = 8;
int BRAKELIGHT = 7;

int left = 0;
int right = 0;

int long  LASTBLINK = 0;
int BLINKTIME = 500;

void setup() {
    pinMode(RUNNING,OUTPUT);
    pinMode(BLINKERBUTTENRIGHT,INPUT);
    pinMode(BLINKERBUTTENLEFT,INPUT);
    pinMode(BLINKERRIGHTLIGHT,OUTPUT);
    pinMode(BLINKERLEFTLIGHT,OUTPUT);
    pinMode(BRAKELIGHT,OUTPUT);
    pinMode(BRAKEBUTTEN,INPUT);
    digitalWrite(RUNNING,HIGH);
}

void loop() {
  
  brakeCheck();
  buttonCheck();
  blinker();
}
 

void blinker(){
  
   if((right == 1) && (left) == 0){
    digitalWrite(BLINKERRIGHTLIGHT,HIGH);
    delay(BLINKTIME);
    digitalWrite(BLINKERRIGHTLIGHT,LOW);
    delay(BLINKTIME);

   }
   if((left == 0) && (right) == 0){
    digitalWrite(BLINKERRIGHTLIGHT,LOW);
    digitalWrite(BLINKERLEFTLIGHT,LOW);
   }
   if((left == 1) && (right) == 0){
    digitalWrite(BLINKERLEFTLIGHT,HIGH);
    delay(BLINKTIME);
    digitalWrite(BLINKERLEFTLIGHT,LOW);
    delay(BLINKTIME);
   }
}

void buttonCheck(){
    if(digitalRead(BLINKERBUTTENRIGHT) == HIGH){
      right = 1;
      left = 0;
    }
    if(digitalRead(BLINKERBUTTENLEFT) == HIGH){
      right = 0;
      left = 1;
    }
    if(digitalRead(BLINKERSTOP) == HIGH){
      right = 0;
      left = 0;
    }
}


void brakeCheck() {
      if(digitalRead(BRAKEBUTTEN) == HIGH){
      digitalWrite(BRAKELIGHT,HIGH);
    }else{
      digitalWrite(BRAKELIGHT,LOW);
    }
}



