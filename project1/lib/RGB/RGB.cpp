#include "RGB.hpp"
#include "global.hpp"

void RGB_init(){
    NeoPixel.begin();
    NeoPixel.clear();
    NeoPixel.show();
}

void RGB_setColor(uint8_t r, uint8_t g, uint8_t b){
    for (int pixel = 0; pixel < num_RGB; pixel++) {
        NeoPixel.setPixelColor(pixel, NeoPixel.Color(r, g, b));
    }
    NeoPixel.show();
}

void RGB_clear(){
    NeoPixel.clear();
    NeoPixel.show();
}

void RGB_setColoByNum(int num, const char* colorName){
    if (strcmp(colorName, "red") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(255, 0, 0));
    } else if (strcmp(colorName, "green") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(0, 255, 0));
    } else if (strcmp(colorName, "blue") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(0, 0, 255));
    } else if (strcmp(colorName, "yellow") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(255, 255, 0));
    } else if (strcmp(colorName, "cyan") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(0, 255, 255));
    } else if (strcmp(colorName, "magenta") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(255, 0, 255));
    } else if (strcmp(colorName, "white") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(255, 255, 255));
    } else if (strcmp(colorName, "off") == 0) {
        NeoPixel.setPixelColor(num, NeoPixel.Color(0, 0, 0));
    } else {
        Serial.println("Unknown color name");
    }
    NeoPixel.show();
}
void RGB_setColorByName(const char* colorName) {
    if (strcmp(colorName, "red") == 0) {
        RGB_setColor(255, 0, 0);
    } else if (strcmp(colorName, "green") == 0) {
        RGB_setColor(0, 255, 0);
    } else if (strcmp(colorName, "blue") == 0) {
        RGB_setColor(0, 0, 255);
    } else if (strcmp(colorName, "yellow") == 0) {
        RGB_setColor(255, 255, 0);
    } else if (strcmp(colorName, "cyan") == 0) {
        RGB_setColor(0, 255, 255);
    } else if (strcmp(colorName, "magenta") == 0) {
        RGB_setColor(255, 0, 255);
    } else if (strcmp(colorName, "white") == 0) {
        RGB_setColor(255, 255, 255);
    } else if (strcmp(colorName, "off") == 0) {
        RGB_clear();
    } else {
        Serial.println("Unknown color name");
    }
}