#pragma once

class Watertank
{
    private:
    float waterAmount = 100;

    public:
    bool empty;
    float getWaterAmount(){return waterAmount;};
    void fillUp(float amount);
    void emptying(float amount);
};