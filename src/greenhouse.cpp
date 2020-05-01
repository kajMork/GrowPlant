#pragma once
#include"../include/greenhouse.h"
#include"../include/watertank.h"

// Do so it actoully gets water from watertank.
void Greenhouse::pumpWater(float amount){

};

void Greenhouse::adjustLight(float luxSensorinput){
   
   if(luxSensorinput==-1){
       LEDlamp=0;
   }

   else if (luxSensorinput <= LEDLightwishedValue)
   {
        luxSensorValue=luxSensorinput;
        LEDlamp=LEDLightwishedValue-luxSensorinput;
   }
};