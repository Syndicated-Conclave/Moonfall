#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/ecm.hpp"

namespace Game
{
    namespace Scenes
    {
        class Level
        {
        public:
            void basicPhysicsSetUp(sf::RenderWindow &window, Engine::EntityManager &ecm);
        };
    }
}
