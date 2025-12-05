#include "level.hpp"
#include <vector>
#include <iostream>

namespace Game
{
    namespace Scenes
    {
        float Game::Scenes::Level::levelWidth = 0;

        void Level::play(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::Components::AudioManager &audioManager, Game::State &gameState, int level)
        {
            //  TEMP, WILL BE REPLACED BY CASSIE'S NIGHTSKY
            sf::Color nightskyColour(24, 50, 100);

            Game::Entities::Moon moon(window, ecm);
            Game::Entities::Cityscape cityscape(ecm);
            std::vector<Game::Entities::Stardust> allStardust;

            cityscape.addBuilding(1, 3600);
            int requiredPoints;
            switch (level)
            {
            case 1:
                requiredPoints = Level::levelOne(window, ecm, cityscape, allStardust);
                break;
            case 2:
                requiredPoints = Level::levelThree(window, ecm, cityscape, allStardust);
                break;
            case 3:
                requiredPoints = Level::levelFour(window, ecm, cityscape, allStardust);
                break;
        }

            cityscape.addBuilding(1, 3600);

            Game::Scenes::Level::levelWidth = 0;
            for (size_t i = 1; i < cityscape.city.size() - 1; i++)
            {
                Game::Scenes::Level::levelWidth += cityscape.city[i].width;
            }

            cityscape.create(window);

            int counter = 0;
            while (gameState == Game::State::Playing)
            {

                // this should be removed as far as i know but removing it makes the window stop responding after a few seconds of playing
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

                // Update entities
                for (size_t i = 0; i < allStardust.size(); i++)
                {
                    allStardust[i].update(window, moon.sfmlPosition, Level::collectedPoints, audioManager);
                }

                cityscape.update(window);
                moon.update(window);

                // TEMPORARY WIN CONDITION ON WHICH RETURNS TO MENU
                if (collectedPoints >= requiredPoints)
                {
                    gameState = Game::State::Menu;
                }

                // Render everything
                window.clear(nightskyColour);
                cityscape.render(window);
                moon.render(window);
                for (size_t i = 0; i < allStardust.size(); i++)
                {
                    allStardust[i].render(window);
                }

                window.display();
            }

            // Cleanup physics world
            Engine::Physics::shutdown();
        }

        int Level::levelOne(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::Entities::Cityscape &cityscape, std::vector<Game::Entities::Stardust> &allStardust)
        {
            cityscape.addBuilding(120, 300);
            cityscape.addBuilding(150, 450);
            cityscape.addBuilding(200, 150);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(130, 400);
            cityscape.addBuilding(170, 300);
            cityscape.addBuilding(120, 200);
            cityscape.addBuilding(150, 250);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(200, 150);
            cityscape.addBuilding(130, 300);
            cityscape.addBuilding(170, 500);
            cityscape.addBuilding(120, 200);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(150, 350);
            cityscape.addBuilding(200, 150);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(130, 400);
            cityscape.addBuilding(170, 100);
            cityscape.addBuilding(200, 250);
            cityscape.addBuilding(150, 350);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(200, 600);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(150, 200);
            cityscape.addBuilding(120, 450);
            cityscape.addBuilding(170, 500);
            cityscape.addBuilding(130, 450);
            cityscape.addBuilding(250, 300);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(140, 450);
            cityscape.addBuilding(180, 250);

            allStardust.push_back(Game::Entities::Stardust(window, ecm, {300, 600}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {400, 300}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {800, 300}, 3));

            return 15;
        }

        int Level::levelThree(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::Entities::Cityscape &cityscape, std::vector<Game::Entities::Stardust> &allStardust)
        {
            cityscape.addBuilding(50, 1075);
            cityscape.addBuilding(150, 325);
            cityscape.addBuilding(30, 1);
            cityscape.addBuilding(200, 400);
            cityscape.addBuilding(130, 200);
            cityscape.addBuilding(170, 250);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(320, 350);
            cityscape.addBuilding(250, 425);
            cityscape.addBuilding(200, 325);
            cityscape.addBuilding(130, 160);
            cityscape.addBuilding(30, 1);
            cityscape.addBuilding(170, 700);
            cityscape.addBuilding(120, 200);
            cityscape.addBuilding(170, 700);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(200, 150);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(130, 400);
            cityscape.addBuilding(170, 100);
            cityscape.addBuilding(200, 250);
            cityscape.addBuilding(150, 550);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(200, 600);
            cityscape.addBuilding(60, 1);
            cityscape.addBuilding(150, 200);
            cityscape.addBuilding(120, 450);
            cityscape.addBuilding(170, 700);
            cityscape.addBuilding(130, 450);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(110, 900);
            cityscape.addBuilding(110, 750);
            cityscape.addBuilding(110, 900);
            cityscape.addBuilding(60, 1);
            cityscape.addBuilding(150, 550);
            cityscape.addBuilding(250, 425);
            cityscape.addBuilding(150, 550);

            allStardust.push_back(Game::Entities::Stardust(window, ecm, {1000, 300}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {2100, 300}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {3000, 300}, 3));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {3700, 300}, 1));

