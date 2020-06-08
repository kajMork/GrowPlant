#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/tomato_plant.h"
#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/cucumber_plant.h"
#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/greenhouse.h"
#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/watertank.h"
#include "/Users/madsrossen/Documents/GitHub/GrowPlant/include/textures.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

// imulates hours put into the function, and manipulates with the plants, water tank and the greenhouse
void simulateHours(PlantBase &a_plant, Watertank &waterTank, GreenHouse &a_greenhouse, int hours, int waterNeedAmount, int plantsAmount, bool putSoil){
    for (int i = 0; i <= hours; i++)
    {
        if (hours!=0)
        {
            a_greenhouse.MoistureProcent(putSoil, 0);
        }

        // If there is water in water tank, and the soil moisture is low (under 16%), then pump water from water tank, and get new moissture readings
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

        // If there is a high enough moisture level (over 7%), and the plant haven’t grow to full size,  plants grow
        if(a_plant.getHeight() <= a_plant.getMaxHeight() && a_greenhouse.getSoilMoisture()>7)
        {
            a_plant.grow(1, putSoil, a_greenhouse.getSoilMoisture());
        }
        // If new soil is put in, plants height reset
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
    TomatoPlant tomatoplant1;
    TomatoPlant tomatoplant2;
    CucumberPlant cucumberplant;
    GreenHouse my_greenhouse;
    Watertank my_watertank;

    // Variables
    int time = 8;
    int hoursToWait = 1;
    int totalHours = 0;
    int plantsAmount = 3;
    bool putSoil=false;
    int luxSensorValue = 0;
    bool autoLight = true;
    std::string strAutoLight = "Automatic light";

    // Set render window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Tomato Simulator");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    // Texture rendering and sprite setup
    textures mytexture;
    mytexture.loadTextures();
    mytexture.setupSprites();
    // setup branches for each plant
    mytexture.tomatoStalk1Branches = mytexture.setupPlantBranches(mytexture.tomatoStalk1Branch1, mytexture.tomatoStalk1Branch2, mytexture.tomatoStalk1Branch3, 181, 289);
    mytexture.tomatoStalk2Branches = mytexture.setupPlantBranches(mytexture.tomatoStalk2Branch1, mytexture.tomatoStalk2Branch2, mytexture.tomatoStalk2Branch3, 284, 288);
    mytexture.cucumberStalk1Branches = mytexture.setupPlantBranches(mytexture.cucumberStalk1Branch1, mytexture.cucumberStalk1Branch2, mytexture.cucumberStalk1Branch3, 174, 488);
    mytexture.cropsTomatoStalk1 = mytexture.setupCrops(mytexture.tomatoesSprite, "tomato", 181, 289);
    mytexture.cropsTomatoStalk2 = mytexture.setupCrops(mytexture.tomatoesSprite, "tomato", 284, 288);
    mytexture.cropsCucumberStalk1 = mytexture.setupCrops(mytexture.cucumberSprite, "cucumber", 174, 488);

    // sfml clock for updating
    sf::Clock deltaClock;

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


        ImGui::Begin("Soil");
        std::string strsoilMoisture = "Soil moisture sensor: " + std::to_string(my_greenhouse.getSoilMoisture());
        std::string strSoilChange = "Here you can change \nsoil and plants.\n\nREMEMBER new soil and \nplants are needed to \ngrow something ;)";
        const char *cc_SoilMoisture = strsoilMoisture.c_str();
        const char *cc_SoilChange = strSoilChange.c_str();
        ImGui::TextUnformatted(cc_SoilMoisture);
        ImGui::TextUnformatted(cc_SoilChange);
        
        // Change soil button
        if(ImGui::Button("Change")){
            putSoil=true;
            simulateHours(tomatoplant1, my_watertank, my_greenhouse, 1, 0.4, plantsAmount, putSoil);
            putSoil=false;
        }
            
        ImGui::End();
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
                // First TomatoPlant
                simulateHours(tomatoplant1, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                mytexture.tomatoStalk1.setSize(sf::Vector2f{5.0, -tomatoplant1.getHeight()});
                mytexture.updatePlantBranches(mytexture.tomatoStalk1Branches, tomatoplant1.getHeight(), 181, 289);
                mytexture.updateCrops(mytexture.cropsTomatoStalk1, tomatoplant1.getHeight(), 181, 289);
                // Second TomatoPlant
                simulateHours(tomatoplant2, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                mytexture.tomatoStalk2.setSize(sf::Vector2f{5.0, -tomatoplant2.getHeight()});
                mytexture.updatePlantBranches(mytexture.tomatoStalk2Branches, tomatoplant2.getHeight(), 284, 288);
                mytexture.updateCrops(mytexture.cropsTomatoStalk2, tomatoplant2.getHeight(), 284, 288);

                // CucumberPlant
                simulateHours(cucumberplant, my_watertank, my_greenhouse, 24, 0.4, plantsAmount, putSoil);
                mytexture.cucumberStalk1.setSize(sf::Vector2f{5.0, -cucumberplant.getHeight()});
                mytexture.updatePlantBranches(mytexture.cucumberStalk1Branches, cucumberplant.getHeight(), 174, 488);
                mytexture.updateCrops(mytexture.cropsCucumberStalk1, cucumberplant.getHeight(), 174, 488);

                totalHours = totalHours + 24;
                
            } 

            if(ImGui::Button("Wait the hours")){
                // First TomatoPlant
                simulateHours(tomatoplant1, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                mytexture.tomatoStalk1.setSize(sf::Vector2f{5.0, -tomatoplant1.getHeight()});
                mytexture.updatePlantBranches(mytexture.tomatoStalk1Branches, tomatoplant1.getHeight(), 181, 289);
                mytexture.updateCrops(mytexture.cropsTomatoStalk1, tomatoplant1.getHeight(), 181, 289);
                // Second TomatoPlant
                simulateHours(tomatoplant2, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                mytexture.tomatoStalk2.setSize(sf::Vector2f{5.0, -tomatoplant2.getHeight()});
                mytexture.updatePlantBranches(mytexture.tomatoStalk2Branches, tomatoplant2.getHeight(), 284, 288);
                mytexture.updateCrops(mytexture.cropsTomatoStalk2, tomatoplant2.getHeight(), 284, 288);
                // CucumberPlant
                simulateHours(cucumberplant, my_watertank, my_greenhouse, hoursToWait, 0.4, plantsAmount, putSoil);
                mytexture.cucumberStalk1.setSize(sf::Vector2f{5.0, -cucumberplant.getHeight()});
                mytexture.updatePlantBranches(mytexture.cucumberStalk1Branches, cucumberplant.getHeight(), 174, 488);
                mytexture.updateCrops(mytexture.cropsCucumberStalk1, cucumberplant.getHeight(), 174, 488);

                totalHours = totalHours + hoursToWait;
            }

            // Show water amount and add button for refill
            ImGui::Begin("Watertank");
            std::string strwaterLevel = "Water level sensor: " + std::to_string(my_watertank.getWaterAmount());
            const char *c = strwaterLevel.c_str();
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
            mytexture.sunSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            mytexture.skySprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            mytexture.teraseSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            window.clear(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            
            my_greenhouse.adjustLight(700-(getClock(totalHours)-20)*100);
            
            
        }
        //Keep the spritetextures dark from 24:00 to 05:00
        if (getClock(totalHours)>23 && getClock(totalHours)<=5 || getClock(totalHours)>=1 && getClock(totalHours)<=5)
        {
            window.clear(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            mytexture.sunSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            mytexture.skySprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            mytexture.teraseSprite.setColor(sf::Color(rgb_codenight,rgb_codenight,rgb_codenight));
            my_greenhouse.adjustLight(50);
        }
        //Daylight appears from 06:00 to 08:00
        if (getClock(totalHours)>5 && getClock(totalHours)<8)
        {
            //Make spritetextures lighter for each incremented hour. 
            rgb_codeday = rgb_codenight+(getClock(totalHours)-4)*48.75;
            mytexture.sunSprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            mytexture.skySprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            mytexture.teraseSprite.setColor(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            window.clear(sf::Color(rgb_codeday,rgb_codeday,rgb_codeday));
            
            my_greenhouse.adjustLight(100);
            
        }
        //Keep the spritetextures light from 08:00 to 19:00
        if(getClock(totalHours)>7 && getClock(totalHours)<=19)
        {
            window.clear(sf::Color::White);
            mytexture.sunSprite.setColor(sf::Color::White);
            mytexture.skySprite.setColor(sf::Color::White);
            mytexture.teraseSprite.setColor(sf::Color::White);
            my_greenhouse.adjustLight(750);
        }
        
        //Update the suns position depending on the time of the day
        //sunYPos is calculated with the linear formular: 500x+17y=9450, where x = getClock().
        double sunYPos = (9450/17)-(500*getClock(totalHours))/17 ;
        mytexture.sunSprite.setPosition(450,sunYPos);

        // Lights automode or off
        if(autoLight==true){
            mytexture.lightSprite.setColor(sf::Color(255,255,255, my_greenhouse.getLedlampvalue()*0.3));

        }

        else if (autoLight==false)
        {
            mytexture.lightSprite.setColor(sf::Color(255,255,255,0));
            my_greenhouse.adjustLight(-1);
        }

        // Draw to screen
        window.draw(mytexture.skySprite);
        window.draw(mytexture.sunSprite);
        window.draw(mytexture.teraseSprite);
        window.draw(mytexture.greenhouseSprite);
        window.draw(mytexture.tomatoStalk1);
        window.draw(mytexture.tomatoStalk2);
        window.draw(mytexture.cucumberStalk1);
        //Draw each branch on the screen
        for ( auto obj1 : mytexture.tomatoStalk1Branches) window.draw(obj1);
        for ( auto obj2 : mytexture.tomatoStalk2Branches) window.draw(obj2);
        for ( auto obj3 : mytexture.cucumberStalk1Branches) window.draw(obj3);
        for ( auto obj4 : mytexture.cropsTomatoStalk1) window.draw(obj4);
        for ( auto obj5 : mytexture.cropsTomatoStalk2) window.draw(obj5);
        for ( auto obj6 : mytexture.cropsCucumberStalk1) window.draw(obj6);
        window.draw(mytexture.lightSprite);
        ImGui::SFML::Render(window);

        window.display();
    }
    return 0;
}
