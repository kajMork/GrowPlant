#pragma once
#include "../include/plant_base.h"
#include <stdlib.h>

class TomatoPlant : public PlantBase
{
public:
    float getHeight() override {return height;};
    int getNumTomatoes(){return num_tomatoes;};

    void setHeight(double newHeight) {height = newHeight;}
    void grow(int days) override;

private:
    float height{10.0};
    int num_tomatoes{0};
    int growth_rate{rand() % 5 + 1};
    //
};
