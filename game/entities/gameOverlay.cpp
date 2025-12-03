#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <game/main.cpp>
#include <iostream>

#define WIDTH 1600
#define HEIGHT 900

sf::RenderWindow window;
bool fullScreen;

namespace Game
{
    namespace Entities
    {
        Game::Entities::UI *ui;
        
        //while (Game::State gameState.Playing)
        //{
            void UI::init(sf::RenderWindow &window)
            {
                Game::Entities::Timer timer;
                Game::Entities::StarDustCounter starDustCounter;

                
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
                    
                    input();
                    render();
                    Game::Entities::Timer::init();
                    Game::Entities::StarDustCounter::init();
                    
                    
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
                window.draw(Game::Entities::Timer::timerText);
                window.draw(Game::Entities::StarDustCounter::starDustCounterText);               
                window.display();
                
            };

            void Timer::init()
            {
                //timer
                sf::Clock countdown;
                /*Setting game time to two minutes*/
                int gameTime = 120;
                float timeTaken = countdown.getElapsedTime().asSeconds();
                int timeLeft = gameTime - countdown.getElapsedTime().asSeconds();
                
                //font object
                sf::Font font;
                font.loadFromFile("resources/HUSKYSTA.otf");

                //points
                int Game::Entities::StarDustCounter::points = 0;
                
                //timer variables
                timer.setFillColor(sf::Color(255, 255, 225));
                timer.setPosition({20.f, 10.f});
                timer.setFont(font);
                timer.setCharacterSize(48);
                
                timer.setString("Time Left: " + timeLeft);
            }
            
            void StarDustCounter::init()
            {
                //font object
                sf::Font font;
                font.loadFromFile("resources/HUSKYSTA.otf");
                
                //star dust counter variables
                starDustCounter.setFillColor(sf::Color(255, 255, 225));
                starDustCounter.setPosition({1500.f, 10.f});
                starDustCounter.setFont(font);
                starDustCounter.setCharacterSize(48);
                starDustCounter.setString("Star Dust Collected: " + Game::Entities::StarDustCounter::points);
            }

        //}
    }  
}