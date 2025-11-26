#include "level.hpp"
#include <vector>
#include <iostream>
#include <./entities/cityscape.hpp>
#include <./entities/moon.hpp>

namespace Game
{
    namespace Scenes
    {
        void Level::basicPhysicsSetUp(sf::RenderWindow &window)
        {
            // Vars
            sf::Color nightskyColour(24, 50, 100);

            // Initialise physics world
            PhysicsEngine::initialise();
            b2WorldId worldId = PhysicsEngine::getWorldId();

            // Create cityscape & moon
            Game::Entities::Cityscape cityscape(window);
            Game::Entities::Moon moon(window);

            // Loop
            while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                // Step the physics world
                PhysicsEngine::update(PhysicsEngine::timeStep);

                // Update cityscape & moon
                cityscape.update(window);
                moon.update(window);

                // Render everything
                window.clear(nightskyColour);
                cityscape.render(window);
                moon.render(window);
                window.display();
            }

            // Cleanup lab physics world
            PhysicsEngine::shutdown();
        }

    }
}
