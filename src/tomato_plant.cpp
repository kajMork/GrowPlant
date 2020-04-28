#include"../include/tomato_plant.h"
#include"../include/watertank.h"
#include"../include/greenhouse.h"

void TomatoPlant::grow(int days, bool newSoil, Greenhouse &a_greenhouse)
{
    if (newSoil==true)
    {
        height = 10.0;
    }
    else
    {
        height = height + days * growth_rate * (a_greenhouse.getSoilMoisture()/20);
    }
}
