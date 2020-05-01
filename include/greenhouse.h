#pragma once

class Greenhouse
{
    private:
    const int LEDLightwishedValue = 800;
    float LEDlamp;
    int plantSpaces;

    public:

    int getPlantSpacesAvailable(){ return plantSpaces; };
    void pumpWater(float amount);
    void adjustLight(float luxSensorValue);
    float getLedlampvalue(){return LEDlamp; };
    int getledwishedValue(){return LEDLightwishedValue;};
};