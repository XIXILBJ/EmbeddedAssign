#include <Arduino.h>

// put function declarations here:
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C  // I2C地址

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
  Wire.begin(21, 22); // 初始化I2C（SDA=21, SCL=22）

  if(!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED初始化失败");
    while(1);
  }

  display.clearDisplay();
  display.setTextSize(2);           // 字体放大2倍
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 25);        // 文本起始坐标
  display.print("Hello World!");
  display.display();                // 输出到屏幕
}

void loop() {}