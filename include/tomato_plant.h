#pragma once
#include "../include/plant_base.h"
#include "../include/green_house.h"
#include <stdlib.h>

class TomatoPlant : public PlantBase
{
public:
    float getHeight() override {return height;};
    void grow(int hours, bool newSoil, float soilMoisture) override;
    int getMaxHeight() override {return max_Height;};

private:
    float height{10.0};
    int num_tomatoes{0};
    int max_Height{110};

    // Since we need float values, and rand() only returns integer values, a cheap and easy fix is needed
    float currentRand = rand() % 300 + 100;
    float growth_rate{currentRand / 1200};
};