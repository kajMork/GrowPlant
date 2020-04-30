#include "../include/cucumber_plant.h"
#include "../include/green_house.h"

void CucumberPlant::grow(int days, bool newSoil, double soilMoisture) {
    if (newSoil==true)
    {
        height = 5.0;
    }
    else
    {
        height = height + days * growth_rate * (soilMoisture/35);
    }
}