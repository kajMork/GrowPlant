#include"../include/tomato_plant.h"
#include"../include/water_tank.h"

void TomatoPlant::grow(int hours, bool newSoil, float soilMoisture)
{
    // If new soil and plants are put in pants reset
    if (newSoil==true)
    {
        height = 10.0;
    }
    // Height of plants are dependent on hours waited, growth rate and soilmoisture.
    else
    {
        height = height + hours * growth_rate * (soilMoisture/40);
    }
}
