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

        class Stardust
        {
        public:
            Stardust(sf::RenderWindow &window, Engine::EntityManager &ecm, sf::Vector2f sfmlPosition, int type);

            void update(sf::RenderWindow &window);
            void render(sf::RenderWindow &window);

            Engine::Entity *entity;

            std::vector<sf::Vector2f> constellation;

            /*
            static constexpr float FIBO_ANGLE = 2.4f; // approximate
            */
            static constexpr float SFML_DIAMETER = 14.f;
            static constexpr float SPACING = 20.f;

            static constexpr float DENSITY = 1.f;
            static constexpr float FRICTION = 0.0f;
            static constexpr float RESTITUTION = 0.0f;

            static constexpr int COLOUR = 0xFFFDD0; // hex value!
        private:
            static std::vector<sf::Vector2f> init_constellation(int type);
        };
    }
}
