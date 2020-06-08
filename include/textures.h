#pragma once
#include "imgui.h"
#include "imgui-SFML.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "tomato_plant.h"
#include "cucumber_plant.h"
#include <cmath>
class textures
{
public:
    sf::Texture greenhouseTex;
    sf::Texture stalk;
    sf::Texture sun;
    sf::Texture terase;
    sf::Texture sky;
    sf::Sprite greenhouseSprite;
    sf::Sprite sunSprite;
    sf::Sprite teraseSprite;
    sf::Sprite skySprite;
    sf::Sprite tomatoesSprite;
    sf::Sprite cucumberSprite;
    const sf::Texture *pTexture;
    sf::RectangleShape tomatoStalk1;
        sf::RectangleShape tomatoStalk1Branch1;
        sf::RectangleShape tomatoStalk1Branch2;
        sf::RectangleShape tomatoStalk1Branch3;
    sf::RectangleShape tomatoStalk2;
        sf::RectangleShape tomatoStalk2Branch1;
        sf::RectangleShape tomatoStalk2Branch2;
        sf::RectangleShape tomatoStalk2Branch3;
    sf::RectangleShape cucumberStalk1;
        sf::RectangleShape cucumberStalk1Branch1;
        sf::RectangleShape cucumberStalk1Branch2;
        sf::RectangleShape cucumberStalk1Branch3;
    std::vector<sf::RectangleShape> tomatoStalk1Branches;
    std::vector<sf::RectangleShape> tomatoStalk2Branches;
    std::vector<sf::RectangleShape> cucumberStalk1Branches;
    std::vector<sf::Sprite> cropsTomatoStalk1;
    std::vector<sf::Sprite> cropsTomatoStalk2;
    std::vector<sf::Sprite> cropsCucumberStalk1;
    sf::Texture tomatoesTex;
    sf::Texture cucumberTex;
    sf::Texture lightTex;
    sf::Sprite lightSprite;

    void loadTextures();
    void setupSprites();
    std::vector<sf::RectangleShape> setupPlantBranches(sf::RectangleShape branch1, sf::RectangleShape branch2, sf::RectangleShape branch3, int x_pos, int y_pos);
    void updatePlantBranches( std::vector<sf::RectangleShape> &vec, float b_height, double x_pos, double y_pos);
    std::vector<sf::Sprite> setupCrops(sf::Sprite crops, std::string type, int x_pos, int y_pos);
    void updateCrops( std::vector<sf::Sprite> &vec, float b_height, double x_pos, double y_pos);
private:
};

