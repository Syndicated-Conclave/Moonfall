#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"

namespace Game
{
    namespace Scenes
    {
        class Menu
        {
        public:
            void mainMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);
        private:
            void levelMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

    }
}