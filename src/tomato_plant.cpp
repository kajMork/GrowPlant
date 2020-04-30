#include"../include/tomato_plant.h"
#include"../include/watertank.h"

void TomatoPlant::grow(int days, bool newSoil, double soilMoisture)
{
    if (newSoil==true)
    {
        height = 10.0;
    }
    else
    {
        height = height + days * growth_rate * (soilMoisture/40);
    }
}
