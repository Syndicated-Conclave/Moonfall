#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        class Level
        {
        public:
            void level1(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::State &gameState);

            int collectedPoints = 0;
        };
    }
}
