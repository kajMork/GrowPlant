#include "../include/cucumber_plant.h"

void CucumberPlant::grow(int days) {
    height = height + days * growth_rate;
}