#include "tool.h"


class ProcessBar1{
    TFT_eSprite sprite;

    public:

    void draw(TFT_eSprite *sprite,float data){
        fillSector(sprite,50,50,180,data,40,TFT_FORECOLOR);
    }
};

