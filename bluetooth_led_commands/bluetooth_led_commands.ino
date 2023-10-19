#define LED_01 8                           //define pin 8 for LED1
#define LED_02 9                           //define pin 9 for LED2
#define LED_03 10                          //define pin 10 for LED3

int input_value = 0;

void setup(){
  Serial.begin(9600);                     //set the bund rate 9600 
  pinMode(LED_01, OUTPUT);                //take pin 8 as OUTPUT
  pinMode(LED_02, OUTPUT);                //take pin 9 as OUTPUT
  pinMode(LED_03, OUTPUT);                //take pin 10 as OUTPUT
}

void loop(){
  if(Serial.available()){                //true when sending data is available  
    input_value = Serial.parseInt();     //Serial.parseInt()function take serial data as integer 
    Serial.print(input_value);           //print seding data   
    Serial.print("\n");
  
    if(input_value==1){
      digitalWrite(LED_01,HIGH);         //turn ON LED1
      digitalWrite(LED_02,LOW);
      digitalWrite(LED_03,LOW);
    }
    else if(input_value==2){
      digitalWrite(LED_01,LOW);         //turn ON LED2
      digitalWrite(LED_02,HIGH);
      digitalWrite(LED_03,LOW);
    }
    else if(input_value==3){
      digitalWrite(LED_01,LOW);         //turn ON LED 3
      digitalWrite(LED_02,LOW);
      digitalWrite(LED_03,HIGH);
    }
  }
}