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
                
                // Game::Entities::UI *ui;
                
                // Game::Entities::Timer timer;
                // Game::Entities::StarDustCounter starDustCounter;
                
                //variables
                sf::Vector2f posX;
                sf::Vector2f posY;
                int CollectedPoints;
                int RequiredPoints;
                sf::Text counterText;
                sf::RectangleShape counterBlock;
                sf::RectangleShape counterBox;
                sf::Font font;
                sf::Text timerText;
                sf::RectangleShape timerBlock;
                sf::RectangleShape timerBox;

                
                sf::Clock timer;
               
                int gameTime = 120;
                sf::Text TimerText;
                float timeLeft;
                float countdowntext;
                
                //methods
                //void init(sf::RenderWindow &window);
                void input(sf::RenderWindow &window);               
                //void update(sf::RenderWindow &window);               
                //void render(sf::RenderWindow &window);
                
        };
        
        // class Timer
        // {
        //     //variables
        //     sf::Clock countdown;
        //     int gameTime;
        //     float timeTaken;
        //     int timeLeft;
        //     sf::Font font;
        //     sf::Color color;
        //     sf::Text timerText;

        //     //methods
        //     void init();
        // };

        // class StarDustCounter
        // {
        //     static int points;
        //     sf::Font font;
        //     sf::Color color;
        //     sf::Text starDustCounterText;

        //     //methods
        //     void init();
        // };
    }
}