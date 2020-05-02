#pragma once
#include <stdlib.h>
#include <time.h>

class GreenHouse
{
public:
    float getLEDLightValue(){ return LEDLightValue; };
    void adjustLight(float amount);

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
    int plantSpaces;
    double soilMoisture=0;
};