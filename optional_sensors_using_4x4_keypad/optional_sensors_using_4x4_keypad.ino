#include <dht.h>
#include <Wire.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27


dht DHT;

#define DHT11_PIN 12

const int flamePin = 13;

//distance variables
const int trigPin = 11;
const int echoPin = 10;

//keypad variables
char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);


void setup(){
  lcd.init(); 
  lcd.backlight();

  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(flamePin, INPUT);
}

void loop(){

  lcd.setCursor(0,0);
  lcd.print("Pick sensor:");
  customKey = customKeypad.getKey();

  if(customKey){
    lcd.clear();
    Serial.print(customKey);
    delay(500);
    
    if(customKey == '1'){
      dhtFunction();
    }else if(customKey == '2'){
      distanceFunction();
    }else if(customKey == '3'){
      flameFunction();
    }
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void dhtFunction(){
  lcd.setCursor(0, 0);
  lcd.print("DHT Sensor");
  Serial.print("DHT Sensor picked");
  delay(1000);
  lcd.clear();

  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  Serial.print("Temp: ");
  Serial.print(DHT.temperature);
  Serial.print((char)223);
  Serial.print("C");
  Serial.print("Humidity: ");
  Serial.print(DHT.humidity);
  Serial.print("%");
  delay(5000);
  lcd.clear();
}

void distanceFunction(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic Sensor");
  delay(1000);
  lcd.clear();

  long duration, inches, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  lcd.setCursor(0,0);
  lcd.print(cm);
  lcd.print("cm");
  delay(5000);
  lcd.clear();

}

void flameFunction() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Flame Sensor");
  delay(1000);
  lcd.clear();

  if (digitalRead(flamePin) == 1 )
  {
    Serial.println("Fire detected!");
  }
  else
  {
    Serial.println("No Fire detected");
  }
  delay(100);

}
