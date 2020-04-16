#include"../include/tomato_plant.h"
#include"../include/cucumber_plant.h"
#include"../include/greenhouse.h"
#include"../include/watertank.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include"SFML/Graphics.hpp"

#include<vector>
#include<iostream>


void simulateOneDay(PlantBase &a_plant){
    a_plant.grow(1);
}

int main(int argc, char const *argv[])
{
    TomatoPlant my_plant;
    CucumberPlant my_cucumber_plant;
    Greenhouse my_greenhouse;
    Watertank my_watertank;

    simulateOneDay(my_plant);
    simulateOneDay(my_cucumber_plant);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock deltaClock;

    float rectangleLength;
    sf::RectangleShape tomatoStalk {sf::Vector2f{5.0, rectangleLength}};
    tomatoStalk.setFillColor(sf::Color{0, 255, 0});

    while (window.isOpen()){

        sf::Event event;

        while (window.pollEvent(event))
        {    
            ImGui::SFML::ProcessEvent(event);
            if(event.type == sf::Event::Closed) window.close();
        }

        ImGui::SFML::Update(window, deltaClock.restart());


        // UI SEGMENTS //
        ImGui::Begin("length Of Stalk");
        if (ImGui::SliderFloat("Length", &rectangleLength, 0., 100.)){
            tomatoStalk.setSize(sf::Vector2f{5.0, rectangleLength});
        }
        ImGui::End();

        ImGui::Begin("Watertank");
        
        if(ImGui::Button("Water plants")){
            my_watertank.emptying(10);
            tomatoStalk.setSize(sf::Vector2f{5.0, rectangleLength + 10});
        }
        ImGui::End();

        window.clear(sf::Color::Black);

        window.draw(tomatoStalk);

        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}
