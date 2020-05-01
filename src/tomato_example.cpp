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

void simulateHours(PlantBase &a_plant, Watertank &waterTank, int hours, int waterNeedAmount, int plantsAmount){
        for (int i = 0; i < hours; i++)
        {
            if (a_plant.getHeight() <= a_plant.getMaxHeight())
            {
                waterTank.emptying(waterNeedAmount + (a_plant.getHeight() / 20 ));
            }
            
            if(waterTank.getWaterAmount() <= 0)
                waterTank.empty = true;
            else
                waterTank.empty = false;
            
            if(!waterTank.empty && a_plant.getHeight() <= a_plant.getMaxHeight())
                a_plant.grow(1);
            else break;
        }
}

void simulateOneDay(PlantBase &a_plant){
    a_plant.grow(1);
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
    int time = 8;
    int hoursToWait = 1;
    int totalHours = 0;
    int plantsAmount = 3;
    int luxSensorValue = 0;
    bool autoLight = true;
    std::string strAutoLight = "Automatic light";

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

    sf::Texture stalk;
    if(!stalk.loadFromFile("..\\pictures\\stalk.jpg")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    stalk.setSmooth(true);

    sf::Texture sun;
    if(!sun.loadFromFile("..\\pictures\\SunV3.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    sun.setSmooth(true);

    sf::Texture terase;
    if(!terase.loadFromFile("..\\pictures\\TeraseV2.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    terase.setSmooth(true);

    sf::Texture lightTex;
    if(!lightTex.loadFromFile("..\\pictures\\light_PNG14427.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    lightTex.setSmooth(true);


    sf::Texture sky;
    if(!sky.loadFromFile("..\\pictures\\Sky.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    stalk.setSmooth(true);
    const sf::Texture *pTexture = &stalk;

    sf::Sprite greenhouseSprite;
    greenhouseSprite.setTexture(greenhouseTex);
    greenhouseSprite.setPosition(100, 70);
    greenhouseSprite.setScale(0.8, 0.8);

    sf::Sprite sunSprite;
    sunSprite.setTexture(sun);
    sunSprite.setScale(0.4, 0.4);
    

    sf::Sprite teraseSprite;
    teraseSprite.setTexture(terase);
    teraseSprite.setPosition(-100,-100);
    teraseSprite.setScale(1, 1);

    sf::Sprite skySprite;
    skySprite.setTexture(sky);
    skySprite.setPosition(-100,-100);
    skySprite.setScale(0.7, 0.7);

    
    sf::Sprite lightSprite;
    lightSprite.setTexture(lightTex);
    lightSprite.setPosition(105,78);
    lightSprite.setScale(0.2, 0.2);
    
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
        ImGui::Begin("Time Controller");
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
                hoursToWait--;
            } ImGui::SameLine();
            if(ImGui::Button("Add hour")){
                hoursToWait++;
            }
            if(ImGui::Button("Wait one day")){
                simulateHours(my_plant, my_watertank, 24, 0.4, plantsAmount);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});

                // Second TomatoPlant
                simulateHours(my_plant2, my_watertank, 24, 0.4, plantsAmount);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});

                // Third TomatoPlant
                simulateHours(my_plant3, my_watertank, 24, 0.4, plantsAmount);
                tomatoStalk3.setSize(sf::Vector2f{5.0, -my_plant3.getHeight()});

                totalHours = totalHours + 24;
                
            } 

            if(ImGui::Button("Wait the hours")){
                // First TomatoPlant
                simulateHours(my_plant, my_watertank, hoursToWait, 0.4, plantsAmount);
                tomatoStalk.setSize(sf::Vector2f{5.0, -my_plant.getHeight()});

                // Second TomatoPlant
                simulateHours(my_plant2, my_watertank, hoursToWait, 0.4, plantsAmount);
                tomatoStalk2.setSize(sf::Vector2f{5.0, -my_plant2.getHeight()});

                // Third TomatoPlant
                simulateHours(my_plant3, my_watertank, hoursToWait, 0.4, plantsAmount);
                tomatoStalk3.setSize(sf::Vector2f{5.0, -my_plant3.getHeight()});

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

            ImGui::Begin("Light");
            std::string strLux = "Lux sensor: " + std::to_string(my_greenhouse.getluxSensorValue());
            std::string strLEDLux = "LED light lux: " + std::to_string(my_greenhouse.getLedlampvalue());
            std::string strSetting = "Light setting: " + strAutoLight;
            const char *c_Lux = strLux.c_str();
            const char *c_LEDLux = strLEDLux.c_str();
            const char *c_Setting = strSetting.c_str();
            ImGui::TextUnformatted(c_Lux);
            ImGui::TextUnformatted(c_LEDLux);
            ImGui::TextUnformatted(c_Setting);

            if(ImGui::Button("Automatic lights switch")){

                if (autoLight==true)
                {
                    strAutoLight = "Lights off";
                    autoLight=false;
                }
                else if (autoLight==false)
                {
                    strAutoLight = "Automatic light";
                    autoLight=true;
                }
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
            
            my_greenhouse.adjustLight(700-(getClock(totalHours)-20)*100);
            
            
        }
        //Keep the spritetextures dark from 24:00 to 05:00
        if (getClock(totalHours)>23 && getClock(totalHours)<=5 || getClock(totalHours)>=1 && getClock(totalHours)<=5)
        {
            window.clear(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            sunSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            skySprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            teraseSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            
            my_greenhouse.adjustLight(50);
       
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
            
            my_greenhouse.adjustLight(100);
            
        }
        //Keep the spritetextures light from 08:00 to 19:00
        if(getClock(totalHours)>7 && getClock(totalHours)<=19)
        {
            window.clear(sf::Color::White);
            sunSprite.setColor(sf::Color::White);
            skySprite.setColor(sf::Color::White);
            teraseSprite.setColor(sf::Color::White);
            
            my_greenhouse.adjustLight(750);
        }

    if(autoLight==true){
        lightSprite.setColor(sf::Color(255,255,255, my_greenhouse.getLedlampvalue()*0.3));

    }

    else if (autoLight==false)
    {
        lightSprite.setColor(sf::Color(255,255,255,0));
        my_greenhouse.adjustLight(-1);
    }
    

        //Update the suns position depending on the time of the day
        //sunYPos is calculated with the linear formular: 500x+17y=9450, where x = getClock().
        double sunYPos = (9450/17)-(500*getClock(totalHours))/17;
        sunSprite.setPosition(450,sunYPos);

        // Draw to screen
        window.draw(skySprite);
        window.draw(sunSprite);
        window.draw(teraseSprite);
        window.draw(greenhouseSprite);
        window.draw(tomatoStalk);
        window.draw(tomatoStalk2);
        window.draw(tomatoStalk3);
        window.draw(lightSprite);

        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}
