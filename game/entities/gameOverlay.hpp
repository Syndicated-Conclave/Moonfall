#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace Game
{
    namespace Entities
    {
        class UI
        {            
            public:
                
                //Objects    
                //sf::RenderWindow window(sf::VideoMode({800, 400}), "Moonfall");    
                
                //variables
                sf::Vector2f posX;
                sf::Vector2f posY;

                sf::Font font;
                sf::Text Timer;
                sf::Text StarDustCounter;
                sf::Color color;

                //methods
                void init(sf::RenderWindow &window);
                void input(sf::RenderWindow &window);               
                void update(sf::RenderWindow &window);               
                void render(sf::RenderWindow &window);
                
        };   
    }
}