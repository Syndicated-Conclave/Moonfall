#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <iostream>

#define WIDTH 1600
#define HEIGHT 900

sf::RenderWindow window;
bool fullScreen;

namespace Game
{
    namespace Entities
    {
        
        //while(game_isPlaying == true) // some sort of while loop with a bool so that the UI only shows when the game is being played
        //{
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
            };

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
                    window.create(sf::VideoMode(WIDTH, HEIGHT), "Moonfall");
                    }
                    fullScreen = !fullScreen;
                }
            };
            
            //update method
            void UI::update(sf::RenderWindow &window)
            {                
                while (window.isOpen())
                {
                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
                        {
                            window.close();
                        }
                    }
                }
            };

            //render method
            void UI::render(sf::RenderWindow &window) //BUG NEEDS FIX
            {
                sf::Event event;

                while(window.pollEvent(event))
                {
                    if(event.type == sf::Event::Closed)
                    {
                        window.close();
                    }

                };

                window.clear();
                window.draw(Timer);
                window.draw(StarDustCounter);               
                window.display();
                
            };
        //}
    }  
}