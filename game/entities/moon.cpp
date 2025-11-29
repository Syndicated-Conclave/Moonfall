#include "moon.hpp"

namespace Game
{
    namespace Entities
    {
        Moon::Moon(sf::RenderWindow &window, Engine::EntityManager &ecm) : entity(ecm.createEntity())
        {
            float sfmlPosX = window.getSize().x / 2;
            float sfmlPosY = Moon::SFML_DIAMETER / 2;
            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            entity->physicsBodyIds.push_back(b2_nullBodyId);
            Game::Components::Physics::createMoon(window, entity->physicsBodyIds.back(), sfmlPosition, SFML_DIAMETER, DENSITY, FRICTION, RESTITUTION);

            entity->graphicsShapes.push_back(std::make_unique<sf::CircleShape>());              // makes a circle shape pointer and assigned the graphicsShapes as its owner
            auto *circle = static_cast<sf::CircleShape *>(entity->graphicsShapes.back().get()); // stores a raw pointer (non owner) of the graphicsShapes, which we know is a circle, in the circle var
            Game::Components::Graphics::createMoon(window, *circle, sfmlPosition, SFML_DIAMETER, COLOUR);
        }

        void Moon::update(sf::RenderWindow &window)
        {
            sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds.back())), window.getSize().y);

            float angle = b2Rot_GetAngle(b2Body_GetRotation(entity->physicsBodyIds.back())) * 180.f / B2_PI;

            Game::Components::Graphics::updateShape(window, *entity->graphicsShapes.back(), newPosition, angle);
        }

        void Moon::render(sf::RenderWindow &window)
        {
            window.draw(*entity->graphicsShapes.back());
        }
    }

}
