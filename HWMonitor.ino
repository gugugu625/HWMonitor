#include "config.h"

TFT_eSPI tft = TFT_eSPI();
HardwareData data = HardwareData();
unsigned long LastUpdate = 0;
unsigned long LastDraw = 0;
bool TimeOutFlag = 0;
void setup() {
  pinMode(4,OUTPUT);
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);
  Serial.begin(115200);
  Serial2.begin(115200);
}

void loop() {
  String SerialData = "";
  while(Serial2.available()>0) {
    SerialData += char(Serial2.read());
  }
  SerialData.trim();

  if(SerialData!=""){
    
    DynamicJsonDocument jsonBuffer(200);
    deserializeJson(jsonBuffer, SerialData);
    JsonObject root = jsonBuffer.as<JsonObject>();
    data.SetCPUTemperature(root["CPUTemperature"]);
    data.SetCPULoad(root["CPULoad"]);
    data.SetRAM(root["RAMUsed"]);
    data.SetGPULoad(root["GPULoad"]);
    data.SetGPUTemperature(root["GPUTemperature"]);
    data.SetGRAM(root["GPUMemoryUsed"]);
    //Serial.println(SerialData);
    //Serial.println(data.CPUTemperature);
    LastUpdate = millis();
    TimeOutFlag = 0;
  }

  if(!TimeOutFlag){
    digitalWrite(4,HIGH);
    DrawCPUData();
    DrawGPUData();
    DrawRAMData();
    data.step();
    LastDraw = millis();
  }


  //Serial.println(TimeOutFlag);
  if(millis()-LastUpdate>=5000&&(!TimeOutFlag)){
    Serial.println("TimeOutFlag");
    TimeOutFlag = 1;
    tft.fillScreen(TFT_BLACK);
    digitalWrite(4,LOW);
  }
  if(SerialData=="GetDeviceName"){
    Serial2.println("HardwareMonitor");
  }
  
}
