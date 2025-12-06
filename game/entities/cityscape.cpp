#include "cityscape.hpp"
#include <iostream>

namespace Game
{
    namespace Entities
    {
        Cityscape::Cityscape(Engine::EntityManager &ecm) : entity(ecm.createEntity()) {}

        void Cityscape::create(sf::RenderWindow &window)
        {
            // since the first building's center is the origin of the cityscape
            float sfmlPosX = city[0].width / 2 - 1;
            // gaps in the cityscape are buildings with height 1, to avoid that being visible on bump the cityscape is offset by max bump
            float sfmlPosY = window.getSize().y + MAX_BUMP * Engine::Physics::PHYSICS_SCALE;
            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            // Physics
            entity->physicsBodyIds.push_back(b2_nullBodyId);
            Game::Components::Physics::createCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, city, DENSITY, FRICTION, RESTITUTION);

            // Graphics -> FUTURE IMPROVEMENT: have this handled in components::graphics so its one function call just like for physics
            // create first building
            entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
            auto *rect1 = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());
            Game::Components::Graphics::createBuilding(window, *rect1, sfmlPosition, city[0].width, city[0].height, COLOUR);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop for remaining buildings
            for (size_t i = 1; i < city.size(); i++)
            {
                // set offset
                offset.x += city[i].width / 2 + city[i - 1].width / 2;

                // create building
                entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
                auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[i].get());
                Game::Components::Graphics::createBuilding(window, *rect, sfmlPosition + offset, city[i].width, city[i].height, COLOUR);
            }
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            // Physics
            Game::Components::Physics::updateCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, MAX_BUMP, BUMP_VELOCITY);

            // Graphics -> FUTURE IMPROVEMENT: have this handled in components::graphics so its one function call just like for physics
            sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds.back())), window.getSize().y);
            float angle = 0.f;

            // update first building
            auto *rect1 = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());
            Game::Components::Graphics::updateShape(window, *rect1, newPosition, angle, false);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop for remaining buildings
            for (size_t i = 1; i < city.size(); i++)
            {
                // set offset
                offset.x += city[i].width / 2 + city[i - 1].width / 2;

                // update building
                auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[i].get());
                Game::Components::Graphics::updateShape(window, *rect, newPosition + offset, angle, false);
            }
        }

        void Cityscape::render(sf::RenderWindow &window)
        {
            for (size_t i = 0; i < entity->graphicsShapes.size(); i++)
            {
                window.draw(*entity->graphicsShapes[i]);
            }
        }

        void Cityscape::addBuilding(float width, float height)
        {
            city.push_back({width, height});
        }

    }
}