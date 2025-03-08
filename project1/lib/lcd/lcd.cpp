#include "lcd.hpp"
#include "global.hpp"

void lcd_init(){
    lcd.init();                      // initialize the lcd 
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("IOT SMARTFARM");
    delay(1000);
}

void lcd_print(float data1, float data2, float data3, float data4){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("H: ");
    lcd.print(data1, 1);
    lcd.print("% T: ");
    lcd.print(data2, 1);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("L: ");
    lcd.print(data3, 1);
    lcd.print("% S: ");
    lcd.print(data4, 1);
    lcd.print("%");
}