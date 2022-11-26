#include <time.h>
#include <stdlib.h>


bool led_glow = false; 
int n = 0;
bool start = true;
bool winning = false;
bool losing = false;
int buttonState = 0;

int R = 10;
int G = 9;
int B = 8;
int buzzer = 12;

int button = 11;
void setup()
{
   
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(button, INPUT);
  pinMode(buzzer, OUTPUT);
  srand(time(NULL));
  Serial.begin(9600);
}
  
 void loop()
 {
  //tone(buzzer, 1000);
  int time_of_glowing = 100;
  int time_of_delay = rand()% (2000 + 1 - 1000) + 1000;
  buttonState = digitalRead(button);
  n = n + 1;

  if (start == true){
    if (n > time_of_delay){
      led_glow = true;
      start = false;
      n = 0;
      digitalWrite(R, HIGH); 
      digitalWrite(G, LOW); 
      digitalWrite(B, LOW); 
    }
  }
  if (led_glow == true){
    if (n > time_of_glowing){
      led_glow = false;
      digitalWrite(R, LOW); 
      digitalWrite(G, LOW); 
      digitalWrite(B, LOW); 
      losing = true;
      n = 0;
    } 
  }
  if(winning == true){
    for (int a = 0; a<5; a++) {
      tone(buzzer, 800);
      digitalWrite(R, LOW); 
      digitalWrite(G, HIGH); 
      digitalWrite(B, LOW);  
      delay(100);
      noTone(buzzer);
      digitalWrite(R, LOW); 
      digitalWrite(G, LOW); 
      digitalWrite(B, LOW);
      delay(100);  
    }
    winning = false;
    led_glow = false; 
    n = 0;
    start = true;
    winning = false;
    losing = false;
    buttonState = 0;
  }

  if(losing == true){
    for (int a = 0; a<3; a++) {
      tone(buzzer, 2000);
      digitalWrite(R, LOW); 
      digitalWrite(G, LOW); 
      digitalWrite(B, HIGH);  
      delay(100);
      noTone(buzzer);
      digitalWrite(R, LOW); 
      digitalWrite(G, LOW); 
      digitalWrite(B, LOW);
      delay(100);  
    }
    
    winning = false;
    losing = false;
    led_glow = false; 
    n = 0;
    start = true;
    winning = false;
    buttonState = 0;
  }

  
  if (buttonState == HIGH){
    if (led_glow == true){
      winning = true;
      led_glow = false;
    }
    else{
      led_glow = false;
      digitalWrite(R, LOW); 
      digitalWrite(G, LOW); 
      digitalWrite(B, LOW); 
      losing = true;
      n = 0;
      }
  }
  Serial.println(buttonState);
  delay(1);

  
  




  
  // % (max_number + 1 - minimum_number) + minimum_number
  /*
  if (led_glow == false){
    if (time_of_glowing < 500){
      digitalWrite(8, HIGH);
      led_glow = true;
      time_of_glowing = 0;
    }
  }
  else{
    delay(time_of_glowing);
  }
  //delay(rand()% (5000 + 1 - 100) + 100);
  
  if (led_glow == false){
    digitalWrite(8, HIGH);
    led_glow = true;
  }
  else{
    digitalWrite(8, LOW);
    led_glow = false;
  }
  n = n+1;
  */
 }
