#pragma once
#include "../include/plant_base.h"
#include "../include/green_house.h"
#include <stdlib.h>

class CucumberPlant : public PlantBase
{

public:
    float getHeight() override {return height;};
    int getNumCucumbers(){return num_cucumbers;};

    void grow(int days, bool newSoil, double soilMoisture) override;

    int getMaxHeight() override {return max_Height;};
private:
    double height{0.0};
    int num_cucumbers{0};
    int max_Height{110};
    
    // Since we need float values, and rand() only returns integer values, a cheap and easy fix is needed
    float currentRand = rand() % 250 + 150;
    float growth_rate{currentRand / 1200};
    //rand() % 5 + 1
};