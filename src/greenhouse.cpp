#pragma once
#include"/Users/madsrossen/Documents/GitHub/GrowPlant/include/greenhouse.h"
#include"/Users/madsrossen/Documents/GitHub/GrowPlant/include/watertank.h"

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
