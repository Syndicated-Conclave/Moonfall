#pragma once
#include <SFML/Graphics.hpp>

// namespace for all game specific things
namespace Game
{
    // namespace for all components

    namespace Components
    {
        // GRAPHICS

        // this class handles the graphics of all entities
        class Graphics
        {
        public:
            // used to create all individual buildings of the cityscape entity
            static void createBuilding(sf::RenderWindow &window, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, int colour);
            // used to create the moon entity
            static void createMoon(sf::RenderWindow &window, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour);
            // used to create all individual stars of the stardust entities
            static void createStar(sf::RenderWindow &window, sf::ConvexShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour);
            // used to update all sfml shapes including shifting them for the continuous horizontal movement
            static void updateShape(sf::RenderWindow &window, sf::Shape &shape, sf::Vector2f newPosition, float angle, bool isMoon);

            // the vector used to store the current offset for the continuous horizontal movement
            static sf::Vector2f offset;
        };
    }
}