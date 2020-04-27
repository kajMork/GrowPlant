#pragma once
#include"../include/greenhouse.h"
#include"../include/watertank.h"

// Do so it actoully gets water from watertank.
void Greenhouse::pumpWater(float amount){

};

void Greenhouse::adjustLight(float amount){
    if(amount > LEDLightMaxValue)
        LEDLightValue = LEDLightMaxValue;
    else
        LEDLightValue = amount;
};