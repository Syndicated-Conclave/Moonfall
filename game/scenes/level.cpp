#include "level.hpp"
#include <vector>
#include <iostream>
#include "../entities/cityscape.hpp"
#include "../entities/moon.hpp"
#include "../entities/stardust.hpp"

namespace Game
{
    namespace Scenes
    {
        void Level::level1(sf::RenderWindow &window, Engine::EntityManager &ecm)
        {
            // std::cout << "Reached basicPhysicsSetUp\n";
            //  Vars
            sf::Color nightskyColour(24, 50, 100);

            // std::cout << "Creating cityscape...\n";
            //  Create cityscape & moon
            Game::Entities::Cityscape cityscape(window, ecm);
            // std::cout << "Created cityscape.\n";

            // std::cout << "Creating moon...\n";
            Game::Entities::Moon moon(window, ecm);
            // std::cout << "Created moon.\n";

            // std::cout << "Creating stardust...\n";
            Game::Entities::Stardust stardust(window, ecm, {300, 600}, 1);
            Game::Entities::Stardust stardust2(window, ecm, {400, 300}, 2);
            Game::Entities::Stardust stardust3(window, ecm, {800, 300}, 3);

            // std::cout << "Created stardust.\n";

            window.setKeyRepeatEnabled(false);
            int counter = 0;
            // Loop
            while (window.isOpen())
            {
                // std::cout << "Reached loop\n";
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                    {
                        window.close();
                    }
                }

                // Step the physics world
                Engine::Physics::update();
                // std::cout << "Time stepped physics world\n";
                // std::cout << counter++ << "\n";
                // Update cityscape & moon

                stardust.update(window, moon.sfmlPosition);
                stardust2.update(window, moon.sfmlPosition);
                stardust3.update(window, moon.sfmlPosition);
                // std::cout << "Updating cityscape...\n";
                cityscape.update(window);
                // std::cout << "Updated cityscape.\n";

                // std::cout << "Updating moon...\n";
                moon.update(window);
                // std::cout << "Updated moon.\n";

                // Render everything
                window.clear(nightskyColour);
                // std::cout << "Rendered nightsky.\n";
                cityscape.render(window);
                // std::cout << "Rendered cityscape.\n";
                moon.render(window);
                // std::cout << "Rendered moon.\n";

                stardust.render(window);
                stardust2.render(window);
                stardust3.render(window);

                window.display();
                // std::cout << "Displaying window.\n";
            }

            // Cleanup lab physics world
            // std::cout << "Shutting down physics world...\n";
            Engine::Physics::shutdown();
            // std::cout << "Shut down physics world.\n";
        }

    }
}
