//Interface 4 wires I2C LCD Display with Arduino Code
//https://www.programmingboss.com/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x3F

void setup() {
  lcd.init();
  lcd.clear();         
  lcd.backlight();      // Turning on the backlight
  
  lcd.setCursor(3,0);   //Set LCD cursor to character 3 on line 0
  lcd.print("Hello world!");
  
  lcd.setCursor(0,1);   //Move LCD cursor to character 0 on line 1
  lcd.print("programmingboss");
}

void loop() {
//Rest of the code
}