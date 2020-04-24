#pragma once
#include "../include/plant_base.h"
#include <stdlib.h>

class CucumberPlant : public PlantBase
{

public:
    float getHeight() override {return height;};
    int getNumCucumbers(){return num_cucumbers;};

    void grow(int days) override;
private:
    double height{0.0};
    int num_cucumbers{0};
    int growth_rate{rand() % 3 + 1};
};


