#pragma once
#include <stdlib.h>
#include <time.h>

class GreenHouse
{
public:
    void pumpWater(float amount);
    void adjustLight(float luxSensorinput);
    float getLedlampvalue(){return LEDlamp; };
    int getledwishedValue(){return LEDLightwishedValue;};
    float getluxSensorValue() {return luxSensorValue;};
    float getLEDLightValue(){ return LEDLightValue; };
    int getSoilMoisture(){ return soilMoisture; };

    void MoistureProcent(bool newSoil, double addedWater)
    {
        // Random soil moisture if new soil is put in
        if (newSoil==true)
        {
            int RandomNumberNewSoil = rand() % 35 + 5;
            soilMoisture = RandomNumberNewSoil;
        }

        // Evaporation and adding water manipulates soil moisture
        if (soilMoisture > 2)
        {
            int numEvpapor = rand() % 5 + 1;

            soilMoisture = soilMoisture - numEvpapor/5 + addedWater;
        }
    }

private:
    float LEDLightValue;
    const int LEDLightMaxValue = 100;
    double soilMoisture = 0;
    const int LEDLightwishedValue = 800;
    float LEDlamp = 0;
    float luxSensorValue;
};