            return 17;
        }
        
        int Level::levelFour(sf::RenderWindow& window, Engine::EntityManager& ecm, Game::Entities::Cityscape& cityscape, std::vector<Game::Entities::Stardust>& allStardust)
        {
            cityscape.addBuilding(120, 280);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(80, 320);
            cityscape.addBuilding(100, 400);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(60, 440);
            cityscape.addBuilding(90, 520);
            cityscape.addBuilding(30, 1);
            cityscape.addBuilding(110, 600);
            cityscape.addBuilding(70, 480);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(80, 360);
            cityscape.addBuilding(100, 440);
            cityscape.addBuilding(120, 520);
            cityscape.addBuilding(50, 1);
            cityscape.addBuilding(90, 600);
            cityscape.addBuilding(70, 560);
            cityscape.addBuilding(60, 400);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(100, 300);
            cityscape.addBuilding(120, 360);
            cityscape.addBuilding(110, 460);
            cityscape.addBuilding(80, 520);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(90, 600);
            cityscape.addBuilding(100, 520);
            cityscape.addBuilding(120, 480);
            cityscape.addBuilding(60, 420);
            cityscape.addBuilding(70, 320);
            cityscape.addBuilding(30, 1);
            cityscape.addBuilding(80, 380);
            cityscape.addBuilding(100, 460);
            cityscape.addBuilding(120, 600);
            cityscape.addBuilding(90, 540);
            cityscape.addBuilding(60, 400);  // stardust checkpoint at 2640
            cityscape.addBuilding(80, 480);
            cityscape.addBuilding(100, 560);
            cityscape.addBuilding(120, 520);
            cityscape.addBuilding(60, 1);
            cityscape.addBuilding(70, 420);
            cityscape.addBuilding(80, 360);
            cityscape.addBuilding(110, 460);
            cityscape.addBuilding(90, 520);
            cityscape.addBuilding(100, 600);
            cityscape.addBuilding(120, 540);
            cityscape.addBuilding(80, 440);
            cityscape.addBuilding(70, 360);
            cityscape.addBuilding(60, 280);
            cityscape.addBuilding(100, 400);
            cityscape.addBuilding(50, 1);
            cityscape.addBuilding(120, 480);
            cityscape.addBuilding(80, 520);
            cityscape.addBuilding(100, 600);
            cityscape.addBuilding(70, 560);
            cityscape.addBuilding(60, 400);
            cityscape.addBuilding(20, 1);
            cityscape.addBuilding(90, 360);
            cityscape.addBuilding(120, 440);
            cityscape.addBuilding(110, 520);
            cityscape.addBuilding(80, 600);
            cityscape.addBuilding(100, 520);
            cityscape.addBuilding(120, 480);
            cityscape.addBuilding(40, 1);
            cityscape.addBuilding(60, 400);
            cityscape.addBuilding(80, 360);
            cityscape.addBuilding(100, 440);
            cityscape.addBuilding(110, 520);
            cityscape.addBuilding(90, 500);  // stardust checkpoint at 5460
            cityscape.addBuilding(70, 500);
            cityscape.addBuilding(80, 440);
            cityscape.addBuilding(100, 360);
            cityscape.addBuilding(120, 300);
            cityscape.addBuilding(90, 400);
            cityscape.addBuilding(30, 1);
            cityscape.addBuilding(110, 480);
            cityscape.addBuilding(100, 560);
            cityscape.addBuilding(70, 600);
            cityscape.addBuilding(60, 520);
            cityscape.addBuilding(80, 460);
            cityscape.addBuilding(120, 400);
            cityscape.addBuilding(100, 340);
            cityscape.addBuilding(110, 280);
            cityscape.addBuilding(120, 360);
            cityscape.addBuilding(100, 440);
            cityscape.addBuilding(90, 1);
            cityscape.addBuilding(80, 520);
            cityscape.addBuilding(60, 480);
            cityscape.addBuilding(100, 600);
            cityscape.addBuilding(110, 560);
            cityscape.addBuilding(120, 520);
            cityscape.addBuilding(80, 440);
            cityscape.addBuilding(100, 360);
            cityscape.addBuilding(120, 280);
            cityscape.addBuilding(220, 200); // stardust checkpoint at 8200

            allStardust.push_back(Game::Entities::Stardust(window, ecm, { 2640, 300 }, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, { 5460, 300 }, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, { 8200, 300 }, 3));

            return 15;
        }
    }
}
