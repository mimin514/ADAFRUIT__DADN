#include "global.hpp"

// Khởi tạo các biến toàn cục
WiFiClient *client = new WiFiClient();
Adafruit_MQTT_Client *mqtt = new Adafruit_MQTT_Client(client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Publish *temperature = new Adafruit_MQTT_Publish(mqtt, AIO_USERNAME "");
Adafruit_MQTT_Publish *humidity = new Adafruit_MQTT_Publish(mqtt, AIO_USERNAME "");
Adafruit_MQTT_Publish *lightSensor  = new Adafruit_MQTT_Publish(mqtt, AIO_USERNAME "");
Adafruit_MQTT_Publish *soilSensor  = new Adafruit_MQTT_Publish(mqtt, AIO_USERNAME "");

Adafruit_MQTT_Subscribe *fanControl = new Adafruit_MQTT_Subscribe(mqtt, AIO_USERNAME "");



DHT20 DHT(&Wire1);
LiquidCrystal_I2C lcd(0x21, 20, 4);
const int BUZZER_PIN = 25;
const int LIGHT_PIN = 39;
const int SOIL_PIN = 33;
const uint8_t  RGB_PIN = 32;
const uint8_t  num_RGB = 4;
const int FAN_PIN = 26;
Adafruit_NeoPixel NeoPixel = Adafruit_NeoPixel(num_RGB, RGB_PIN, NEO_GRB + NEO_KHZ800);
// extern Adafruit_NeoPixel NeoPixel;

