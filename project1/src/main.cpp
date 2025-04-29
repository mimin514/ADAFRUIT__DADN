#include <Arduino.h>
#include "global.hpp"
#include "MQTT.hpp"
#include "lcd.hpp"
#include "RGB.hpp"
#include "FAN.hpp"
int count = 0;

void setup()
{
  Serial.begin(115200);
  
  Wire1.begin(21, 22);  //  select your pin numbers here
  lcd_init();

  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(SOIL_PIN, INPUT);
  pinMode(RGB_PIN, OUTPUT);
  pinMode(LIGHT_PIN, INPUT);
  pinMode(FAN_PIN , OUTPUT);
  pinMode(PUMP1_PIN , OUTPUT);
  pinMode(PUMP2_PIN , OUTPUT);
  RGB_init();

fanControl->setCallback(fanCallback);
mqtt->subscribe(fanControl);

pump1Control->setCallback(pump1Callback);
mqtt->subscribe(pump1Control);

pump2Control->setCallback(pump2Callback);
mqtt->subscribe(pump2Control);

RGB->setCallback(RGBcallback);
mqtt->subscribe(RGB);
RGB_setColorByName("green");
NeoPixel.setBrightness(10);

}

void loop()
{
  NeoPixel.setBrightness(50);
  // Kiểm tra kết nối WiFi  
  if (WiFi.status() != WL_CONNECTED) {
      // connectWiFi("603H6-KH&KTMT", "svkhktmt");
      connectWiFi("601H6-KH&KTMT", "svkhktmt");

  }

  // Kiểm tra kết nối MQTT
  if (!mqtt->connected()) {
      connectMQTT();
  }
  mqtt->processPackets(10000);
  // tone(BUZZER_PIN, 494, 500);

  // RGB_setColorByName("green");
  int status = DHT.read();
  float hum_value = DHT.getHumidity();
  float temp_value = DHT.getTemperature();

  // Đọc giá trị cảm biến ánh sáng
  float lightSensorValue = analogRead(LIGHT_PIN);
  float lightPercentage = map(lightSensorValue, 0, 4095, 0, 100);

  // Đọc giá trị cảm biến độ ẩm đất
  float soilSensorValue = analogRead(SOIL_PIN);
  float soilPercentage = map(soilSensorValue, 0, 4095, 0, 100);


//   // Hiển thị trên Serial Monitor dưới dạng bảng hàng ngang
  Serial.println("\nTime (s)\tTemperature (C)\tHumidity (%)\tLight (%)\tSoil Moisture (%)");
//   Serial.print(count++); // Thời gian tính bằng giây
//   Serial.print("\t\t");
  Serial.print(temp_value, 1);
  Serial.print("\t\t");
  Serial.print(hum_value, 1);
  Serial.print("\t\t");
  Serial.print(lightPercentage);
  Serial.print("\t\t");
  Serial.print(soilPercentage);
  Serial.print("\t\t\n");

//   // Gửi dữ liệu lên Adafruit IO với đúng key
    publishData(temperature, temp_value);
    publishData(humidity, hum_value); 
    publishData(lightSensor, lightPercentage);
    publishData(soilSensor, soilPercentage);
//   RGB_setColorByName("yellow");
  lcd_print(hum_value, temp_value, lightPercentage, soilPercentage);

//   int fanSpeed = round(map(70, 0, 100, 0, 255)); // Example: map 70% to PWM value



// turnOnFan(70);
// delay(6000);

// // Turn off the fan
// turnOffFan();

// // Set RGB color to yellow
// RGB_setColorByName("yellow");
// RGB_setColor(255,0,255);
// RGB_setColoByNum(1,"red");
// RGB_setColoByNum(2,"cyan");
// RGB_setColoByNum(3,"green");
// RGB_setColoByNum(0,"magenta");
// NeoPixel.setBrightness(20);
delay(700);
mqtt->processPackets(3000);

}
