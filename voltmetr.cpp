#include "LiquidCrystal_I2C.h" //plugin
#include "Wire.h"
LiquidCrystal_I2C lcd(0x27, 16, 2); //adresa a parametry
void setup() {
  lcd.init();
   lcd.backlight(); //podsviceni
   delay(500);
  lcd.print("VOLTMETR! v2"); //nabíhací obrazovka
  delay(2000);
  lcd.setCursor(0, 0);
  lcd.clear();
}
void loop() {
  int Raw;
  double V;
  Raw = analogRead(A0);
  V = Raw * (5.0*11 / 1023); //výpočet
  lcd.setCursor(0, 1);
  lcd.print("Napeti:"); //hlavní obrazovka
  lcd.print(V,  3);
  lcd.print("V");
  delay(500);
}