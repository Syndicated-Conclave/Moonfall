#include "level.hpp"
#include <vector>
#include <iostream>

namespace Game
{
    namespace Scenes
    {
        float Game::Scenes::Level::levelWidth = 0;

        void Level::play(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::State &gameState, int level)
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
                requiredPoints = Level::levelTwo(window, ecm, cityscape, allStardust);
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
                    allStardust[i].update(window, moon.sfmlPosition, Level::collectedPoints);
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

        int Level::levelTwo(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::Entities::Cityscape &cityscape, std::vector<Game::Entities::Stardust> &allStardust) //Rob's Level
        {
            
            cityscape.addBuilding(200, 600);
            cityscape.addBuilding(300, 600);
            cityscape.addBuilding(400, 700);
            cityscape.addBuilding(500, 800); //SD
            cityscape.addBuilding(600, 600);
            cityscape.addBuilding(700, 1); //gap
            cityscape.addBuilding(750, 500);
            cityscape.addBuilding(800, 550); //SD
            cityscape.addBuilding(900, 550);
            cityscape.addBuilding(1000, 500);
            cityscape.addBuilding(1100, 1); //gap
            cityscape.addBuilding(1200, 1); //gap
            cityscape.addBuilding(1350, 550);
            cityscape.addBuilding(1450, 500);
            cityscape.addBuilding(1500, 400); // SD
            cityscape.addBuilding(1650, 400);
            cityscape.addBuilding(1700, 400);
            cityscape.addBuilding(1750, 1); //gap
            cityscape.addBuilding(1800, 1); //gap
            cityscape.addBuilding(1850, 450);
            cityscape.addBuilding(1900, 400);
            cityscape.addBuilding(1950, 400); //SD           
            cityscape.addBuilding(2000, 500);
            cityscape.addBuilding(2050, 500);
            cityscape.addBuilding(2100, 600);
            cityscape.addBuilding(2150, 1); //gap
            cityscape.addBuilding(2200, 600);
            cityscape.addBuilding(2350, 650); //SD
            cityscape.addBuilding(2400, 600);
            cityscape.addBuilding(2450, 600);
            cityscape.addBuilding(2500, 1); //gap
            cityscape.addBuilding(2550, 500);
            cityscape.addBuilding(2600, 450); //SD
            cityscape.addBuilding(2650, 400);
            cityscape.addBuilding(2700, 400);
            cityscape.addBuilding(2800, 1); //gap
            cityscape.addBuilding(2850, 450);
            cityscape.addBuilding(2900, 400);
            cityscape.addBuilding(4100, 1); //gap
            cityscape.addBuilding(4150, 400);
            cityscape.addBuilding(4200, 450); //SD
            cityscape.addBuilding(4250, 400);
            cityscape.addBuilding(4250, 450);
            cityscape.addBuilding(4300, 1); //gap
            cityscape.addBuilding(4350, 400);
            cityscape.addBuilding(4350, 1); //gap
            cityscape.addBuilding(4400, 400);
            cityscape.addBuilding(4450, 400);
            cityscape.addBuilding(4450, 450); //SD
            cityscape.addBuilding(4500, 500);
            cityscape.addBuilding(4500, 500);
            cityscape.addBuilding(4600, 1); //gap
            cityscape.addBuilding(4650, 500); //SD
            cityscape.addBuilding(4700, 550); 

            allStardust.push_back(Game::Entities::Stardust(window, ecm, {500, 500}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {800, 550}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {1500, 450}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {1950, 450}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {2350, 700}, 3));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {2600, 500}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {4200, 500}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {4450, 500}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {4650, 500}, 2));

            return 15;
        }

    }
}
