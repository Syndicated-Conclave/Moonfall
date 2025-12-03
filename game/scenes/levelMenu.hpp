#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"

namespace Game
{
    namespace Scenes
    {
        class levelMenu
        {
        public:
            void mainMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);
            void basicPhysicsSetUp(sf::RenderWindow& window, Engine::EntityManager& ecm);
        private:
            //void levelMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

    }
}