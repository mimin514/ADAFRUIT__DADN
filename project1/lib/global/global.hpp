#ifndef GLOBAL_HPP
#define GLOBAL_HPP

#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT20.h>
#include <Adafruit_NeoPixel.h>

// Định nghĩa thông tin mạng WiFi


// Khai báo các đối tượng toàn cục
extern WiFiClient *client;
extern Adafruit_MQTT_Client *mqtt;
extern Adafruit_MQTT_Publish *temperature;
extern Adafruit_MQTT_Publish *humidity;
extern Adafruit_MQTT_Publish *lightSensor;
extern Adafruit_MQTT_Publish *soilSensor;
extern Adafruit_MQTT_Subscribe *fanControl ;

extern DHT20 DHT;
extern LiquidCrystal_I2C lcd;
extern const int BUZZER_PIN;
extern const int LIGHT_PIN;
extern const int SOIL_PIN;
extern const uint8_t  RGB_PIN;
extern const uint8_t  num_RGB;
extern Adafruit_NeoPixel NeoPixel ;
extern const int FAN_PIN;
#endif
