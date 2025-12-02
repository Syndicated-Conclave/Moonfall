#pragma once
#include <SFML/Graphics.hpp>

namespace Game
{
    namespace Components
    {
        class Graphics
        {
        public:
            static void createCityscape(sf::RenderWindow &window, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, int colour);
            static void createMoon(sf::RenderWindow &window, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour);
            static void createStar(sf::RenderWindow &window, sf::ConvexShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour);
            static void updateShape(sf::RenderWindow &window, sf::Shape &shape, sf::Vector2f newPosition, float angle, bool isMoon);
            static sf::Vector2f cameraOffset;
        };
    }
}