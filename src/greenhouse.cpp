#pragma once
#include"../include/greenhouse.h"
#include"../include/watertank.h"

void GreenHouse::adjustLight(float luxSensorinput){
   

   if(luxSensorinput==-1){
       LEDlamp = 0;
   }

    // If lux is too low the led becomes brighter
   else if (luxSensorinput <= LEDLightwishedValue)
   {
        luxSensorValue=luxSensorinput;
        LEDlamp = LEDLightwishedValue - luxSensorinput;
   }
}
