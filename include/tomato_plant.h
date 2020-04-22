#pragma once
#include "../include/plant_base.h"

class TomatoPlant : public PlantBase
{
public:
    double getHeight() override {return height;};
    int getNumTomatoes(){return num_tomatoes;};

    void grow(int days) override;

private:
    double height{0.0};
    int num_tomatoes{0};
    double growth_rate{2.0};

};
