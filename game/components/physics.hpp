#pragma once
#include "../../engine/physics.hpp"

namespace Game
{
    namespace Entities
    {
        struct Building; // forward declare
    }
    namespace Components
    {
        class Physics
        {
        public:
            static void createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, std::vector<Game::Entities::Building> city, float density, float friction, float restitution);
            static void updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity);
            static void createStar(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution);
            static void updateStardust(sf::RenderWindow &window, std::vector<b2BodyId> bodyIds, sf::Vector2f direction, float speed);
            static void createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution);

        private:
            static b2BodyId setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window);
            static b2ShapeDef setUpShapeDef(float density, float friction, float restitution);
        };
    }
}