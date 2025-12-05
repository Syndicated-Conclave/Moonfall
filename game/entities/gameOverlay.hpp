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
                
                //variables               
                int CollectedPoints;
                int RequiredPoints;
                sf::Text counterText;
                sf::RectangleShape counterBlock;
                sf::RectangleShape counterBox;
                sf::Font font;
                sf::Text timerText;
                sf::Text TimerText;
                sf::RectangleShape timerBlock;
                sf::RectangleShape timerBox;                
                sf::Clock timer;               
                int gameTime = 120;                
                float timeLeft;
                float countdowntext;
                
                //methods
                //void init(sf::RenderWindow &window);
                void input(sf::RenderWindow &window);               
                //void update(sf::RenderWindow &window);               
                //void render(sf::RenderWindow &window);
                
        };               
    }
}