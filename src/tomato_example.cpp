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

void simulateDays(PlantBase &a_plant, Watertank &waterTank, int days, int waterNeedAmount){
    
    for (int i = 0; i < days; i++)
    {
        waterTank.emptying(waterNeedAmount + (a_plant.getHeight() / 10));

        if(waterTank.getWaterAmount() <= 0)
            waterTank.empty = true;
        else
            waterTank.empty = false;
        
        if(!waterTank.empty)
            a_plant.grow(1);
    }
}

int main(int argc, char const *argv[])
{
    // Define types
    TomatoPlant my_plant;
    TomatoPlant my_plant2;
    CucumberPlant my_cucumber_plant;
    Greenhouse my_greenhouse;
    Watertank my_watertank;

    // Variables
    int daysToWait = 1;

    // Set render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // sfml clock for updating
    sf::Clock deltaClock;

    // Tomato plant
    sf::RectangleShape tomatoStalk {sf::Vector2f{5.0, -my_plant.getHeight()}};
    tomatoStalk.setPosition(window.getSize().x / 2, window.getSize().y);
    tomatoStalk.setFillColor(sf::Color{0, 255, 0});
    
    // Tomato plant 2
    sf::RectangleShape tomatoStalk2 {sf::Vector2f{5.0, -my_plant2.getHeight()}};
    tomatoStalk2.setPosition( (window.getSize().x / 2) - 50, window.getSize().y);
    tomatoStalk2.setFillColor(sf::Color{255, 0, 0});

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
                simulateDays(my_plant, my_watertank, daysToWait, 10);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});

                // Second TomatoPlant
                simulateDays(my_plant2, my_watertank, daysToWait, 10);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});
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

        window.draw(tomatoStalk);
        window.draw(tomatoStalk2);

        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}
