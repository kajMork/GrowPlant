#include"../include/tomato_plant.h"
#include"../include/watertank.h"


void TomatoPlant::grow(int days)
{
    height = height + days * growth_rate;
}
