#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/cucumber_plant.h"
#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/greenhouse.h"

void CucumberPlant::grow(int hours, bool newSoil, float soilMoisture) {
    
    // If new soil and plants are put in pants reset
    if (newSoil==true)
    {
        height = 5.0;
    }
    // Height of plants are dependent on hours waited, growth rate and soilmoisture.
    else
    {
        height = height + hours * growth_rate * (soilMoisture/35);
    }
}