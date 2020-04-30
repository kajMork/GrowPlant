#pragma once
#include"../include/green_house.h"
#include"../include/water_tank.h"

// Do so it actoully gets water from watertank.
void GreenHouse::pumpWater(float amount){

};

void GreenHouse::adjustLight(float amount){
    if(amount > LEDLightMaxValue)
        LEDLightValue = LEDLightMaxValue;
    else
        LEDLightValue = amount;
};