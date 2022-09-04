
#pragma once
#ifndef HARDWAREDATA_H
#define HARDWAREDATA_H




class HardwareData{
    private:
    int CPUTemperatureTGT;
    int CPUTemperatureNow;
    
    int CPULoadTGT;
    int CPULoadNow;
    int GPUTemperatureTGT;
    int GPUTemperatureNow;
    int GPULoadTGT;
    int GPULoadNow;
    float GPUMemoryUsed;
    
    int RAMTGT;
    int RAMNow;

    int GRAMTGT;
    int GRAMNow;
    int DataStep(int TGT,int now){
        int btw = TGT-now;
        if(btw>0){
            if(btw>=10){
                return now+10;
            }else if(btw>5){
                return now+5;
            }else{
                return now+1;
            }
        }else if(btw<0){
            if(btw<=-10){
                return now-10;
            }else if(btw<-5){
                return now-5;
            }else{
                return now-1;
            }
        }else{
            return now;
        }
    }

    public:
    float CPUTemperature;
    float GPUTemperature;
    float RAMUsed;
    float GRAMUsed;
    HardwareData(){
        CPULoadNow = 0;
        CPULoadTGT = 0;
        CPUTemperatureNow = 0;
        CPUTemperatureTGT = 0;
    }

    void SetCPULoad(float LOAD){
        CPULoadTGT  = round(LOAD*2.7);
    }
    int GetCPULoadDegree(){
        return CPULoadNow;
    }

    void SetGPULoad(float LOAD){
        GPULoadTGT  = round(LOAD*2.7);
    }
    int GetGPULoadDegree(){
        return GPULoadNow;
    }

    void SetCPUTemperature(float Temperature){
        CPUTemperature = Temperature;
        CPUTemperatureTGT  = round(Temperature);
    }
    int GetCPUTemperatureNumber(){
        return CPUTemperatureNow;
    }

    void SetGPUTemperature(float Temperature){
        GPUTemperature = Temperature;
        GPUTemperatureTGT  = round(Temperature);
    }
    int GetGPUTemperatureNumber(){
        return GPUTemperatureNow;
    }

    void SetRAM(float ram){
        RAMUsed = ram;
        RAMTGT  = round(ram);
    }
    int GetRAMNumber(){
        return RAMNow;
    }

    void SetGRAM(float ram){
        GRAMUsed = ram;
        GRAMTGT  = round(ram);
    }
    int GetGRAMNumber(){
        return GRAMNow;
    }
    void step(){
        CPULoadNow = DataStep(CPULoadTGT,CPULoadNow);
        CPUTemperatureNow = DataStep(CPUTemperatureTGT,CPUTemperatureNow);
        RAMNow = DataStep(RAMTGT,RAMNow);
        GPULoadNow = DataStep(GPULoadTGT,GPULoadNow);
        GPUTemperatureNow = DataStep(GPUTemperatureTGT,GPUTemperatureNow);
        GRAMNow = DataStep(GRAMTGT,GRAMNow);
    }
};
#endif