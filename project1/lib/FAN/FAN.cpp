#include "lcd.hpp"
#include "global.hpp"

void turnOnFan(int percentage) {
    int fanSpeed = round(map(percentage, 0, 100, 0, 255)); // Example: map 70% to PWM value
    analogWrite(FAN_PIN, fanSpeed);
}
void turnOffFan() {
    analogWrite(FAN_PIN, 0);
}

void fanCallback(uint32_t value) {
    Serial.print("Fan control received: ");
    Serial.println(value);
    if(value == 1){
      turnOnFan(70);
    }
    else{
      turnOffFan();
    }
  }