#pragma once
#include <SFML/Graphics.hpp>
#include "physics.hpp"

namespace Engine
{
    class Utils
    {
    public:
        static int RNG();
        static sf::Color hexToSfmlColour(int hex);
        static void createCircle(sf::RenderWindow &window, b2BodyId &bodyId, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution, int colour);
        static void createRectangle(sf::RenderWindow &window, b2BodyId &bodyId, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, float density, float friction, float restitution, int colour);

    private:
        static b2BodyId setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window);
        static b2ShapeDef setUpShapeDef(float density, float friction, float restitution);
    };
}