#include "../include/tomato_plant.h"
#include "../include/cucumber_plant.h"
#include "../include/green_house.h"
#include "../include/water_tank.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

void simulateHours(PlantBase &a_plant, Watertank &waterTank, Greenhouse &a_greenhouse, int hours, int waterNeedAmount, int plantsAmount, bool putSoil){
    for (int i = 0; i <= hours; i++)
    {
        if (hours!=0)
        {
            a_greenhouse.MoistureProcent(putSoil, 0);
        }

        if (a_greenhouse.getSoilMoisture()<=16 && waterTank.getWaterAmount()>0)
        {
            waterTank.emptying(waterNeedAmount + (a_plant.getHeight() / 5));
            a_greenhouse.MoistureProcent(putSoil, waterNeedAmount + (a_plant.getHeight() / 20));
        }
        
        if(waterTank.getWaterAmount() <= 0)
        {
            waterTank.empty = true;
        }

        else
        {
            waterTank.empty = false;
        }
        
        if(a_plant.getHeight() <= a_plant.getMaxHeight() && a_greenhouse.getSoilMoisture()>7)
        {
            a_plant.grow(1, putSoil, a_greenhouse.getSoilMoisture());
        }
        else if (putSoil==true)
        {
            a_plant.grow(1, putSoil, a_greenhouse.getSoilMoisture());
        }
        else
        break;
    }
}

