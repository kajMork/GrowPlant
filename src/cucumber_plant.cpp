#include "../include/cucumber_plant.h"
#include "../include/greenhouse.h"

void CucumberPlant::grow(int days, bool newSoil, double soilMoisture) {
    if (newSoil==true)
    {
        height = 5.0;
    }
    else
    {
        height = height + days * growth_rate * (soilMoisture/30);
    }
}