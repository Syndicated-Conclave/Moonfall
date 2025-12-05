#pragma once
#include <SFML/Graphics.hpp>
#include "../../engine/physics.hpp"
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"
#include "../entities/cityscape.hpp"
#include "../entities/moon.hpp"
#include "../entities/stardust.hpp"

namespace Game
{
    namespace Scenes
    {
        class Level
        {
        public:
            void play(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::State &gameState, int level);

            int collectedPoints = 0;
            static float levelWidth;

        private:
            int levelOne(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::Entities::Cityscape &cityscape, std::vector<Game::Entities::Stardust> &allStardust);
            int levelThree(sf::RenderWindow& window, Engine::EntityManager& ecm, Game::Entities::Cityscape& cityscape, std::vector<Game::Entities::Stardust>& allStardust);
        };
    }
}
