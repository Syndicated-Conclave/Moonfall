#pragma once
#include <SFML/Graphics.hpp>

// namespace for all game specific things
namespace Game
{
    // namespace for all components
    namespace Components
    {
        // AI

        // this class deals with entity's automated behaviour like the stardust's movement patterns
        class AI
        {
        public:
            // function returning a direction vector used by all stardust types
            static sf::Vector2f getDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition, int type);

            // how close the moon can get to the stardust before the stardust starts to flee
            static constexpr float FLEE_DISTANCE = 300.f;
            // the speed multiplier applied to the direction vector to make fleeing faster than idle movement
            static constexpr float FLEE_SPEED = 3.f;

        private:
            // function to calculate the direction vector for the medium sized stardust type
            static sf::Vector2f getLyraDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition);
            // function to calculate the direction vector for the large sized stardust type
            static sf::Vector2f getLeoDirection(sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition);
            // helper function to normalise a direction vector
            static sf::Vector2f normaliseDirection(sf::Vector2f direction);
            // helper function to compare two coordinates to see if they are close enough
            static bool goalReached(sf::Vector2f current, sf::Vector2f goal);
        };
    }
}
