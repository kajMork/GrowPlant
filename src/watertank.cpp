#include"../include/watertank.h"

void Watertank::fillUp(float amount){
    empty = false;
    if(amount > 1000)
        waterAmount = 1000;
    else
        waterAmount = amount;
};

// Do so it waters instead of just emptying
void Watertank::emptying(float amount){
    if(amount > waterAmount && !empty)
        waterAmount = 0;
    else if(amount < waterAmount && !empty)
        waterAmount = waterAmount - amount;
    else
    {
        empty = true;
        waterAmount = 0;
    }

};