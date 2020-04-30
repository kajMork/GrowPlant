#pragma once

class WaterTank
{
    private:
    float waterAmount = 1000;

    public:
    bool empty = false;
    float getWaterAmount(){return waterAmount;};
    void fillUp(float amount);
    void emptying(float amount);
};