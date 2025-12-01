#include "cityscape.hpp"
#include <iostream>

namespace Game
{
    namespace Entities
    {
        std::vector<Building> Cityscape::city;

        Cityscape::Cityscape(sf::RenderWindow &window, Engine::EntityManager &ecm) : entity(ecm.createEntity())
        {

            init_city();
            // float sfmlPosX = window.getSize().x / 2;
            float sfmlPosX = 60.f;
            float sfmlPosY = window.getSize().y;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            // Physics
            entity->physicsBodyIds.push_back(b2_nullBodyId);
            Game::Components::Physics::createCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, city, DENSITY, FRICTION, RESTITUTION);

            // Graphics
            entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
            auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());

            Game::Components::Graphics::createCityscape(window, *rect, sfmlPosition, city[0].width, city[0].height, COLOUR);

            sf::Vector2f offset = {city[0].width / 2, 0};

            for (size_t i = 1; i < city.size(); i++)
            {
                entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
                auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[i].get());

                Game::Components::Graphics::createCityscape(window, *rect, sfmlPosition + offset, city[i].width, city[i].height, COLOUR);
                offset.x += city[i].width;
            }
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            // Physics
            Game::Components::Physics::updateCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, MAX_BUMP, BUMP_VELOCITY);

            // Graphics
            sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds.back())), window.getSize().y);
            float angle = -b2Rot_GetAngle(b2Body_GetRotation(entity->physicsBodyIds.back())) * 180.f / B2_PI;

            auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());

            Game::Components::Graphics::updateShape(window, *rect, newPosition, angle);

            sf::Vector2f offset = {city[0].width / 2, 0};

            for (size_t i = 1; i < city.size(); i++)
            {
                auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[i].get());

                Game::Components::Graphics::updateShape(window, *rect, newPosition + offset, angle);
                offset.x += city[i].width;
            }
        }

        void Cityscape::render(sf::RenderWindow &window)
        {
            for (size_t i = 0; i < entity->graphicsShapes.size(); i++)
            {
                window.draw(*entity->graphicsShapes[i]);
            }
        }

        void Cityscape::init_city()
        {
            city.push_back({120.f, 300.f});
            city.push_back({150.f, 420.f});
            city.push_back({200.f, 180.f});
            city.push_back({130.f, 400.f});
            city.push_back({170.f, 390.f});
            city.push_back({120.f, 200.f});
            city.push_back({150.f, 220.f});
            city.push_back({200.f, 180.f});
            city.push_back({130.f, 300.f});
            city.push_back({170.f, 490.f});
            city.push_back({120.f, 200.f});
            city.push_back({150.f, 320.f});
            city.push_back({200.f, 180.f});
            city.push_back({130.f, 400.f});
            city.push_back({170.f, 390.f});
        }
    }

}
