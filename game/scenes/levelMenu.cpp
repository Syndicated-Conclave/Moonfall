#include "levelMenu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"
#include "scenes/menu.hpp"
#include "../game/gameStates.hpp"

namespace Game
{
    namespace Scenes
    {
        void levelMenu::chooseLevel(sf::RenderWindow& window)
        {
            // Adding custom font and styling for title
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text thisTitle("Select Level", font, 88);
            title = thisTitle;
            title.setFillColor(sf::Color(255, 255, 224));
            title.setPosition({ 600.f, 100.f });

            // Creating gradient background colour
            sf::VertexArray thisSky(sf::Quads, 4);
            sky = thisSky;
            sky[0].position = sf::Vector2f(0, 0);
            sky[1].position = sf::Vector2f(window.getSize().x, 0);
            sky[2].position = sf::Vector2f(window.getSize().x, window.getSize().y);
            sky[3].position = sf::Vector2f(0, window.getSize().y);
            sf::Color deep(7, 7, 41);
            sf::Color light(24, 66, 75);
            sky[0].color = deep;
            sky[1].color = deep;
            sky[3].color = light;
            sky[2].color = light;



            // Creating Level Buttons
            levelOne.setSize({ 380.f, 65.f });
            levelOne.setPosition(600.f, 300.f);
            levelTwo.setSize({ 380.f, 65.f });
            levelTwo.setPosition(600.f, 400.f);
            levelThree.setSize({ 380.f, 65.f });
            levelThree.setPosition(600.f, 500.f);
            returnMenu.setSize({ 380.f, 65.f });
            returnMenu.setPosition(600.f, 600.f);

            levelOne.setFillColor(sf::Color(255, 255, 224));
            levelTwo.setFillColor(sf::Color(255, 255, 224));
            levelThree.setFillColor(sf::Color(255, 255, 224));
            returnMenu.setFillColor(sf::Color(255, 255, 224));

            //Making labels for my buttons
            sf::Text localLevelOne("Level One", font);
            LevelOne = localLevelOne;
            LevelOne.setCharacterSize(40);
            LevelOne.setFillColor(sf::Color(11, 27, 44));
            LevelOne.setPosition(730.f, 300.f);

            sf::Text localLevelTwo("Level Two", font);
            LevelTwo = localLevelOne;
            LevelTwo.setCharacterSize(40);
            LevelTwo.setFillColor(sf::Color(11, 27, 44));
            LevelTwo.setPosition(740.f, 400.f);


            sf::Text localLevelThree("Level Three", font);
            LevelThree = localLevelThree;
            LevelThree.setCharacterSize(40);
            LevelThree.setFillColor(sf::Color(11, 27, 44));
            LevelThree.setPosition(710.f, 500.f);

            sf::Text localReturnMenu("Return", font);
            ReturnMenu = localReturnMenu;
            ReturnMenu.setCharacterSize(40);
            ReturnMenu.setFillColor(sf::Color(11, 27, 44));
            ReturnMenu.setPosition(740.f, 600.f);

        }

        void levelMenu::draw(sf::RenderWindow& window)
        {
            window.clear();
            window.draw(sky);
            window.draw(title);
            window.draw(levelOne);
            window.draw(LevelOne);
            window.draw(levelTwo);
            window.draw(LevelTwo);
            window.draw(levelThree);
            window.draw(LevelThree);
            window.draw(returnMenu);
            window.draw(ReturnMenu);
            window.display();
        }







        void levelMenu::handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );
                if (levelOne.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Play" << std::endl;

                    Engine::EntityManager ecm;
                    gameState = Game::State::Playing;
                    std::cout << gameState;
                }
                if (levelTwo.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Lvl2" << std::endl;
                }
                if (levelThree.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Lvl3" << std::endl;
                }
                if (returnMenu.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Back" << std::endl;

                }


            }


        }
    }
}


            


        
    
