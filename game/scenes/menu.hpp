#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "levelMenu.hpp"

namespace Game
{
    namespace Scenes
    {
        class Menu
        {
        public:
            void mainMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);
            sf::RectangleShape exit;
            sf::RectangleShape guide;
            sf::RectangleShape play;
            sf::RectangleShape controls;
        private:
            //void chooseLevel(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

        

    }
}