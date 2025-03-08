#include "MQTT.hpp"
#include "global.hpp"


void connectWiFi() {
    Serial.print("Connecting to WiFi...");
    WiFi.begin(WIFI_SSID, WIFI_PASS);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected!");
}

void connectMQTT() {
    while (mqtt->connected() == false) {
        Serial.print("Connecting to MQTT...");
        if (mqtt->connect()) {
            Serial.println("Connected!");
        } else {
            Serial.print("Failed, retrying in 5s...");
            delay(5000);
        }
    }
}

void publishData(Adafruit_MQTT_Publish *a, float data) {
    if (!a->publish(data)) {
        Serial.print("Failed to publish ");
        Serial.print(data);
    }
}



