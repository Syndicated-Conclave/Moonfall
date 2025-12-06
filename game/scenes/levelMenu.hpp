#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"
#include "../components/AudioManager.hpp"

namespace Game
{
    namespace Scenes
    {
        class levelMenu
        {
        public:
            void chooseLevel(sf::RenderWindow &window);
            void draw(sf::RenderWindow &window);
            int handleEvent(sf::RenderWindow &window, Game::Components::AudioManager &audioManager, sf::Event &event, Game::State &gameState);
            sf::Font font;
            sf::Text title;
            sf::VertexArray sky;
            sf::RectangleShape levelOne;
            sf::RectangleShape levelTwo;
            sf::RectangleShape levelThree;
            sf::RectangleShape levelFour;
            sf::RectangleShape returnMenu;
            sf::Text LevelOne;
            sf::Text LevelTwo;
            sf::Text LevelThree;
            sf::Text LevelFour;
            sf::Text ReturnMenu;

            // void basicPhysicsSetUp(sf::RenderWindow& window, Engine::EntityManager& ecm);
        private:
            // void levelMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

    }
}