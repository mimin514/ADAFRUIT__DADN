#ifndef MQTT_HPP
#define MQTT_HPP
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>


// void connectWiFi() ;
void connectMQTT() ;
void publishData(Adafruit_MQTT_Publish *a, float data);
void connectWiFi(const char* name, const char* pass) ;
    #endif 