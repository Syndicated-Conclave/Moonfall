#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <iostream>

namespace Game
{
    namespace Entities
    {
        sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Moonfall");
        
        void UI::init(sf::RenderWindow &window)
        {
            //font object
            sf::Font font;
            font.loadFromFile("resources/HUSKYSTA.otf");
            
            //timer variables
            Timer.setFillColor(sf::Color(255, 255, 225));
            Timer.setPosition({20.f, 10.f});
            Timer.setFont(font);
            Timer.setCharacterSize(48);
            
            Timer.setString("Time Left: "); // needs timer code plugged in from Cass' sunrise code

            //star dust counter variables
            StarDustCounter.setFillColor(sf::Color(255, 255, 225));
            StarDustCounter.setPosition({20.f, 10.f});
            StarDustCounter.setFont(font);
            StarDustCounter.setCharacterSize(48);
            StarDustCounter.setString("Star Dust Collected: "); // will need a counter made to plug into string
        }

        
        //while(game_isPlaying) // some sort of while loop so that the UI only shows when the game is being played
        //{
            //update method
            void UI::update(sf::RenderWindow &window, float dt, sf::Clock clock)
            {
                static sf::Clock clock;
                float dt = clock.restart().asSeconds();
            };

            //render method
            void UI::render(sf::RenderWindow &window)
            {
                window.clear();
                window.draw(Timer);
                window.draw(StarDustCounter);
                // window.display(Timer);
                // window.display(StarDustCounter);
                window.display();
                
            };

        //};
    }  
}