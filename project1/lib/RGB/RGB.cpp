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



void RGBcallback(char *data, uint16_t len) {
    if (len < 1) return;

    char* dataCopy = strdup(data);
    
    char* firstDot = strchr(dataCopy, '.');
    if (firstDot) {
        // Tiếp tục tìm dấu "." thứ hai
        char* secondDot = strchr(firstDot + 1, '.');
        if (secondDot) {
            // Tách chuỗi thành phần thiết bị và màu
            *secondDot = '\0';  // Đặt dấu null ở vị trí dấu chấm thứ hai, tạo ra chuỗi "xxx" và "yyy"
            char* device = dataCopy;          // Phần trước dấu chấm thứ hai (thiết bị)
            char* color = secondDot + 1;     // Phần sau dấu chấm thứ hai (màu sắc)

            // Kiểm tra và xác định thiết bị
            if (device && color) {
                if (strcmp(device, "da.light") == 0) {
                    RGB_setColoByNum(0, color);  // Điều khiển LED 0 (Ánh sáng)
                } else if (strcmp(device, "da.hum") == 0) {
                    RGB_setColoByNum(1, color);  // Điều khiển LED 1 (Độ ẩm không khí)
                } else if (strcmp(device, "da.soil") == 0) {
                    RGB_setColoByNum(2, color);  // Điều khiển LED 2 (Độ ẩm đất)
                } else if (strcmp(device, "da.temp") == 0) {
                    RGB_setColoByNum(3, color);  // Điều khiển LED 3 (Nhiệt độ)
                }
            }
        }
    }
    
    // Giải phóng bộ nhớ đã cấp phát
    free(dataCopy);
}