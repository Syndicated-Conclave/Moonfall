#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/utils.hpp"
#include "../../engine/ecm.hpp"
#include "../components/physics.hpp"
#include "../components/graphics.hpp"

namespace Game
{
    namespace Entities
    {
        class Cityscape
        {
        public:
            Cityscape(sf::RenderWindow &window, Engine::EntityManager &ecm);

            void update(sf::RenderWindow &window);
            void render(sf::RenderWindow &window);

            Engine::Entity *entity;
            sf::Vector2f sfmlPosition;
            float angle = 0.f; // radians

            static constexpr float SFML_WIDTH = 2000.f;
            static constexpr float SFML_HEIGHT = 200.f;

            static constexpr float TILT_SPEED = 0.02f;
            static constexpr float MAX_TILT = 0.25f;

            static constexpr float BUMP_VELOCITY = 2.f;
            static constexpr float MAX_BUMP = 1.f;

            static constexpr float DENSITY = 999999999999.f;
            static constexpr float FRICTION = 0.4f;    // glidiness
            static constexpr float RESTITUTION = 0.0f; // bounciness

            static constexpr int COLOUR = 0x282828; // hex value!
        };
    }
}
