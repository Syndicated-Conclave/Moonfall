#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <iostream>

namespace Game
{
    namespace Entities
    {
        UI::init(sf::RenderWindow &window)
        {
            //font object
            sf::Font font;
            font.loadFromFile("resources/HUSKYSTA.otf");
            
            //timer variables
            Timer.setFillColor(sf::Color(255, 255, 225));
            Timer.setPosition({20.f, 10.f});
            Timer.setFont(font);
            Timer.setCharacterSize(48);
            Timer.setString("Time Left: ");

            //star dust counter variables
            StarDustCounter.setFillColor(sf::Color(255, 255, 225));
            StarDustCounter.setPosition({20.f, 10.f});
            StarDustCounter.setFont(font);
            StarDustCounter.setCharacterSize(48);
            StarDustCounter.setString("Star Dust Collected: ");
        }

        UI::update(sf::RenderWindow &window)
        {
            
        }

        UI::render(sf::RenderWindow &window)
        {
            window.display(Timer);
            window.display(StarDustCounter);
            
        }
        
    }
    
}


