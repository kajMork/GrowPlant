#pragma once
#include"../include/green_house.h"
#include"../include/water_tank.h"

void GreenHouse::adjustLight(float amount){
    if(amount > LEDLightMaxValue)
        LEDLightValue = LEDLightMaxValue;
    else
        LEDLightValue = amount;
};