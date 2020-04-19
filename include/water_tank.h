#pragma once

class waterTank
{
public:
    void fillUp(double fullTank)
    {
        waterAmount=fullTank;
        empty = false;
    };
    void emptying()
    {
        waterAmount=waterAmount-100;
        if (waterAmount==0)
        {
            empty = true;
        }
    };

    double getWaterAmount(){return waterAmount;};
    double getFullwaterAmount(){return fullwaterAmount;};
    bool getIsItEmpty(){return empty;};

private:
    float waterAmount = 0;
    float fullwaterAmount = 1000;
    bool empty = true;
};