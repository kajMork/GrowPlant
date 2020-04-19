#pragma once

class lightRegulation
{
public:
    
    
    
    double getLUXlevel(){return LUXSensor;};
    double getwishedLUXlevel(){return wished_luxLevel;};
   
    void adjustlight(int value){
        LEDLightValue=value;
    };



private:
    float LUXSensor{0};
    float LEDLightValue{0};
    float wished_luxLevel{500};
};