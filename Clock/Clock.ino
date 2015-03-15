#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int FANPIN = 82;
int AMAX = 255;
boolean start;
int dayInt;

void setup() {
  start = true;
  // Set up time
  setTime(0,0,0,1,1,2015);
  dayInt = 1;
  
  // Set up LCD
  lcd.init();

  // ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  
  
}

void loop() {
  if(dayInt != day() || start){
    lcd.setCursor(0,0);
    char date[15];
    sprintf(date, "%02i/%02i/%04i", day(), month(), year());
    lcd.print(date);    
    dayInt = day();
    if(start){
      start = false;    
    }
  }
  
  // Display current time
  lcd.setCursor(0,1);
  char time[8];
  sprintf(time, "%02i:%02i:%02i", hour(), minute(), second());
  lcd.print(time);
  
  
  delay(1000);
}

