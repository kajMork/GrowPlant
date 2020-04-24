#pragma once
class PlantBase
{
public:
    virtual float getHeight() = 0;

    virtual void grow(int days) = 0;

    virtual int getMaxHeight() = 0;
private:
    
};


