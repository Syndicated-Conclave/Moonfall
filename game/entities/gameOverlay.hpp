#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace Game
{
    namespace Entities
    {
        class UI
        {
        public:
            UI(sf::RenderWindow &window);
            void updateTimer(float timePassed, int gameTimeLimit);
            void drawTimer(sf::RenderWindow &window);
            void updateCounter(int collectedStars, int requiredStars);
            void drawCounter(sf::RenderWindow &window);

            sf::Font font;

            // variables

            std::string counterBaseText;
            sf::Text counterText;
            sf::RectangleShape counterBlock;
            sf::RectangleShape counterBox;

            std::string timerBaseText;
            sf::Text timerText;

            sf::RectangleShape timerBlock;
            sf::RectangleShape timerBox;

            // sf::Clock timer;
            int timeLeft;
        };
    }
}