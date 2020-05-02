#include "../include/textures.h"
void textures::loadTextures()
{
    // Texture rendering
    if(!greenhouseTex.loadFromFile("..\\pictures\\Drivhus_2_v5.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    greenhouseTex.setSmooth(true);

    
    if(!stalk.loadFromFile("..\\pictures\\stalk.jpg")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    stalk.setSmooth(true);

    
    if(!sun.loadFromFile("..\\pictures\\SunV3.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    sun.setSmooth(true);

    
    if(!terase.loadFromFile("..\\pictures\\TeraseV2.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    terase.setSmooth(true);

    
    if(!sky.loadFromFile("..\\pictures\\Sky.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    sky.setSmooth(true);

    
    if(!tomatoesTex.loadFromFile("..\\pictures\\tomatoes.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    tomatoesTex.setSmooth(true);

    
    if(!cucumberTex.loadFromFile("..\\pictures\\Cucumber.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    cucumberTex.setSmooth(true);

    
    if(!lightTex.loadFromFile("..\\pictures\\light_PNG14427.png")){
        std::cout << "Couldn't load textures, check directory." << std::endl;
    }
    lightTex.setSmooth(true);
    pTexture  = &stalk;

}
void textures::setupSprites()
{
    //Greenhouse setup;
    greenhouseSprite.setTexture(greenhouseTex);
    greenhouseSprite.setPosition(100, 70);
    greenhouseSprite.setScale(0.8, 0.8);

    //Sun setup;
    sunSprite.setTexture(sun);
    sunSprite.setScale(0.4, 0.4);
    
    //Terase setup;
    teraseSprite.setTexture(terase);
    teraseSprite.setPosition(-100,-100);
    teraseSprite.setScale(1, 1);

    //Sky setup;
    skySprite.setTexture(sky);
    skySprite.setPosition(-100,-100);
    skySprite.setScale(0.7, 0.7);

    //Tomato plant 1 setup;
    tomatoStalk1 = {sf::Vector2f{5.0, -5}};
    tomatoStalk1.setPosition(181, 289);
    tomatoStalk1.setTexture(pTexture);
    
    // Tomato plant 2 setup;
    tomatoStalk2 = {sf::Vector2f{5.0, -5}};
    tomatoStalk2.setPosition(284, 288);
    tomatoStalk2.setTexture(pTexture);

    // Tomato plant 3 setup;
    cucumberStalk1 = {sf::Vector2f{5.0, -5}};
    cucumberStalk1.setPosition(174, 488);
    cucumberStalk1.setTexture(pTexture);

    
    tomatoesSprite.setTexture(tomatoesTex);
    //tomatoesSprite.setPosition(xPosTomato_plant1,xPosTomato_plant1);
    tomatoesSprite.setScale(0, 0);

    cucumberSprite.setTexture(cucumberTex);
    //tomatoesSprite.setPosition(xPosTomato_plant1,xPosTomato_plant1);
    cucumberSprite.setScale(0, 0);
    
    lightSprite.setTexture(lightTex);
    lightSprite.setPosition(105,78);
    lightSprite.setScale(0.2, 0.2);
}

std::vector<sf::RectangleShape> textures::setupPlantBranches(sf::RectangleShape branch1, sf::RectangleShape branch2, sf::RectangleShape branch3, int x_pos, int y_pos)
{
    //std::string branchNr = "tomatoStalk1Branch" + std::to_string((int)i);
    std::vector<sf::RectangleShape> vec; 
    vec.push_back(branch1);
    vec.push_back(branch2);
    vec.push_back(branch3);
    int rot = 70;
    float height_stalk = 4.0;
    for (auto i = 0; i < vec.size() ; i++)
    {       
            vec[i] = {sf::Vector2f{5.0, - height_stalk/2}};
            vec[i].setPosition(x_pos, y_pos);
            vec[i].setTexture(pTexture);
            vec[i].setRotation(rot);
            rot = rot * -1;
            height_stalk = height_stalk + 3;
            std::cout << "rot: " << rot << "height_stalk: " << height_stalk << "x_pos: "<<x_pos << std::endl;  
    }
    return vec;
}
void textures::updatePlantBranches( std::vector<sf::RectangleShape> &vec, float b_height, double x_pos, double y_pos)
{
    float scale =  1.5;
    for (auto i = 0; i < vec.size() ; i++)
    {
        vec[i].setPosition(x_pos, - b_height/scale+y_pos);
        vec[i].setSize(sf::Vector2f{5.0, -b_height/scale});
        scale = scale + 1;
    }

}
std::vector<sf::Sprite> textures::setupCrops(sf::Sprite crops, std::string type, int x_pos, int y_pos)
{
    //std::string branchNr = "tomatoStalk1Branch" + std::to_string((int)i);
    std::vector<sf::Sprite> vec; 
    vec.push_back(crops);
    vec.push_back(crops);
    vec.push_back(crops);
    float height_stalk = 4.0;
    int rot = 0;
    for (auto i = 0; i < vec.size() ; i++)
    {       
            //vec[i] = {sf::Vector2f{5.0, - height_stalk}};
            vec[i].setPosition(x_pos, y_pos);
            if (type == "tomato")
            {
                vec[i].setTexture(tomatoesTex);
                rot = -15;
            }
            else 
            {
                vec[i].setTexture(cucumberTex);
            }
            vec[i].setRotation(rot);
            rot = rot;
            height_stalk = height_stalk + 3;
            std::cout << "rot: " << rot << "height_stalk: " << height_stalk << "x_pos: "<<x_pos << std::endl;  
    }
    return vec;
}
void textures::updateCrops( std::vector<sf::Sprite> &vec, float b_height, double x_pos, double y_pos)
{
    float scale =  1.5;
    for (auto i = 0; i < vec.size() ; i++)
    {   
        vec[i].setPosition(x_pos, - b_height/scale+y_pos -(b_height/scale+y_pos)/70 );
        vec[i].setScale(sf::Vector2f{b_height/3000, b_height/3000});
        scale = scale + 1;
    }

}