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
        // BUILDING

        // this struct is used to hold the width and height of each individual building
        struct Building
        {
            float width;
            float height;
        };

        // CITYSCAPE

        // this class is used to create and manage the cityscape and its buildings
        class Cityscape
        {
        public:
            //  FUNCTIONS

            // constructor which creates a new cityscape
            Cityscape(sf::RenderWindow &window, Engine::EntityManager &ecm);
            // handles updating all cityscape components
            void update(sf::RenderWindow &window);
            // handles rendering the cityscape
            void render(sf::RenderWindow &window);

            // VARIABLES

            // holds a pointer to the cityscape entity in the ecm
            Engine::Entity *entity;
            // holds the starting position of the cityscape
            sf::Vector2f sfmlPosition;
            // holds all buildings
            std::vector<Building> city;

            // PARAMETERS

            // how fast the cityscape moves up when space is pressed
            static constexpr float BUMP_VELOCITY = 2.f;
            // how hight the cityscape can moves up when space is pressed
            static constexpr float MAX_BUMP = 1.f;
            // high density for the bump to apply enough force to the moon for it to jump
            static constexpr float DENSITY = 999999999999.f;
            // relatively high to avoid moon gliding across the cityscape
            static constexpr float FRICTION = 0.7f;
            // minimal bounce
            static constexpr float RESTITUTION = 0.1f;
            // colour of the buildings as a hex value
            static constexpr int COLOUR = 0x282828;

        private:
            // function to populate the city vector with buildings
            void init_city();
        };

    }
}
