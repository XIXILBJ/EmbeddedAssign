#include <Arduino.h>

// put function declarations here:
// 定义LED引脚
#define LED1_PIN 23
#define LED2_PIN 22

// 提前声明函数原型
void toggleLED(int pin, const char* ledName);

void setup() {
  Serial.begin(115200);           
  pinMode(LED1_PIN, OUTPUT);      
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);    
  digitalWrite(LED2_PIN, LOW);
}

void loop() {
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n'); 
    command.trim();                                

    if (command == "1") {
      toggleLED(LED1_PIN, "LED1");
    } else if (command == "2") {
      toggleLED(LED2_PIN, "LED2");
    } else {
      Serial.println("无效指令"); 
    }
  }
}

// 函数定义
void toggleLED(int pin, const char* ledName) {
  int state = digitalRead(pin);
  digitalWrite(pin, !state);                  
  Serial.print(ledName);
  Serial.println(state ? " 灭" : " 亮");       
}