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

        void MoistureProcent(bool putSoil)
        {
            if (putSoil=true)
            {
               int RandomNumberNewSoil = rand() % 45 + 0;
               soilMoisture=RandomNumberNewSoil;
               putSoil=false;
            }
            int numEvpapor = rand() % 5 + 0;
            int evapor = numEvpapor/6;
            soilMoisture=soilMoisture-evapor;
        }
};