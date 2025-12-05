#include "graphics.hpp"
#include "../../engine/utils.hpp"

namespace Game
{
    namespace Components
    {
        sf::Vector2f Game::Components::Graphics::offset = {0.f, 0.f}; // initialise static variable with 0,0

        void Graphics::createBuilding(sf::RenderWindow &window, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, int colour)
        {
            shape.setSize({sfmlWidth, sfmlHeight});
            shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
            shape.setOrigin(sfmlWidth / 2, sfmlHeight / 2); // center origin to match box2d's automatic center origin
            shape.setPosition(sfmlPosition);
        }

        void Graphics::createMoon(sf::RenderWindow &window, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour)
        {
            shape.setRadius(sfmlDiameter / 2);
            shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
            shape.setOrigin(sfmlDiameter / 2, sfmlDiameter / 2); // center origin to match box2d's automatic center origin
            shape.setPosition(sfmlPosition);
        }

        void Graphics::createStar(sf::RenderWindow &window, sf::ConvexShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, int colour)
        {
            shape.setPointCount(10);
            shape.setPoint(0, sf::Vector2f(8, -2));
            shape.setPoint(1, sf::Vector2f(10, 3));
            shape.setPoint(2, sf::Vector2f(15, 3));
            shape.setPoint(3, sf::Vector2f(11, 6));
            shape.setPoint(4, sf::Vector2f(12, 11));
            shape.setPoint(5, sf::Vector2f(8, 8));
            shape.setPoint(6, sf::Vector2f(4, 11));
            shape.setPoint(7, sf::Vector2f(5, 6));
            shape.setPoint(8, sf::Vector2f(1, 3));
            shape.setPoint(9, sf::Vector2f(6, 3));
            shape.setFillColor(sf::Color(Engine::Utils::hexToSfmlColour(colour)));
            shape.setOrigin(sfmlDiameter / 2, sfmlDiameter / 2); // center origin to match box2d's automatic center origin
            shape.setPosition(sfmlPosition);
        }

        void Graphics::updateShape(sf::RenderWindow &window, sf::Shape &shape, sf::Vector2f newPosition, float angle, bool isMoon)
        {
            if (isMoon)
            {
                if (newPosition.x > window.getSize().x * 0.5f)
                {
                    Game::Components::Graphics::offset = {window.getSize().x * 0.5f - newPosition.x, 0}; // distance between window middle and moon position
                }
                else
                {
                    Game::Components::Graphics::offset = {0, 0};
                }
                shape.setPosition(newPosition - Game::Components::Graphics::offset); // offset moon to cancel out its x axis movement
                shape.setRotation(angle);
            }
            shape.setPosition(newPosition + Game::Components::Graphics::offset); // offset other entities to add x axis movement to them instead
            shape.setRotation(angle);
        }

    }
}