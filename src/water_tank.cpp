#include"../include/water_tank.h"

void WaterTank::fillUp(float amount){
    empty = false;
    if(amount > 1000)
        waterAmount = 1000;
    else
        waterAmount = amount;
};

void WaterTank::emptying(float emptyingAmount){
    if(emptyingAmount > waterAmount && !empty)
        waterAmount = 0;
    else if(emptyingAmount < waterAmount && !empty)
        waterAmount = waterAmount - emptyingAmount;
    else
    {
        empty = true;
        waterAmount = 0;
    }
};