int getClock (int totalHours)
{   
    int timeclock = totalHours % 24 + 8;

    if (timeclock > 24)
    {
        timeclock = timeclock - 24;
    }

    return timeclock;
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
        
        //Starting time of simulation
        int time = 8;
        
        //Starting hours to wait of simulation
        int hoursToWait = 1;
        
        //Starting total hours spend of simulation
        int totalHours = 0;
        
        //Starting size of visual size of plant in simulation
        int plantsAmount = 2;
        
        //Starting change soil option in simulation
        bool putSoil=false;
        std::string strChangeSoil = "No";
        
        //Starting position of plants and branches in simulation
        
        //// Tomato plant 1
        //Tomato plant start position y-kooridnate
        int my_plantPosition = 289;
            //Tomato branch start position y-kooridnate
            double PosTomatoStalkBranch1 = my_plantPosition;
                double PosTomatoTomatoStalkBranch1 = my_plantPosition;
                double sizeTomatoes = 0.00;
            double PosTomatoStalkBranch2 = my_plantPosition;
            double PosTomatoStalkBranch3 = my_plantPosition;

        //// Tomato plant 2
        int my_plant2Position = 288;
        double PosTomatoStalk2Branch1 = my_plant2Position;
        double PosTomatoStalk2Branch2 = my_plant2Position;
        double PosTomatoStalk2Branch3 = my_plant2Position;

        //// Cucumber plant
        int my_cucumber_plantPosition = 488;
        double PosCucumberStalkBranch1 = my_cucumber_plantPosition;
        double PosCucumberStalkBranch2 = my_cucumber_plantPosition;
        double PosCucumberStalkBranch3 = my_cucumber_plantPosition;
        double PosCucumberStalkBranch4 = my_cucumber_plantPosition;
        double PosCucumberStalkBranch5 = my_cucumber_plantPosition;
        
    // Set render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

     // Texture rendering
    sf::Texture greenhouseTex;
    if(!greenhouseTex.loadFromFile("..\\pictures\\Drivhus_2_v5.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    greenhouseTex.setSmooth(true);

    sf::Texture tomatoesTex;
    if(!tomatoesTex.loadFromFile("..\\pictures\\tomatoes.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    tomatoesTex.setSmooth(true);

    sf::Texture cucumberTex;
    if(!cucumberTex.loadFromFile("..\\pictures\\Cucumber.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    cucumberTex.setSmooth(true);

    sf::Texture stalkTex;
    if(!stalkTex.loadFromFile("..\\pictures\\stalk.jpg")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    stalkTex.setSmooth(true);

    sf::Texture sunTex;
    if(!sunTex.loadFromFile("..\\pictures\\SunV3.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    sunTex.setSmooth(true);

    sf::Texture teraseTex;
    if(!teraseTex.loadFromFile("..\\pictures\\TeraseV2.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    teraseTex.setSmooth(true);

    sf::Texture sky;
    if(!sky.loadFromFile("..\\pictures\\Sky.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    sky.setSmooth(true);
    const sf::Texture *pTexture = &stalkTex;

    sf::Sprite greenhouseSprite;
    greenhouseSprite.setTexture(greenhouseTex);
    greenhouseSprite.setPosition(100, 70);
    greenhouseSprite.setScale(0.8, 0.8);

    sf::Sprite sunSprite;
    sunSprite.setTexture(sunTex);
    sunSprite.setScale(0.4, 0.4);

    sf::Sprite teraseSprite;
    teraseSprite.setTexture(teraseTex);
    teraseSprite.setPosition(-100,-100);
    teraseSprite.setScale(1, 1);

    sf::Sprite skySprite;
    skySprite.setTexture(sky);
    skySprite.setPosition(-100,-100);
    skySprite.setScale(0.7, 0.7);
    
    // sfml clock for updating
    sf::Clock deltaClock;

    // Tomato plant 1
    sf::RectangleShape tomatoStalk {sf::Vector2f{5.0, -my_plant.getHeight()}};
    tomatoStalk.setPosition(181, my_plantPosition);
    tomatoStalk.setTexture(pTexture);
        // Tomato plant brach 1
        sf::RectangleShape tomatoStalkBranch1 {sf::Vector2f{5.0, -my_plant.getHeight()/2}};
        tomatoStalkBranch1.setPosition(181, PosTomatoStalkBranch1);
        tomatoStalkBranch1.setTexture(pTexture);
        tomatoStalkBranch1.setRotation (70);
            sf::Sprite tomatoesSprite;
            tomatoesSprite.setTexture(tomatoesTex);
            tomatoesSprite.setPosition(my_plantPosition,my_plantPosition);
            tomatoesSprite.setScale(sizeTomatoes, sizeTomatoes);

        // Tomato plant brach 2
        sf::RectangleShape tomatoStalkBranch2 {sf::Vector2f{5.0, -my_plant.getHeight()/2}};
        tomatoStalkBranch2.setPosition(181, PosTomatoStalkBranch2);
        tomatoStalkBranch2.setTexture(pTexture);
        tomatoStalkBranch2.setRotation (-70);
        // Tomato plant brach 3
        sf::RectangleShape tomatoStalkBranch3 {sf::Vector2f{5.0, -my_plant.getHeight()/2}};
        tomatoStalkBranch3.setPosition(181, PosTomatoStalkBranch3);
        tomatoStalkBranch3.setTexture(pTexture);
        tomatoStalkBranch3.setRotation (70);
    
    // Tomato plant 2
    sf::RectangleShape tomatoStalk2 {sf::Vector2f{5.0, -my_plant2.getHeight()}};
    tomatoStalk2.setPosition(284, my_plant2Position);
    tomatoStalk2.setTexture(pTexture);
        sf::RectangleShape tomatoStalk2Branch1 {sf::Vector2f{5.0, -my_plant2.getHeight()/2}};
        tomatoStalk2Branch1.setPosition(284, PosTomatoStalk2Branch1);
        tomatoStalk2Branch1.setTexture(pTexture);
        tomatoStalk2Branch1.setRotation (70);
        // Tomato plant brach 2
        sf::RectangleShape tomatoStalk2Branch2 {sf::Vector2f{5.0, -my_plant2.getHeight()/2}};
        tomatoStalk2Branch2.setPosition(284, PosTomatoStalk2Branch2);
        tomatoStalk2Branch2.setTexture(pTexture);
        tomatoStalk2Branch2.setRotation (-70);
        // Tomato plant brach 3
        sf::RectangleShape tomatoStalk2Branch3 {sf::Vector2f{5.0, -my_plant2.getHeight()/2}};
        tomatoStalk2Branch3.setPosition(284, PosTomatoStalk2Branch3);
        tomatoStalk2Branch3.setTexture(pTexture);
        tomatoStalk2Branch3.setRotation (70);

    // Cucumber plant
    sf::RectangleShape CucumberStalk {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()}};
    CucumberStalk.setPosition(230, my_cucumber_plantPosition);
    CucumberStalk.setTexture(pTexture);
    sf::RectangleShape CucumberStalkBranch1 {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2}};
        CucumberStalkBranch1.setPosition(230, PosCucumberStalkBranch1);
        CucumberStalkBranch1.setTexture(pTexture);
        CucumberStalkBranch1.setRotation (90);
        // Cucumber plant brach 1
        sf::RectangleShape CucumberStalkBranch2 {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2}};
        CucumberStalkBranch2.setPosition(230, PosCucumberStalkBranch2);
        CucumberStalkBranch2.setTexture(pTexture);
        CucumberStalkBranch2.setRotation (-90);
        // Cucumber plant brach 2
        sf::RectangleShape CucumberStalkBranch3 {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2}};
        CucumberStalkBranch3.setPosition(230, PosCucumberStalkBranch3);
        CucumberStalkBranch3.setTexture(pTexture);
        CucumberStalkBranch3.setRotation (70);
        // Cucumber plant brach 3
        sf::RectangleShape CucumberStalkBranch4 {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2}};
        CucumberStalkBranch4.setPosition(230, PosCucumberStalkBranch4);
        CucumberStalkBranch4.setTexture(pTexture);
        CucumberStalkBranch4.setRotation (-70);
        // Cucumber plant brach 4
        sf::RectangleShape CucumberStalkBranch5 {sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2}};
        CucumberStalkBranch5.setPosition(230, PosCucumberStalkBranch5);
        CucumberStalkBranch5.setTexture(pTexture);
        CucumberStalkBranch5.setRotation (60);

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

            // Soil changing
            ImGui::Begin("Soil");
            std::string strsoilMoisture = "Soilmoisture: " + std::to_string(my_greenhouse.getSoilMoisture());
            std::string strSoilChange = "Here you can change \nsoil and plants.\n\nREMEMBER to change the \nsoil and plants when \nyou start the simulation.";
            const char *cc_SoilMoisture = strsoilMoisture.c_str();
            const char *cc_SoilChange = strSoilChange.c_str();
            ImGui::TextUnformatted(cc_SoilMoisture);
            ImGui::TextUnformatted(cc_SoilChange);
            
            if(ImGui::Button("Change")){
                putSoil=true;
                simulateHours(my_plant, my_watertank, my_greenhouse, 1, 0.4, plantsAmount, putSoil);
                putSoil=false;
            }
            
            ImGui::End();

            ImGui::Begin("Controller");
            // Being able to see and change how many Hours the user wants to wait
            // Being able to track total hours and time of the day. 
            std::string strHours = "Hours to wait: " + std::to_string(hoursToWait);
            std::string strTotalTime = "Total time waited: ";
            std::string strTotalDays =  std::to_string((int)totalHours/24) + " day(s).";
            std::string strTotalHours = std::to_string((int)totalHours % 24) + " hour(s).";
            std::string strClock = "Clock: " + std::to_string((int)getClock(totalHours)) + ":00";
            const char *cc_Hours = strHours.c_str();
            const char *cc_TotalTime = strTotalTime.c_str();
            const char *cc_TotalDays = strTotalDays.c_str();
            const char *cc_TotalHours = strTotalHours.c_str();
            const char *cc_Clock = strClock.c_str();
            ImGui::TextUnformatted(cc_Hours);
            ImGui::TextUnformatted(cc_TotalTime);
            ImGui::TextUnformatted(cc_TotalDays);
            ImGui::TextUnformatted(cc_TotalHours);
            ImGui::TextUnformatted(cc_Clock);

            if(ImGui::Button("Remove hour")){
                if (hoursToWait>1)
                {
                    hoursToWait--;
                }
            } ImGui::SameLine();
            if(ImGui::Button("Add hour")){
                hoursToWait++;
            }
            if(ImGui::Button("Wait one day")){
                // Tomato plant 1
                simulateHours(my_plant, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});
                    PosTomatoStalkBranch1 = (- my_plant.getHeight()/1.5) + 289;
                    PosTomatoStalkBranch2 = (- my_plant.getHeight()/2) + 289;
                    PosTomatoStalkBranch3 = (- my_plant.getHeight()/4) + 289;
                    tomatoStalkBranch1.setPosition(181, PosTomatoStalkBranch1);
                        tomatoesSprite.setPosition(187 , PosTomatoStalkBranch1 - PosTomatoStalkBranch1 / 70);
                        tomatoesSprite.setScale(my_plant.getHeight()/3000, my_plant.getHeight()/3000);
                    tomatoStalkBranch2.setPosition(181, PosTomatoStalkBranch2);
                    tomatoStalkBranch3.setPosition(181, PosTomatoStalkBranch3);
                    tomatoStalkBranch1.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/2});
                    tomatoStalkBranch2.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/3});
                    tomatoStalkBranch3.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/3});

                // Tomato plant 2
                simulateHours(my_plant2, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});
                PosTomatoStalk2Branch1 = (-my_plant2.getHeight()/1.5)+my_plant2Position;
                PosTomatoStalk2Branch2 = (-my_plant2.getHeight()/2)+my_plant2Position;
                PosTomatoStalk2Branch3 = (-my_plant2.getHeight()/4)+my_plant2Position;
                tomatoStalk2Branch1.setPosition(284, PosTomatoStalk2Branch1);
                tomatoStalk2Branch2.setPosition(284, PosTomatoStalk2Branch2);
                tomatoStalk2Branch3.setPosition(284, PosTomatoStalk2Branch3);
                tomatoStalk2Branch1.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/3});
                tomatoStalk2Branch2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/2});
                tomatoStalk2Branch3.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/3});

                // Cucumber plant
                simulateHours(my_cucumber_plant, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                CucumberStalk.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()});
                PosCucumberStalkBranch1 = (-my_cucumber_plant.getHeight()/1.2)+my_cucumber_plantPosition;
                PosCucumberStalkBranch2 = (-my_cucumber_plant.getHeight()/2)+my_cucumber_plantPosition;
                PosCucumberStalkBranch3 = (-my_cucumber_plant.getHeight()/3)+my_cucumber_plantPosition;
                PosCucumberStalkBranch4 = (-my_cucumber_plant.getHeight()/4)+my_cucumber_plantPosition;
                PosCucumberStalkBranch5 = (-my_cucumber_plant.getHeight()/5)+my_cucumber_plantPosition;
                CucumberStalkBranch1.setPosition(230, PosCucumberStalkBranch1);
                CucumberStalkBranch2.setPosition(230, PosCucumberStalkBranch2);
                CucumberStalkBranch3.setPosition(230, PosCucumberStalkBranch3);
                CucumberStalkBranch4.setPosition(230, PosCucumberStalkBranch4);
                CucumberStalkBranch5.setPosition(230, PosCucumberStalkBranch5);
                CucumberStalkBranch1.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});
                CucumberStalkBranch2.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2});
                CucumberStalkBranch3.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});
                CucumberStalkBranch4.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2});
                CucumberStalkBranch5.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});

                totalHours = totalHours + 24;
            }

            if(ImGui::Button("Wait the hours")){
                // Tomato plant
                simulateHours(my_plant, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});
                PosTomatoStalkBranch1 = (-my_plant.getHeight()/1.5)+my_plantPosition;
                PosTomatoStalkBranch2 = (-my_plant.getHeight()/2)+my_plantPosition;
                PosTomatoStalkBranch3 = (-my_plant.getHeight()/4)+my_plantPosition;
                tomatoStalkBranch1.setPosition(181, PosTomatoStalkBranch1);
                tomatoStalkBranch2.setPosition(181, PosTomatoStalkBranch2);
                tomatoStalkBranch3.setPosition(181, PosTomatoStalkBranch3);
                tomatoStalkBranch1.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/2});
                tomatoStalkBranch2.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/3});
                tomatoStalkBranch3.setSize(sf::Vector2f{5.0, -my_plant.getHeight()/3});

                // Tomato plant 2
                simulateHours(my_plant2, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});
                PosTomatoStalk2Branch1 = (-my_plant2.getHeight()/1.5)+my_plant2Position;
                PosTomatoStalk2Branch2 = (-my_plant2.getHeight()/2)+my_plant2Position;
                PosTomatoStalk2Branch3 = (-my_plant2.getHeight()/4)+my_plant2Position;
                tomatoStalk2Branch1.setPosition(284, PosTomatoStalk2Branch1);
                tomatoStalk2Branch2.setPosition(284, PosTomatoStalk2Branch2);
                tomatoStalk2Branch3.setPosition(284, PosTomatoStalk2Branch3);
                tomatoStalk2Branch1.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/3});
                tomatoStalk2Branch2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/2});
                tomatoStalk2Branch3.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()/3});

                // Cucumber plant
                simulateHours(my_cucumber_plant, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                CucumberStalk.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()});
                PosCucumberStalkBranch1 = (-my_cucumber_plant.getHeight()/1.2)+my_cucumber_plantPosition;
                PosCucumberStalkBranch2 = (-my_cucumber_plant.getHeight()/2)+my_cucumber_plantPosition;
                PosCucumberStalkBranch3 = (-my_cucumber_plant.getHeight()/3)+my_cucumber_plantPosition;
                PosCucumberStalkBranch4 = (-my_cucumber_plant.getHeight()/4)+my_cucumber_plantPosition;
                PosCucumberStalkBranch5 = (-my_cucumber_plant.getHeight()/5)+my_cucumber_plantPosition;
                CucumberStalkBranch1.setPosition(230, PosCucumberStalkBranch1);
                CucumberStalkBranch2.setPosition(230, PosCucumberStalkBranch2);
                CucumberStalkBranch3.setPosition(230, PosCucumberStalkBranch3);
                CucumberStalkBranch4.setPosition(230, PosCucumberStalkBranch4);
                CucumberStalkBranch5.setPosition(230, PosCucumberStalkBranch5);
                CucumberStalkBranch1.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});
                CucumberStalkBranch2.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2});
                CucumberStalkBranch3.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});
                CucumberStalkBranch4.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/2});
                CucumberStalkBranch5.setSize(sf::Vector2f{5.0, -my_cucumber_plant.getHeight()/3});

                totalHours = totalHours + hoursToWait;
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
            
        //Update spritetextures color for the time of the day.
        double rgb_codenight;
        double rgb_codeday;
        ImGui::End();
        //Daylight disappears from 20:00 to 24:00 
        if (getClock(totalHours)>19 && getClock(totalHours)<25)
        {   
            //Make spritetextures darker for each incremented hour. 
            rgb_codenight = 255-(getClock(totalHours)-20)*48.75;
            sunSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            skySprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            teraseSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            window.clear(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
        }
        //Keep the spritetextures dark from 24:00 to 05:00
        if (getClock(totalHours)>23 && getClock(totalHours)<=5 || getClock(totalHours)>=1 && getClock(totalHours)<=5)
        {
            window.clear(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            sunSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            skySprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            teraseSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
        }
        //Daylight appears from 06:00 to 08:00
        if (getClock(totalHours)>5 && getClock(totalHours)<8)
        {
            //Make spritetextures lighter for each incremented hour. 
            rgb_codeday = rgb_codenight+(getClock(totalHours)-4)*48.75;
            sunSprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            skySprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            teraseSprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            window.clear(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
        }
        //Keep the spritetextures light from 08:00 to 19:00
        if(getClock(totalHours)>7 && getClock(totalHours)<=19)
        {
            window.clear(sf::Color::White);
            sunSprite.setColor(sf::Color::White);
            skySprite.setColor(sf::Color::White);
            teraseSprite.setColor(sf::Color::White);
        }
        //Update the suns position depending on the time of the day
        //sunYPos is calculated with the linear formular: 500x+17y=9450, where x = getClock().
        double sunYPos = (9450/17)-(500*getClock(totalHours))/17 ;
        sunSprite.setPosition(450,sunYPos);
        

        // Draw to screen
        window.draw(skySprite);
        window.draw(sunSprite);
        window.draw(teraseSprite);
        window.draw(greenhouseSprite);
        window.draw(tomatoStalk);
            window.draw(tomatoStalkBranch1);
            window.draw(tomatoStalkBranch2);
            window.draw(tomatoStalkBranch3);

        window.draw(tomatoStalk2);
            window.draw(tomatoStalk2Branch1);
            window.draw(tomatoStalk2Branch2);
            window.draw(tomatoStalk2Branch3);

        window.draw(CucumberStalk);
            window.draw(CucumberStalkBranch1);
                window.draw(tomatoesSprite);

            window.draw(CucumberStalkBranch2);
            window.draw(CucumberStalkBranch3);
            window.draw(CucumberStalkBranch4);
            window.draw(CucumberStalkBranch5);

        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}