#pragma once
#include "../include/plant_base.h"
#include <stdlib.h>

class TomatoPlant : public PlantBase
{
public:
    float getHeight() override {return height;};
    int getNumTomatoes(){return num_tomatoes;};
    float getGrowthRate(){return growth_rate;};

    void setHeight(double newHeight) {height = newHeight;}
    void grow(int days) override;

private:
    float height{10.0};
    int num_tomatoes{0};

    // Since we need float values, and rand() only returns integer values, a cheap and easy fix is needed
    float currentRand = rand() % 300 + 100;
    float growth_rate{currentRand / 100};
    //rand() % 5 + 1
};
