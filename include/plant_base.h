#pragma once
#include "../include/greenhouse.h"

class PlantBase
{
public:
    virtual float getHeight() = 0;

    virtual void grow(int days, bool newSoil, Greenhouse &a_greenhouse) = 0;

    virtual int getMaxHeight() = 0;
private:
    
};


