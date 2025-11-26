#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/utils.hpp"

namespace Game
{
    namespace Entities
    {

        class Moon
        {
        public:
            Moon(sf::RenderWindow &window);

            void update(sf::RenderWindow &window);
            void render(sf::RenderWindow &window);

            b2BodyId bodyId;       // box2d moon
            sf::CircleShape shape; // sfml moon
            sf::Vector2f sfmlPosition;

            static constexpr float SFML_DIAMETER = 100.f;

            static constexpr float DENSITY = 1.f;
            static constexpr float FRICTION = 0.3f;
            static constexpr float RESTITUTION = 0.0f;

            static constexpr int COLOUR = 0xF6F1D5; // hex value!
        };
    }
}
