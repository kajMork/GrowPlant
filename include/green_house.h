#pragma once

class greenHouse
{
public:
    int plantSpaces = 0;
    void adjustLight(float differenceInLightamount);

private:
    float lightAmount{0};
    float LEDLightValue{0};
    float soil_moisture = 10 //%
};