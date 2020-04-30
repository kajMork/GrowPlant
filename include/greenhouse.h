#pragma once
#include <stdlib.h>
#include <time.h>

class Greenhouse
{
    private:
        float LEDLightValue;
        const int LEDLightMaxValue = 100;
        int plantSpaces;
        double soilMoisture=0;

    public:
        float getLEDLightValue(){ return LEDLightValue; };
        int getPlantSpacesAvailable(){ return plantSpaces; };
        void pumpWater(float amount);
        void adjustLight(float amount);
        int getSoilMoisture(){ return soilMoisture; };

        void MoistureProcent(bool newSoil, double addedWater)
        {
            if (newSoil==true)
            {
               int RandomNumberNewSoil = rand() % 35 + 0;
               soilMoisture = RandomNumberNewSoil;
            }

            if (soilMoisture > 0)
            {
                int numEvpapor = rand() % 5 + 1;

                soilMoisture = soilMoisture - numEvpapor/5 + addedWater;
            }
        }
};