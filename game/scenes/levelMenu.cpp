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
        void levelMenu::chooseLevel(sf::RenderWindow &window)
        {
            // Adding custom font and styling for title
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text thisTitle("Select Level", font, 88);
            title = thisTitle;
            title.setFillColor(sf::Color(255, 255, 224));
            title.setPosition({Parameters::game_width / 2 - title.getGlobalBounds().width / 2, 100.f});

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
            levelOne.setSize({380.f, 65.f});
            levelOne.setPosition(Parameters::game_width / 2 - levelOne.getGlobalBounds().width / 2, 300.f);
            levelTwo.setSize({380.f, 65.f});
            levelTwo.setPosition(Parameters::game_width / 2 - levelTwo.getGlobalBounds().width / 2, 400.f);
            levelThree.setSize({380.f, 65.f});
            levelThree.setPosition(Parameters::game_width / 2 - levelOne.getGlobalBounds().width / 2, 500.f);
            levelFour.setSize({380.f, 65.f});
            levelFour.setPosition(Parameters::game_width / 2 - levelFour.getGlobalBounds().width / 2, 600.f);
            returnMenu.setSize({380.f, 65.f});
            returnMenu.setPosition(Parameters::game_width / 2 - returnMenu.getGlobalBounds().width / 2, 700.f);

            levelOne.setFillColor(sf::Color(255, 255, 224));
            levelTwo.setFillColor(sf::Color(255, 255, 224));
            levelThree.setFillColor(sf::Color(255, 255, 224));
            levelFour.setFillColor(sf::Color(255, 255, 224));
            returnMenu.setFillColor(sf::Color(255, 255, 224));

            // Making labels for my buttons
            sf::Text localLevelOne("Level One", font);
            LevelOne = localLevelOne;
            LevelOne.setCharacterSize(40);
            LevelOne.setFillColor(sf::Color(11, 27, 44));
            LevelOne.setPosition(Parameters::game_width / 2 - LevelOne.getGlobalBounds().width / 2, 300.f);

            sf::Text localLevelTwo("Level Two", font);
            LevelTwo = localLevelTwo;
            LevelTwo.setCharacterSize(40);
            LevelTwo.setFillColor(sf::Color(11, 27, 44));
            LevelTwo.setPosition(Parameters::game_width / 2 - LevelOne.getGlobalBounds().width / 2, 400.f);

            sf::Text localLevelThree("Level Three", font);
            LevelThree = localLevelThree;
            LevelThree.setCharacterSize(40);
            LevelThree.setFillColor(sf::Color(11, 27, 44));
            LevelThree.setPosition(Parameters::game_width / 2 - LevelOne.getGlobalBounds().width / 2, 500.f);

            sf::Text localLevelFour("Level Four", font);
            LevelFour = localLevelFour;
            LevelFour.setCharacterSize(40);
            LevelFour.setFillColor(sf::Color(11, 27, 44));
            LevelFour.setPosition(Parameters::game_width / 2 - LevelOne.getGlobalBounds().width / 2, 600.f);

            sf::Text localReturnMenu("Return", font);
            ReturnMenu = localReturnMenu;
            ReturnMenu.setCharacterSize(40);
            ReturnMenu.setFillColor(sf::Color(11, 27, 44));
            ReturnMenu.setPosition(Parameters::game_width / 2 - ReturnMenu.getGlobalBounds().width / 2, 700.f);
        }

        void levelMenu::draw(sf::RenderWindow &window)
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
            window.draw(levelFour);
            window.draw(LevelFour);
            window.draw(returnMenu);
            window.draw(ReturnMenu);
            window.display();
        }

        int levelMenu::handleEvent(sf::RenderWindow &window, Game::Components::AudioManager &audioManager, sf::Event &event, Game::State &gameState)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));
                if (levelOne.getGlobalBounds().contains(mouse))
                {
                    // std::cout << "Lvl1" << std::endl;
                    audioManager.playMenuUISound();

                    gameState = Game::State::Playing;
                    return 1;
                }
                if (levelTwo.getGlobalBounds().contains(mouse))
                {
                    // std::cout << "Lvl2" << std::endl;
                    audioManager.playMenuUISound();

                    gameState = Game::State::Playing;
                    return 2;
                }
                if (levelThree.getGlobalBounds().contains(mouse))
                {
                    // std::cout << "Lvl3" << std::endl;
                    audioManager.playMenuUISound();
                    gameState = Game::State::Playing;
                    return 3;
                }
                if (levelFour.getGlobalBounds().contains(mouse))
                {
                    // std::cout << "Lvl4" << std::endl;
                    audioManager.playMenuUISound();
                    gameState = Game::State::Playing;
                    return 4;
                }
                if (returnMenu.getGlobalBounds().contains(mouse))
                {
                    gameState = Game::State::Menu;
                    audioManager.playMenuUISound();
                    // std::cout << "Back" << std::endl;
                }
            }
        }
    }
}
