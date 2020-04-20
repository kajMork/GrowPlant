#include "../include/tomato_plant.h"
#include "../include/cucumber_plant.h"
#include "../include/water_tank.h"
#include "../include/green_house.h"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iostream>
#include <chrono>
#include "SFML/Graphics.hpp"
#include "imgui.h"
#include "imgui-SFML.h"

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
        
        pumpingWater(my_greenHouse, my_watertank);

        if (my_watertank.getWaterAmount()==0)
        {
            cout << "WARNING: the water tank is empty" << endl;
        }
        else if (my_watertank.getWaterAmount()<=100)
        {
            cout << "WARNING: the water tank level is low" << endl;
        }
        
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
   /* using namespace std::chrono_literals;
    TomatoPlant my_tomato_plant;
    CucumberPlant my_cucumber_plant;
    simulateOneDay(my_tomato_plant);
    simulateOneDay(my_cucumber_plant);
    for (int i = 0; i < 5; i++)
    {
        simulateOneDay(my_tomato_plant);
        std::cout <<"plant height" << my_tomato_plant.getHeight() << "\n";
        std::this_thread::sleep_for(1s);
        
    }*/
    float stalk_length;
    sf::RectangleShape tomato_stalk {sf::Vector2f{5.0, 250}};
    tomato_stalk.setFillColor(sf::Color{0,255,0});
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(event);
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        ImGui::SFML::Update(window, deltaClock.restart());
        ImGui::Begin("Hello, world!");
        if (ImGui::SliderFloat("Length", &stalk_length, 0., 100.))
        {
            tomato_stalk.setSize(sf::Vector2f{5.0, stalk_length});
        }
        ImGui::End();
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        window.draw(tomato_stalk);
        ImGui::SFML::Render(window);
        // end the current frame
        window.display();
    }
    return 0;
}