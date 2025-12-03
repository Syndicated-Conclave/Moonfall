#include "stardust.hpp"

namespace Game
{
    namespace Entities
    {
        Stardust::Stardust(sf::RenderWindow &window, Engine::EntityManager &ecm, sf::Vector2f sfmlPosition, int type) : entity(ecm.createEntity())
        {
            constellation = init_constellation(type);

            // each star in the stardust constellation has its own physics body and graphics shape
            // this is so they can easily move and act as one or as the individual stars as needed
            for (size_t i = 0; i < constellation.size(); i++)
            {
                // in each constellation a central star was determined which is used for positioning
                // this star is at the stardust's {0,0} so the offset is each stars coordinate
                spawnPosition = sfmlPosition;
                Stardust::type = type;
                sf::Vector2f offset = constellation[i];
                sf::Vector2f starSfmlPosition = sfmlPosition + offset;

                // Physics
                entity->physicsBodyIds.push_back(b2_nullBodyId);
                Game::Components::Physics::createStar(window, entity->physicsBodyIds.back(), starSfmlPosition, SFML_DIAMETER, DENSITY, FRICTION, RESTITUTION);

                // Graphics
                entity->graphicsShapes.push_back(std::make_unique<sf::ConvexShape>());
                auto *star = static_cast<sf::ConvexShape *>(entity->graphicsShapes.back().get());
                Game::Components::Graphics::createStar(window, *star, starSfmlPosition, SFML_DIAMETER, COLOUR);
            }
        }

        void Stardust::update(sf::RenderWindow &window, sf::Vector2f moonPosition, int &collectedPoints)
        {
            // AI (automated steering behaviour)
            sf::Vector2f currentPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds.front())), window.getSize().y);
            direction = Game::Components::AI::getDirection(direction, spawnPosition, currentPosition, moonPosition, type);

            // Physics
            Game::Components::Physics::updateStardust(window, entity->physicsBodyIds, direction, SPEED, collectedPoints);

            // Graphics
            for (size_t i = 0; i < entity->physicsBodyIds.size(); i++)
            {
                // if the star has not been collected
                if (b2Body_IsEnabled(entity->physicsBodyIds[i]))
                {
                    sf::Vector2f newPosition = Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(entity->physicsBodyIds[i])), window.getSize().y);
                    float angle = b2Rot_GetAngle(b2Body_GetRotation(entity->physicsBodyIds[i])) * 180.f / B2_PI;
                    Game::Components::Graphics::updateShape(window, *entity->graphicsShapes[i], newPosition, angle, false);
                }
            }
        }

        void Stardust::render(sf::RenderWindow &window)
        {
            for (size_t i = 0; i < entity->physicsBodyIds.size(); i++)
            {
                // if the star has not been collected
                if (b2Body_IsEnabled(entity->physicsBodyIds[i]))
                {
                    window.draw(*entity->graphicsShapes[i]);
                }
            }
        }

        std::vector<sf::Vector2f> Stardust::init_constellation(int type)
        {
            std::vector<sf::Vector2f> orionsBelt = {{0.f, 0.f}, {-17.f, 5.f}, {17.f, -7.f}};
            std::vector<sf::Vector2f> lyra = {{0.f, 0.f}, {-37.5f, -22.5f}, {-37.5f, 5.f}, {4.f, 33.f}, {12.5f, 60.f}};
            std::vector<sf::Vector2f> leo = {{0.f, 0.f}, {25.f, 5.f}, {40.f, 25.f}, {-10.f, -15.f}, {5.f, -45.f}, {30.f, -45.f}, {-50.f, 45.f}, {-30.f, 65.f}, {-70.f, 90.f}};
            switch (type)
            {
            case 1:
                return orionsBelt;
                break;
            case 2:
                return lyra;
                break;
            case 3:
                return leo;
                break;
            default:
                return orionsBelt; // should not happen, added as a failsafe
            }
        }

    }

}
