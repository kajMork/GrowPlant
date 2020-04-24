#include <iostream>
#include <thread>
#include <SFML/Graphics.hpp>
#include <imgui.h>
#include <imgui-SFML.h>
#include <tomato_plant.h>

void simulateOneDay(PlantBase &a_plant){
    a_plant.grow(1);
}

int main(int argc, char const *argv[]){

    float stalk_length = -25.;
    sf::RectangleShape tomato_stalk {sf::Vector2f{5.0, stalk_length}};
    tomato_stalk.setFillColor(sf::Color{0, 255, 0});
    tomato_stalk.setPosition(400,300);

    //Laver output til dropdown menu
    const char* items[] = { "AAAA", "BBBB", "CCCC", "DDDD", "EEEE", "FFFF", "GGGG", "HHHH", "IIII", "JJJJ", "KKKK", "LLLLLLL", "MMMM", "OOOOOOO", "PPPP", "QQQQQQQQQQ", "RRR", "SSSS" };
    static const char* current_item = NULL;
    ImGuiComboFlags flags = ImGuiComboFlags_NoArrowButton;

   // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Simulation");
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
        if (ImGui::SliderFloat("Length", &stalk_length, 0., 200.))
        {
           tomato_stalk.setSize(sf::Vector2f{5.0, stalk_length}); 
        }
        ImGui::End();

        ImGuiStyle& style = ImGui::GetStyle();
        float w = ImGui::CalcItemWidth();
        float spacing = style.ItemInnerSpacing.x;
        float button_sz = ImGui::GetFrameHeight();
        ImGui::PushItemWidth(w - spacing * 2.0f - button_sz * 2.0f);
        if (ImGui::BeginCombo("##space", current_item, ImGuiComboFlags_NoArrowButton))
        {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++)
        {
        bool is_selected = (current_item == items[n]);
        if (ImGui::Selectable(items[n], is_selected))
            current_item = items[n];
        if (is_selected)
            ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
        }
        ImGui::PopItemWidth();
        ImGui::SameLine(0, spacing);
       
        ImGui::SameLine(0, style.ItemInnerSpacing.x);
        ImGui::Text("Vælg en plante :) ");

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
