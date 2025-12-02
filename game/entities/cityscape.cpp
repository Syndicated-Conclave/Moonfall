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
            float sfmlPosY = window.getSize().y + MAX_BUMP * Engine::Physics::PHYSICS_SCALE;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            // Physics
            entity->physicsBodyIds.push_back(b2_nullBodyId);
            Game::Components::Physics::createCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, city, DENSITY, FRICTION, RESTITUTION);

            // Graphics
            // create first building
            entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
            auto *rect1 = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());
            Game::Components::Graphics::createCityscape(window, *rect1, sfmlPosition, city[0].width, city[0].height, COLOUR);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop for second++ building
            for (size_t i = 1; i < city.size(); i++)
            {
                // set offset
                offset.x += city[i].width / 2 + city[i - 1].width / 2;

                // create building

                entity->graphicsShapes.push_back(std::make_unique<sf::RectangleShape>());
                auto *rect = static_cast<sf::RectangleShape *>(entity->graphicsShapes[i].get());
                Game::Components::Graphics::createCityscape(window, *rect, sfmlPosition + offset, city[i].width, city[i].height, COLOUR);
            }
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            // Physics
            Game::Components::Physics::updateCityscape(window, entity->physicsBodyIds.back(), sfmlPosition, MAX_BUMP, BUMP_VELOCITY);

            // Graphics
            sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds.back())), window.getSize().y);
            float angle = 0.f;

            // update first bulding
            auto *rect1 = static_cast<sf::RectangleShape *>(entity->graphicsShapes[0].get());
            Game::Components::Graphics::updateShape(window, *rect1, newPosition, angle, false);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop for second++ buildings and offset
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

        void Cityscape::init_city()
        {
            // city.push_back({3600.f, 500.f});

            city.push_back({120.f, 300.f});
            city.push_back({150.f, 450.f});
            city.push_back({200.f, 150.f});
            city.push_back({40.f, 1.f}); // gap
            city.push_back({130.f, 400.f});
            city.push_back({170.f, 300.f});
            city.push_back({120.f, 200.f});
            city.push_back({150.f, 250.f});
            city.push_back({40.f, 1.f}); // gap
            city.push_back({200.f, 150.f});
            city.push_back({130.f, 300.f});
            city.push_back({170.f, 500.f});
            city.push_back({120.f, 200.f});
            city.push_back({40.f, 1.f}); // gap
            city.push_back({150.f, 350.f});
            city.push_back({200.f, 150.f});
            city.push_back({40.f, 1.f}); // gap
            city.push_back({130.f, 400.f});
            city.push_back({170.f, 100.f});
        }
    }

}
