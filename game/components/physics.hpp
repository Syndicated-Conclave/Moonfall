#pragma once
#include "../../engine/physics.hpp"

// namespace for all game specific things
namespace Game
{
    // namespace for all entities
    namespace Entities
    {
        struct Building; // forward declare
    }

    // namespace for all components
    namespace Components
    {
        // PHYSICS

        // this class handles the physics of all entities
        class Physics
        {
        public:
            // used to create the cityscape physics body including all buildings shapes
            static void createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, std::vector<Game::Entities::Building> city, float density, float friction, float restitution);
            // used to update the cityscape entity, including handling user input
            static void updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity);
            // used to create the individual star physics bodies of each stardust entity
            static void createStar(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution);
            // used to update the stardust entities including all their stars
            static void updateStardust(sf::RenderWindow &window, std::vector<b2BodyId> bodyIds, sf::Vector2f direction, float speed, int &collectedPoints);
            // used to create the moon entity
            static void createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution);
            // used to update the moon entity, including handling user input
            static void updateMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, int cooldown, int &counter);

        private:
            // helper function used to create the bodyId for each physics body
            static b2BodyId setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window);
            // helper function used to create the shapeDef for each physics shape
            static b2ShapeDef setUpShapeDef(float density, float friction, float restitution);
        };
    }
}