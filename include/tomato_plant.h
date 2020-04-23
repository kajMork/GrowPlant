#pragma once
#include <plant_base.h>

class TomatoPlant : public PlantBase
{
public:
    double getHeight() override { return height;};
    void grow(int days) override;

    int getNumTomatoes() { return num_tomatoes;};

    
private:
    double height{0.0};
    int num_tomatoes{0};
    double growth_rate{2.0};
};