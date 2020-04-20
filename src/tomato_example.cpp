#include"../include/tomato_plant.h"
#include"../include/cucumber_plant.h"
#include"waterTank.h"
#include "greenHouse.h"
#include<vector>


void simulateOneDay(PlantBase &a_plant){
    a_plant.grow(1);
}
int main(int argc, char const *argv[])
{
    TomatoPlant my_plant;
    CucumberPlant my_cucumber_plant;

    simulateOneDay(my_plant);
    simulateOneDay(my_cucumber_plant);
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
