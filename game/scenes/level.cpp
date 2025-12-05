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
            
            cityscape.addBuilding(100, 600);
            cityscape.addBuilding(400, 600);
            cityscape.addBuilding(400, 700);
            cityscape.addBuilding(500, 800);//SD
            cityscape.addBuilding(600, 600);
            cityscape.addBuilding(700, 1); //gap
            cityscape.addBuilding(750, 500);
            cityscape.addBuilding(800, 550); //SD
            cityscape.addBuilding(900, 550);
            cityscape.addBuilding(100, 500);
            cityscape.addBuilding(110, 1); //gap
            cityscape.addBuilding(120, 1); //gap
            cityscape.addBuilding(135, 550);
            cityscape.addBuilding(145, 500);
            cityscape.addBuilding(150, 400); // SD
            cityscape.addBuilding(165, 400);
            cityscape.addBuilding(170, 400);
            cityscape.addBuilding(175, 1); //gap
            cityscape.addBuilding(180, 1); //gap
            cityscape.addBuilding(185, 450);
            cityscape.addBuilding(190, 400);
            cityscape.addBuilding(195, 400); //SD           
            cityscape.addBuilding(200, 500);
            cityscape.addBuilding(205, 500);
            cityscape.addBuilding(210, 600);
            cityscape.addBuilding(215, 1); //gap
            cityscape.addBuilding(220, 600);
            cityscape.addBuilding(235, 650); //SD
            cityscape.addBuilding(240, 600);
            cityscape.addBuilding(245, 600);
            cityscape.addBuilding(250, 1); //gap
            cityscape.addBuilding(255, 500);
            cityscape.addBuilding(260, 450); //SD
            cityscape.addBuilding(265, 400);
            cityscape.addBuilding(270, 400);
            cityscape.addBuilding(280, 1); //gap
            cityscape.addBuilding(285, 450);
            cityscape.addBuilding(290, 400);
            cityscape.addBuilding(410, 1); //gap
            cityscape.addBuilding(415, 400);
            

            // total amount of stars: 100 
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {200, 500}, 1)); //3
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {1000, 450}, 1)); //3
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {5000, 500}, 2));//5
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {8000, 450}, 2));//5
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {10500, 500}, 3));//9
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {15000, 450}, 2));//5
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {25000, 450}, 2));//5
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {30000, 500}, 2));//5
            allStardust.push_back(Game::Entities::Stardust(window, ecm, {40000, 500}, 2));//5

            return 80;
        }

    }
}
