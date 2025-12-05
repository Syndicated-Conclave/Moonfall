#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "gameOverlay.hpp"
#include <game/main.cpp>
#include <iostream>

//Robert's Code

namespace Game
{
    namespace Entities
    {   
        class UI
        {
            int width = 1600;
            int height = 900;
            sf::RenderWindow window(sf::VideoMode(width, height), "Moonfall");
            bool fullScreen;

            void UI::input(sf::RenderWindow &window)
            {
                sf::Event e;
                while(window.pollEvent(e))
                {
                    if(e.type == sf::Event::Closed)
                    window.close();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                    window.close();
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
                    {
                    if(fullScreen)
                    window.create(sf::VideoMode::getFullscreenModes()[0], "Moonfall");
                    if(!fullScreen)
                    window.create(sf::VideoMode(Game::Entities::UI::width, Game::Entities::UI::height), "Moonfall");
                    }
                    fullScreen = !fullScreen;
                }
            };

            // Adding custom font and styling for counter text
            
            sf::Font localFont;
            font = localFont;
            font.loadFromFile("resources/HUSKYSTA.otf");
            
            sf::Text localCounterText("Star Dust Collected: " + CollectedPoints, font, 28);
            counterText = localCounterText;
            counterText.setFillColor(sf::Color(255, 255, 224));
            counterText.setPosition({300.f, 30.f});

            // Creating boxes for timer text
            sf::RectangleShape localCounterBlock({400.f, 65.f});
            counterBlock = localCounterBlock;
            counterBlock.setPosition(100.f, 20.f);
            
            sf::RectangleShape localCounterBox({180.f, 35.f});
            counterBox = localCounterBox;
            counterBox.setPosition(380.f, 33.f); 
            
            counterBlock.setFillColor(sf::Color(11, 11, 24));
            counterBox.setFillColor(sf::Color(8, 10, 43));
            
            // Adding custom font and styling for countdown text
            
            sf::Text localTimerText("Time Till Sunrise: ", font, 28);
            timerText = localTimerText;
            timerText.setFillColor(sf::Color(255, 255, 224));
            timerText.setPosition({1200.f, 30.f});

            // Creating boxes for timer text
            sf::RectangleShape localTimerBlock({400.f, 65.f});
            timerBlock = localTimerBlock;
            timerBlock.setPosition(600.f, 20.f);
            
            sf::RectangleShape localTimerBox({1200.f, 35.f});
            timerBox = localTimerBox;
            timerBox.setPosition(1280.f, 33.f); 
            
            timerBlock.setFillColor(sf::Color(11, 11, 24));
            timerBox.setFillColor(sf::Color(8, 10, 43));

            //timer functionality
            sf::Clock timer;
            /*Setting game time to two minutes*/
            int gameTime = 120;
            
            sf::Text localTimerText(" : ", font, 28);
            TimerText = localTimerText;

            TimerText.setFillColor(sf::Color(255, 255, 224));
            TimerText.setPosition(890.f, 35.f);
            
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        
                        window.close();
                    }
                    float timeLeft = timer.getElapsedTime().asSeconds();
                    float timerText = gameTime - timeLeft;
                    if(timerText < 0) timerText = 0;
                    TimerText.setString(std::to_string((int)timerText));

                    CollectedPoints = Game::Components::collectedPoints;
                    RequiredPoints = Game::Components::requiredPoints;
                
                }

                window.clear();           
                window.draw(timerBlock);
                window.draw(timerBox);
                window.draw(timerText);
                window.draw(TimerText);
                window.draw(counterBlock);
                window.draw(counterBox);
                window.draw(counterText);           
                window.display();
            }
        };                       
    }  
}