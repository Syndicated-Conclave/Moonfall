#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/utils.hpp"
#include "../../engine/ecm.hpp"
#include "../components/physics.hpp"
#include "../components/graphics.hpp"

// namespace for all game specific things
namespace Game
{
    // namespace for all entities
    namespace Entities
    {
        // MOON

        // this class is used to create and manage the moon (the player)
        class Moon
        {
        public:
            //  FUNCTIONS

            // constructor which creates the moon
            Moon(sf::RenderWindow &window, Engine::EntityManager &ecm);
            // handles updating all moon components
            void update(sf::RenderWindow &window);
            // handles rendering the moon
            void render(sf::RenderWindow &window);

            //  VARIABLES

            // holds a pointer to the moon entity in the ecm
            Engine::Entity *entity;
            // holds the current position of the moon
            sf::Vector2f sfmlPosition;
            // keeps track of the jump cooldown
            int jumpCooldownCounter = 0;

            //  PARAMETERS

            // the length of the jump cooldown in physics steps
            static constexpr int JUMP_COOLDOWN_PERIOD = 600;
            // the diameter of the moon
            static constexpr float SFML_DIAMETER = 100.f;
            // minimal density to allow forces to act on it easily
            static constexpr float DENSITY = 1.f;
            // medium friction to avoid gliding across the cityscape
            static constexpr float FRICTION = 0.5f;
            // minimal bounce
            static constexpr float RESTITUTION = 0.1f;
            // colour of the moon as a hex value
            static constexpr int COLOUR = 0xF6F1D5;
        };
    }
}
