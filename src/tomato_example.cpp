#include "../include/tomato_plant.h"
#include "../include/cucumber_plant.h"
#include "../include/water_tank.h"
#include "../include/green_house.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

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

void pumpingWater(greenHouse &a_greenhouse, waterTank &a_watertank)
{
    if (a_watertank.getIsItEmpty()!=true)
    {
        a_watertank.emptying();
    }
}

int main(int argc, char const *argv[])
{
    TomatoPlant my_tomato_plant;
    CucumberPlant my_cucumber_plant;
    greenHouse my_greenHouse;
    waterTank my_watertank;

    bool waitFillUp = false;
    bool end = false;
    

    while (end==false)
    {
        simulateOneDay(my_tomato_plant);
        simulateOneDay(my_cucumber_plant);
        cout << "Do you want to fill up water? Type 0 for yes or 1 for no" << endl;
        cin >> waitFillUp;
        if (waitFillUp!=true)
        {
            fillUpWater(my_watertank);
        }
        
        if (my_watertank.getWaterAmount()==0)
        {
            cout << "WARNING: the water tank is empty" << endl;
        }
        else if (my_watertank.getWaterAmount()<=100)
        {
            cout << "WARNING: the water tank level is low" << endl;
        }

        pumpingWater(my_greenHouse, my_watertank);
        cout << "Height of tomato plant: " << my_tomato_plant.getHeight() << endl;
        cout << "Height of cucumber plant: " << my_cucumber_plant.getHeight() << endl;
        cout << "Watertank level: " << my_watertank.getWaterAmount() << endl;
    }
    /*my_plant.grow(10);'
    
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