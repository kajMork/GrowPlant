#pragma once

class waterTank
{
public:
    void fillUp();
    void emtying(float waterEmptyed);
    double getWaterAmount();

private:
    float waterAmount = 0;
    float fullwaterAmount = 1000;
    bool empty = false;
};