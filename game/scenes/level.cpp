#include "level.hpp"
#include <vector>
#include <iostream>

namespace Game
{
    namespace Scenes
    {
        void Level::play(sf::RenderWindow &window, Engine::EntityManager &ecm, Game::State &gameState, int level)
        {
            //  TEMP, WILL BE REPLACED BY CASSIE'S NIGHTSKY
            sf::Color nightskyColour(24, 50, 100);

            Game::Entities::Moon moon(window, ecm);
            Game::Entities::Cityscape cityscape(ecm);
            std::vector<Game::Entities::Stardust> allStardust;

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
            cityscape.addBuilding(120, 300);
            cityscape.addBuilding(150, 250);
            cityscape.addBuilding(200, 150);
            cityscape.addBuilding(40, 1);// gap
            cityscape.addBuilding(130, 150);
            cityscape.addBuilding(170, 160);
            cityscape.addBuilding(120, 170);
            cityscape.addBuilding(150, 180);
            cityscape.addBuilding(40, 1); //gap
            cityscape.addBuilding(200, 160);
            cityscape.addBuilding(130, 150);
            cityscape.addBuilding(170, 140);
            cityscape.addBuilding(120, 130);
            cityscape.addBuilding(40, 1); //gap
            cityscape.addBuilding(150, 130);
            cityscape.addBuilding(200, 140);
            cityscape.addBuilding(40, 1);//gap
            cityscape.addBuilding(130, 140);
            cityscape.addBuilding(170, 160);
            cityscape.addBuilding(200, 170);
            cityscape.addBuilding(150, 180);
            cityscape.addBuilding(40, 1); //gap
            cityscape.addBuilding(200, 180);
            cityscape.addBuilding(40, 1);//gap
            cityscape.addBuilding(150, 180);
            cityscape.addBuilding(120, 190);
            cityscape.addBuilding(170, 200);
            cityscape.addBuilding(130, 250);
            cityscape.addBuilding(250, 300);
            cityscape.addBuilding(40, 1);//gap
            cityscape.addBuilding(140, 400);
            cityscape.addBuilding(180, 450);

            allStardust.push_back(Game::Entities::Stardust(window, ecm, {240, 500}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {160, 600}, 1));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {130, 300}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {450, 250}, 2));
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {800, 300}, 3));

            return 15;
        }

    }
}
