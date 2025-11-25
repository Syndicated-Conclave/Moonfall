#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace Game::Entities
{
    class UI()
    {
        
        public:
            UI(sf::RenderWindow &window);    
        
            sf::Vector2f posX;
            sf::Vector2f posY;

            sf::Font font;
            sf::Text text;
            sf::Color color;

            class DawnTimerUI;
            class DustCounterUI;

            void init(sf::RenderWindow &window);
            void update(sf::RenderWindow &window);
            void render(sf::RenderWindow &window);

    };
};