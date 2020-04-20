#include "../include/tomato_plant.h"
#include "../include/cucumber_plant.h"
#include "../include/greenhouse.h"
#include "../include/watertank.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

void simulateDays(PlantBase &a_plant, Watertank &waterTank, int days, int waterNeedAmount, int plantsAmount){
    
    for (int i = 0; i < plantsAmount; i++)
    {
        for (int i = 0; i < days; i++)
        {
            waterTank.emptying(waterNeedAmount + (a_plant.getHeight() / 10));

            if(waterTank.getWaterAmount() <= 0)
                waterTank.empty = true;
            else
                waterTank.empty = false;
            
            if(!waterTank.empty)
                a_plant.grow(1);
            else break;
        }
    } 

}

int main(int argc, char const *argv[])
{
    // Set random number generation clock
    srand(time(NULL));
    
    // Define types
    TomatoPlant my_plant;
    TomatoPlant my_plant2;
    TomatoPlant my_plant3;
    CucumberPlant my_cucumber_plant;
    Greenhouse my_greenhouse;
    Watertank my_watertank;

    std::cout << "First plant: " << my_plant.getGrowthRate() << std::endl;
    std::cout << "Second plant: " << my_plant2.getGrowthRate() << std::endl;
    std::cout << "Third plant: " << my_plant3.getGrowthRate() << std::endl;

    // Variables
    int daysToWait = 1;
    int plantsAmount = 3;

    // Set render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // Texture rendering
    sf::Texture greenhouseTex;
    if(!greenhouseTex.loadFromFile("C:/Users/ejer/Desktop/DrivhusKode/GrowPlant/pictures/Drivhus_2_v5.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    greenhouseTex.setSmooth(true);

    sf::Texture stalk;
    if(!stalk.loadFromFile("C:/Users/ejer/Desktop/DrivhusKode/GrowPlant/pictures/stalk.jpg")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    stalk.setSmooth(true);

    const sf::Texture *pTexture = &stalk;

    sf::Sprite greenhouseSprite;
    greenhouseSprite.setTexture(greenhouseTex);
    greenhouseSprite.setPosition(100, 70);
    greenhouseSprite.setScale(0.8, 0.8);

    
    // sfml clock for updating
    sf::Clock deltaClock;

    // Tomato plant
    sf::RectangleShape tomatoStalk {sf::Vector2f{5.0, -my_plant.getHeight()}};
    tomatoStalk.setPosition(181, 289);
    tomatoStalk.setTexture(pTexture);
    
    // Tomato plant 2
    sf::RectangleShape tomatoStalk2 {sf::Vector2f{5.0, -my_plant2.getHeight()}};
    tomatoStalk2.setPosition(284, 288);
    tomatoStalk2.setTexture(pTexture);

    // Tomato plant 3
    sf::RectangleShape tomatoStalk3 {sf::Vector2f{5.0, -my_plant3.getHeight()}};
    tomatoStalk3.setPosition(174, 488);
    tomatoStalk3.setTexture(pTexture);

    while (window.isOpen()){

        sf::Event event;

        // Break the while loop if we close the window
        while (window.pollEvent(event))
        {    
            ImGui::SFML::ProcessEvent(event);
            if(event.type == sf::Event::Closed) window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());

    // UI SEGMENTS //

        // Plant simulator controller
        ImGui::Begin("Controller");
            // Being able to see and change how many days the user wants to wait
            std::string strDays = "Days to wait: " + std::to_string(daysToWait);
            const char *cd = strDays.c_str();
            ImGui::TextUnformatted(cd);

            if(ImGui::Button("Remove day")){
                daysToWait--;
            } ImGui::SameLine();
            if(ImGui::Button("Add day")){
                daysToWait++;
            } 

            if(ImGui::Button("Wait the days")){
                // First TomatoPlant
                simulateDays(my_plant, my_watertank, daysToWait, 10, plantsAmount);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});

                // Second TomatoPlant
                simulateDays(my_plant2, my_watertank, daysToWait, 10, plantsAmount);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});

                // Third TomatoPlant
                simulateDays(my_plant3, my_watertank, daysToWait, 10, plantsAmount);
                tomatoStalk3.setSize(sf::Vector2f{5.0, -my_plant3.getHeight()});
            } 

            // Show water amount and add button for refill
            ImGui::Begin("Watertank");
            std::string str = "Water left: " + std::to_string(my_watertank.getWaterAmount());
            const char *c = str.c_str();
            ImGui::TextUnformatted(c);
            if(ImGui::Button("Fill watertank")){
                my_watertank.fillUp(1000);
            }
            ImGui::End();
            
            // Show LED lights and their value, button for changing value.

        ImGui::End();

        window.clear(sf::Color::Black);

        // Draw to screen
        window.draw(greenhouseSprite);
        window.draw(tomatoStalk);
        window.draw(tomatoStalk2);
        window.draw(tomatoStalk3);

        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}
