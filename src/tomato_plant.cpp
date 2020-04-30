#include"../include/tomato_plant.h"
#include"../include/water_tank.h"

void TomatoPlant::grow(int hours, bool newSoil, double soilMoisture)
{
    if (newSoil==true)
    {
        height = 10.0;
    }
    else
    {
        height = height + hours * growth_rate * (soilMoisture/40);
    }
}
