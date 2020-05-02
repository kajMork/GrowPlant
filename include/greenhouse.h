#pragma once
#include <stdlib.h>
#include <time.h>

class GreenHouse
{
public:
    int getPlantSpacesAvailable(){ return plantSpaces; };
    void pumpWater(float amount);
    void adjustLight(float luxSensorinput);
    float getLedlampvalue(){return LEDlamp; };
    int getledwishedValue(){return LEDLightwishedValue;};
    float getluxSensorValue() {return luxSensorValue;};
    float getLEDLightValue(){ return LEDLightValue; };
    //void adjustLight(float amount);

    int getSoilMoisture(){ return soilMoisture; };
    void MoistureProcent(bool newSoil, double addedWater)
    {
        // Random soilmoisture if new soil is put in
        if (newSoil==true)
        {
            int RandomNumberNewSoil = rand() % 35 + 5;
            soilMoisture = RandomNumberNewSoil;
        }

        // Evaporation and adding water manipulates moisture
        if (soilMoisture > 2)
        {
            int numEvpapor = rand() % 5 + 1;

            soilMoisture = soilMoisture - numEvpapor/5 + addedWater;
        }
    }

private:
    float LEDLightValue;
    const int LEDLightMaxValue = 100;
    double soilMoisture=0;
    const int LEDLightwishedValue = 800;
    float LEDlamp = 0;
    int plantSpaces;
    float luxSensorValue;
};