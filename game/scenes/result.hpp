#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        class Win
        {
        public:
            void showResult(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window);
            void handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState);
            sf::RectangleShape win;
            sf::RectangleShape back;
            sf::Text winText;
            sf::Text backText;
            sf::VertexArray sky;
            sf::Font font;
        };

        class Lose
        {
        public:
            void showResult(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window);
            void handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState);
            sf::RectangleShape lose;
            sf::RectangleShape back;
            sf::Text loseText;
            sf::Text backText;
            sf::VertexArray sky;
            sf::Font font;
        };

    }
}
