#ifndef RGB_HPP
#define RGB_HPP


#include <Adafruit_NeoPixel.h>


void RGB_init();
void RGB_setColor(uint8_t r, uint8_t g, uint8_t b);
void RGB_clear();
void RGB_setColorByName(const char* colorName);
void RGB_setColoByNum(int num, const char* colorName);

#endif 