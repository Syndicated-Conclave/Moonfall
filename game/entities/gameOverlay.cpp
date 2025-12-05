#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gameOverlay.hpp"
#include <iostream>

// Robert's Code

namespace Game
{
    namespace Entities
    {
        UI::UI(sf::RenderWindow &window)
        {
            

            // Adding custom font and styling for counter text

            sf::Font localFont;
            font = localFont;
            font.loadFromFile("resources/HUSKYSTA.otf");

            counterBaseText = "Star Dust Collected: ";

            sf::Text localCounterText(counterBaseText, font, 28);
            counterText = localCounterText;
            counterText.setFillColor(sf::Color(255, 255, 224));
            counterText.setPosition({120.f, 30.f});

            // Creating boxes for timer text
            sf::RectangleShape localCounterBlock({400.f, 65.f});
            counterBlock = localCounterBlock;
            counterBlock.setPosition(100.f, 20.f);

            sf::RectangleShape localCounterBox({400.f, 65.f});
            counterBox = localCounterBox;
            counterBox.setPosition(100.f, 20.f);

            counterBlock.setFillColor(sf::Color(11, 11, 24));
            counterBox.setFillColor(sf::Color(8, 10, 43));

            // Adding custom font and styling for countdown text

            timerBaseText = "Time Till Sunrise: ";

            sf::Text localTimerText(timerBaseText, font, 28);
            timerText = localTimerText;
            timerText.setFillColor(sf::Color(255, 255, 224));
            timerText.setPosition({1120.f, 30.f});

            // Creating boxes for timer text
            sf::RectangleShape localTimerBlock({400.f, 65.f});
            timerBlock = localTimerBlock;
            timerBlock.setPosition(1100.f, 20.f);

            sf::RectangleShape localTimerBox({400.f, 65.f});
            timerBox = localTimerBox;
            timerBox.setPosition(1100.f, 20.f);

            timerBlock.setFillColor(sf::Color(11, 11, 24));
            timerBox.setFillColor(sf::Color(8, 10, 43));

            
        }

        void UI::updateTimer(float timePassed)
        {
            timeLeft = round(gameTime - timePassed);
            std::string timerString = timerBaseText + std::to_string(timeLeft);

            timerText.setString(timerString);
        }
        void UI::drawTimer(sf::RenderWindow &window)
        {
            window.draw(timerBlock);
            window.draw(timerBox);
            window.draw(timerText);
        }
        void UI::updateCounter(int collectedStars, int requiredStars)
        {
            std::string counterString = counterBaseText + std::to_string(collectedStars) + " / " + std::to_string(requiredStars);

            counterText.setString(counterString);
        }
        void UI::drawCounter(sf::RenderWindow &window)
        {
            window.draw(counterBlock);
            window.draw(counterBox);
            window.draw(counterText);
        }

    }
}