#include"../include/tomato_plant.h"
void TomatoPlant::grow(int days)
{
    height = height + days * growth_rate;
}
