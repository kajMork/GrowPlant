#pragma once
#include "../include/green_house.h"

class PlantBase
{
public:
    virtual float getHeight() = 0;
    virtual void grow(int hours, bool newSoil, float soilMoisture) = 0;
    virtual int getMaxHeight() = 0;
    
private:
    
};