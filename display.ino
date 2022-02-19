#include <LiquidCrystal.h>
#include <TimeLib.h>

LiquidCrystal lcd (1,2,4,5,6,7);
int secunda = 0;
int minut = 0;
int ora = 0;
float consum = 0;

void secundaZero(){
  lcd.setCursor(7,1);
  lcd.print("0");
  lcd.setCursor(6,1);
  lcd.print("0");
}

void minutZero(){
  lcd.setCursor(4,1);
  lcd.print("0");
  lcd.setCursor(3,1);
  lcd.print("0");
}


void setup() {

  // Initializare si setup
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Timp:");
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(2,1);
  lcd.print(":");
  lcd.setCursor(12,0);
  lcd.print("KWh:");
  lcd.setCursor(12,1);
  lcd.print("0.00");
}

void loop() {

  // Rularea continua
  
  lcd.setCursor(5,1);
  lcd.print(":");
  lcd.setCursor(2,1);
  lcd.print(":");
  delay(1000);
  secunda++;
  if(secunda < 10){
    lcd.setCursor(6, 1);
    lcd.print("0");
    lcd.setCursor(7, 1);
    lcd.print(secunda);
  } else if (secunda >= 10 && secunda < 60){
    lcd.setCursor(6, 1);
    lcd.print(secunda);
  } else{
    secunda = 0;
    secundaZero();
    minut = minut + 1;
    lcd.setCursor(12,1);
    consum = consum + 0.00383;
    lcd.print(consum);
  }

  if(minut < 10){
    lcd.setCursor(3, 1);
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(minut);
  } else if (minut >= 10 && minut < 60){
    lcd.setCursor(3, 1);
    lcd.print(minut);
  } else{
    minut = 0;
    minutZero();
    ora = ora + 1;
  }

  if(ora < 10){
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(ora);
  } else if (ora >= 10 && ora < 60){
    lcd.setCursor(0, 1);
    lcd.print(ora);
  }
  
  }
