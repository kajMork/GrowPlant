#pragma once

class Greenhouse
{
    private:
    float LEDLightValue;
    const int LEDLightMaxValue = 100;
    int plantSpaces;

    public:
    float getLEDLightValue(){ return LEDLightValue; };
    int getPlantSpacesAvailable(){ return plantSpaces; };
    void pumpWater(float amount);
    void adjustLight(float amount);
};