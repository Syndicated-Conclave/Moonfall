#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "levelMenu.hpp"
#include "../gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        class Menu
        {
        public:
            void mainMenu(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window);
            void handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State &gameState);
            sf::Font font;
            sf::Text title;
            sf::VertexArray sky;
            sf::ConvexShape star;
            sf::RectangleShape exit;
            sf::RectangleShape guide;
            sf::RectangleShape play;
            sf::RectangleShape controls;
            sf::Text exitText;
            sf::Text guideText;
            sf::Text playText;
            sf::Text controlsText;
        private:
            //void levelMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
        };

    }
}