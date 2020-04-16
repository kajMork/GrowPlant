#include"../include/watertank.h"

void Watertank::fillUp(float amount){
    if(amount > 1000)
        waterAmount = 1000;
    else
        waterAmount = amount;
};

// Do so it waters instead of just emptying
void Watertank::emptying(float amount){
    if(amount > waterAmount)
        waterAmount = 0;
    else
        waterAmount = waterAmount - amount;
};