#include "cityscape.hpp"
#include <iostream>

namespace Game
{
    namespace Entities
    {
        Cityscape::Cityscape(sf::RenderWindow &window, Engine::EntityManager &ecm) : entity(ecm.createEntity())
        {
            float sfmlPosX = window.getSize().x / 2;
            float sfmlPosY = window.getSize().y;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            Game::Components::Physics::createCityscape(window, entity->physicsBodyId, sfmlPosition, SFML_WIDTH, SFML_HEIGHT, DENSITY, FRICTION, RESTITUTION);

            entity->graphicsShape = std::make_unique<sf::RectangleShape>();
            auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShape.get());

            Game::Components::Graphics::createCityscape(window, *rect, sfmlPosition, SFML_WIDTH, SFML_HEIGHT, COLOUR);
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            Game::Components::Physics::updateCityscape(window, entity->physicsBodyId, angle, MAX_TILT, TILT_SPEED, sfmlPosition, MAX_BUMP, BUMP_VELOCITY);

            sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyId)), window.getSize().y);

            float angle = -b2Rot_GetAngle(b2Body_GetRotation(entity->physicsBodyId)) * 180.f / B2_PI;

            Game::Components::Graphics::updateShape(window, *entity->graphicsShape, newPosition, angle);
        }

        void Cityscape::render(sf::RenderWindow &window)
        {
            window.draw(*entity->graphicsShape);
        }
    }

}
