#include "../include/cucumber_plant.h"
#include "../include/greenhouse.h"

void CucumberPlant::grow(int days, bool newSoil, Greenhouse &a_greenhouse) {
    if (newSoil==true)
    {
        height = 10.0;
    }
    else
    {
        height = height + days * growth_rate * (a_greenhouse.getSoilMoisture()/30);
    }
}