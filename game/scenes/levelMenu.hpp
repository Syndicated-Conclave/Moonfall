#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        class levelMenu
        {
        public:
            void chooseLevel(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window);
            void handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState);
            sf::Font font;
            sf::Text title;
            sf::VertexArray sky;
            sf::RectangleShape levelOne;
            sf::RectangleShape levelTwo;
            sf::RectangleShape levelThree;
            sf::RectangleShape returnMenu;
            sf::Text LevelOne;
            sf::Text LevelTwo;
            sf::Text LevelThree;
            sf::Text ReturnMenu;

            //void basicPhysicsSetUp(sf::RenderWindow& window, Engine::EntityManager& ecm);
        private:
            //void levelMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

    }
}