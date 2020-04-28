#pragma once
#include <stdlib.h>

class Greenhouse
{
    private:
        float LEDLightValue;
        const int LEDLightMaxValue = 100;
        int plantSpaces;
        int soilMoisture=0;

    public:
        float getLEDLightValue(){ return LEDLightValue; };
        int getPlantSpacesAvailable(){ return plantSpaces; };
        void pumpWater(float amount);
        void adjustLight(float amount);
        int getSoilMoisture(){ return soilMoisture; };

        void MoistureProcent(bool newSoil, int addedWater)
        {
            if (newSoil==true)
            {
               int RandomNumberNewSoil = rand() % 45 + 5;
               soilMoisture = RandomNumberNewSoil;
            }

            if (soilMoisture > 0)
            {
                int numEvpapor = rand() % 2 + 0;
                
                soilMoisture = soilMoisture - numEvpapor + addedWater/5;
            }
        }
};