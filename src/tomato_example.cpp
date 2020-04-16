#include"../include/tomato_plant.h"
#include"../include/cucumber_plant.h"
#include"waterTank.h"
#include "greenHouse.h"
#include<vector>
#include <ctime>
#include <cstdlib>

void simulateOneDay(PlantBase &a_plant)
{
    a_plant.grow(1);
}

void fillUpWater(waterTank &a_watertank)
{
    if (a_watertank.getWaterAmount()!=a_watertank.getFullwaterAmount());
    {
        a_watertank.fillUp(a_watertank.getFullwaterAmount());
    }
}

void pumpingWater(greenhouse &a_greenhouse, waterTank &a_watertank)
{
    if (a_watertank.getIsItEmpty()!=true)
    {
        a_watertank.emptying();
    }
}

int main(int argc, char const *argv[])
{
    TomatoPlant my_plant;
    CucumberPlant my_cucumber_plant;
    greenhouse B267a_greenhouse;
    waterTank my_watertank;

    simulateOneDay(my_plant);
    simulateOneDay(my_cucumber_plant);
    fillUpWater(my_watertank);
    pumpingWater(B267a_greenhouse, my_watertank);
    /*my_plant.grow(10);
    
    std::vector<TomatoPlant> my_greenhouse;
    my_greenhouse.push_back(my_plant);
    my_greenhouse.push_back(my_plant);
    my_greenhouse.push_back(my_plant);

    TomatoPlant new_tomatoplant = my_greenhouse[1];

    for (int i = 0; i < my_greenhouse.size(); i++)
    {
        my_greenhouse[i].grow(1);
    }
    
    for(TomatoPlant &p : my_greenhouse)
    {
        p.grow(1);
    }*/
    return 0;
}