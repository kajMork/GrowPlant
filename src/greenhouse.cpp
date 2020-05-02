#pragma once
#include"../include/greenhouse.h"
#include"../include/watertank.h"

void GreenHouse::adjustLight(float amount){
    if(amount > LEDLightMaxValue)
        LEDLightValue = LEDLightMaxValue;
    else
        LEDLightValue = amount;
};