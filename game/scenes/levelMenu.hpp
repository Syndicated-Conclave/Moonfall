#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/ecm.hpp"

namespace Game
{
    namespace Scenes
    {
        class levelMenu
        {
        public:
            void chooseLevel(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);
            sf::RectangleShape levelOne;
            sf::RectangleShape levelTwo;
            sf::RectangleShape levelThree;
            sf::RectangleShape returnMenu;
            
        };

    }
}