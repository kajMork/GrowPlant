#pragma once
#include <string>
class PlantBase
{
public:
    virtual float getHeight() = 0;

    virtual void grow(int days) = 0;

    virtual int getMaxHeight() = 0;

    virtual std::string getName();

private:
    
};


