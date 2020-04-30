#pragma once
#include"../include/green_house.h"
#include"../include/water_tank.h"

// Do so it actoully gets water from watertank.
void Greenhouse::pumpWater(float amount){

};

void Greenhouse::adjustLight(float amount){
    if(amount > LEDLightMaxValue)
        LEDLightValue = LEDLightMaxValue;
    else
        LEDLightValue = amount;
};