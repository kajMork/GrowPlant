#pragma once
#include"../include/greenhouse.h"
#include"../include/watertank.h"

// Do so it actoully gets water from watertank.
void Greenhouse::pumpWater(float amount){

};

void Greenhouse::adjustLight(float luxSensorValue,Greenhouse &a_greenhouse){
     int lowLightValue=0;
     
     if (luxSensorValue < LEDLightwishedValue)
     {
        luxSensorValue=1;
     }
     
           
      while (luxSensorValue<LEDLightwishedValue)
      {
         LEDlamp 

      }
          

};