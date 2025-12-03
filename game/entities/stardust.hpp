#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/utils.hpp"
#include "../../engine/ecm.hpp"
#include "../components/physics.hpp"
#include "../components/graphics.hpp"
#include "../components/ai.hpp"

// namespace for all game specific things
namespace Game
{
    // namespace for all entities
    namespace Entities
    {
        // STARDUST

        // this class is used to create and manage the stardust and its stars
        class Stardust
        {
        public:
            // FUNCTIONS

            // constructor which creates a new stardust entity made up of stars
            Stardust(sf::RenderWindow &window, Engine::EntityManager &ecm, sf::Vector2f sfmlPosition, int type);
            // handles updating all star components
            void update(sf::RenderWindow &window, sf::Vector2f moonPosition);
            // handles rendering the stars
            void render(sf::RenderWindow &window);

            // VARIABLES

            // holds a pointer to the stardust entity in the ecm
            Engine::Entity *entity;
            // holds the initial position of the stardust
            sf::Vector2f spawnPosition;
            // holds the type of stardust - 1 : Orion's Belt, 2 : Lyra, 3 : Leo
            // -> REFACTOR NEEDED: turn type into an enum
            int type;
            // holds the positions of each star in the stardust constellation
            std::vector<sf::Vector2f> constellation;
            // holds the direction in which the stardust is moving
            sf::Vector2f direction = {0, 0};

            // PARAMETERS

            // since box2d does not support 5 pointed stars (polygons have max 8 vertices) we use a circle as the stars physics body
            // this is the diameter of that circle, being slightly smaller than the full diameter of the sfml star shape
            static constexpr float SFML_DIAMETER = 14.f;
            // base speed at which the stardust moves in its idle pattern, fleeing adds a multiplier
            static constexpr float SPEED = 5.f;
            // minimal density since box2d requires it
            static constexpr float DENSITY = 1.f;
            // no friction since it does not have physics reactions other than contact events
            static constexpr float FRICTION = 0.0f;
            // no restitution since it does not have physics reactions other than contact events
            static constexpr float RESTITUTION = 0.0f;
            // colour of the stars as a hex value
            static constexpr int COLOUR = 0xFFFDD0;

        private:
            //  populates constellation vector based on type
            static std::vector<sf::Vector2f> init_constellation(int type);
        };
    }
}
