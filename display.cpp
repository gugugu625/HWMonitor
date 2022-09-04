#include "config.h"



void DrawCPUData(){
    DrawProcessBar2(30,120,String("TEMP")+":"+String(data.CPUTemperature,1),data.GetCPUTemperatureNumber());
    //Serial.println(data.GetCPUTemperatureNumber());
    DrawProcessBar1(30,10,data.GetCPULoadDegree(),CPU_icon);
    tft.drawFastHLine(0,170,160,TFT_BACK1COLOR);
    tft.drawFastVLine(160,0,240,TFT_BACK1COLOR);
}


void DrawGPUData(){
    DrawProcessBar1(180,10,data.GetGPULoadDegree(),GPU_icon);
    DrawProcessBar2(180,120,String("TEMP")+": "+String(round(data.GPUTemperature),0),data.GetGPUTemperatureNumber());
    DrawProcessBar2(180,180,String("GRAM")+":"+String(round(data.GRAMUsed),0)+"%",data.GetGRAMNumber());
}


void DrawRAMData(){

    DrawProcessBar2(30,180,String("RAM")+":"+String(data.RAMUsed,1)+"%",data.GetRAMNumber());
}

void DrawProcessBar1(int x, int y,int data,const uint16_t *icon){
    TFT_eSprite bar1 = TFT_eSprite(&tft);
    bar1.createSprite(100,100);
    bar1.fillScreen(TFT_BACKCOLOR);
    fillSector(&bar1,50,50,180,270,40,TFT_BACK1COLOR);
    fillSector(&bar1,50,50,180,data,40,TFT_FORECOLOR);
    bar1.fillCircle(50,50,30,TFT_BACKCOLOR);
    bar1.setTextDatum(MR_DATUM);
    bar1.loadFont(font_process1);
    bar1.drawNumber(data/2.7,70,50);
    bar1.unloadFont();
    //bar1.fillRect(60,60,32,32,TFT_FORECOLOR);
    bar1.pushImage(60, 60, 32, 32,icon);
    bar1.pushSprite(x,y);
}

void DrawProcessBar2(int x, int y,String title,int data){
    TFT_eSprite bar2 = TFT_eSprite(&tft);
    bar2.createSprite(110,40);
    bar2.fillScreen(TFT_BACKCOLOR);
    bar2.fillRect(0,22, 110,15,TFT_BACK1COLOR);
    bar2.fillRect(0,22,data,15,TFT_FORECOLOR);
    bar2.setTextDatum(TL_DATUM);
    bar2.loadFont(font_process2);
    bar2.drawString(title,0,0);
    bar2.unloadFont();
    bar2.pushSprite(x,y);
}


void fillSector(TFT_eSprite *sprite,int x,int y, int start_angle, int sub_angle, int r, unsigned int colour){
    float sx = cos((start_angle - 90) * DEG2RAD);
    float sy = sin((start_angle - 90) * DEG2RAD);
    uint16_t x1 = sx * r + x;
    uint16_t y1 = sy * r + y;
    for (int i = start_angle; i < start_angle + sub_angle; i++)
    {
        int x2 = cos((i + 1 - 90) * DEG2RAD) * r + x;
        int y2 = sin((i + 1 - 90) * DEG2RAD) * r + y;
        sprite->fillTriangle(x1, y1, x2, y2, x, y, colour);
        x1 = x2;
        y1 = y2;
  }
}