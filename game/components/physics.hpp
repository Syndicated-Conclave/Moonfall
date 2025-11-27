#pragma once
#include "../../engine/physics.hpp"

namespace Game
{
    namespace Components
    {
        class Physics
        {
        public:
            static void createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, float density, float friction, float restitution);
            static void updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, float &angle, float maxTilt, float tiltSpeed, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity);

            static void createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution);

        private:
            static b2BodyId setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window);
            static b2ShapeDef setUpShapeDef(float density, float friction, float restitution);
        };
    }
}