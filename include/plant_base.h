#pragma once
#include "../include/green_house.h"

class PlantBase
{
public:
    virtual float getHeight() = 0;

    virtual void grow(int hours, bool newSoil, double soilMoisture) = 0;

    virtual int getMaxHeight() = 0;
private:
    
};