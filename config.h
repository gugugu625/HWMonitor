#include <SPI.h>
#include <TFT_eSPI.h>
#include <ArduinoJson.h>
#include "HardwareData.h"
#include "Font.h"
#include "Image.h"

#define DEG2RAD 0.0174532925
#define TFT_BACKCOLOR TFT_BLACK
#define TFT_FORECOLOR 0x3d7b
#define TFT_BACK1COLOR 0x3186

extern TFT_eSPI tft;
extern HardwareData data;
void DrawCPUData();
void DrawGPUData();
void DrawRAMData();
void SetCPUData(double);
void fillSector(TFT_eSprite *sprite,int x,int y, int start_angle, int sub_angle, int r, unsigned int colour);
void DrawProcessBar1(int x, int y,int data,const uint16_t *icon);
void DrawProcessBar2(int x, int y,String title,int data);