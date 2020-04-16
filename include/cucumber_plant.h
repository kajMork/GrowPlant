#pragma once
#include "../include/plant_base.h"

class CucumberPlant : public PlantBase
{

public:
    double getHeight() override{return height;};
    int getNumCucumbers(){return num_cucumbers;};

    void grow(int days) override;
private:
    double height{0.0};
    int num_cucumbers{0};
    double growth_rate{1.0};
};


