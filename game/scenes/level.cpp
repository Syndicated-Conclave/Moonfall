#include "level.hpp"
#include <vector>
#include <iostream>
#include "../entities/cityscape.hpp"
#include "../entities/moon.hpp"

namespace Game
{
    namespace Scenes
    {
        void Level::basicPhysicsSetUp(sf::RenderWindow &window)
        {
            std::cout << "Reached basicPhysicsSetUp\n";
            // Vars
            sf::Color nightskyColour(24, 50, 100);

            std::cout << "Creating cityscape...\n";
            // Create cityscape & moon
            Game::Entities::Cityscape cityscape(window);
            std::cout << "Created cityscape.\n";

            std::cout << "Creating moon...\n";
            Game::Entities::Moon moon(window);
            std::cout << "Created moon.\n";

            // Loop
            while (window.isOpen())
            {
                std::cout << "Reached loop\n";
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                // Step the physics world
                Engine::Physics::update(Engine::Physics::timeStep);
                std::cout << "Time stepped physics world\n";

                // Update cityscape & moon
                std::cout << "Updating cityscape...\n";
                cityscape.update(window);
                std::cout << "Updated cityscape.\n";

                std::cout << "Updating moon...\n";
                moon.update(window);
                std::cout << "Updated moon.\n";

                // Render everything
                window.clear(nightskyColour);
                std::cout << "Rendered nightsky.\n";
                cityscape.render(window);
                std::cout << "Rendered cityscape.\n";
                moon.render(window);
                std::cout << "Rendered moon.\n";
                window.display();
                std::cout << "Displaying window.\n";
            }

            // Cleanup lab physics world
            std::cout << "Shutting down physics world...\n";
            Engine::Physics::shutdown();
            std::cout << "Shut down physics world.\n";
        }

    }
}
