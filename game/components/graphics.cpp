#include "graphics.hpp"
#include "../../engine/utils.hpp"
#include <iostream>

namespace Game
{
    namespace Components
    {

        void Graphics::createCityscape(sf::RenderWindow &window, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, int colour)
        {
            shape.setSize({sfmlWidth, sfmlHeight});
            shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
            shape.setOrigin(sfmlWidth / 2, sfmlHeight / 2); // center origin
            shape.setPosition(sfmlPosition);
            std::cout << "Set polygon shape attributes\n";
        }

        void Graphics::createMoon(sf::RenderWindow &window, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour)
        {
            shape.setRadius(sfmlDiameter / 2);
            shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
            shape.setOrigin(sfmlDiameter / 2, sfmlDiameter / 2); // center origin
            shape.setPosition(sfmlPosition);
            std::cout << "Set circle shape attributes\n";
        }
        void Graphics::updateShape(sf::RenderWindow &window, sf::Shape &shape, sf::Vector2f newPosition, float angle)
        {
            shape.setPosition(newPosition);
            shape.setRotation(angle);
        }

    }
}