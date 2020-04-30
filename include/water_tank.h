#pragma once

class WaterTank
{
public:
    bool empty = false;
    float getWaterAmount(){return waterAmount;};
    void fillUp(float amount);
    void emptying(float amount);
    
private:
    float waterAmount = 1000;


};