#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        class Guide
        {
        public:
            void instruct(sf::RenderWindow& window);
            void draw(sf::RenderWindow& window);
            void handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState);
            sf::Font font;
            sf::Text title;
            sf::VertexArray sky;
            sf::RectangleShape exit;
            sf::RectangleShape guide;
            sf::RectangleShape bigClockhand;
            sf::RectangleShape smallClockhand;
            sf::CircleShape moon;
            sf::CircleShape clockface;
            sf::Text exitText;
            sf::Text moonText;
            sf::Text starText;
            sf::Text timeText;
            sf::ConvexShape starOne;
            sf::ConvexShape starTwo;
            sf::ConvexShape starThree;
            sf::ConvexShape sparkleOne;
            sf::ConvexShape sparkleTwo;
            sf::ConvexShape aKey;
            sf::ConvexShape wKey;
            sf::ConvexShape dKey;
            sf::Text aKeyText;
            sf::Text wKeyText;
            sf::Text dKeyText;
            sf::Text aMoveText;
            sf::Text wMoveText;
            sf::Text dMoveText;

        };

    }
}
