#include "levelMenu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "menu.hpp"

namespace Game
{
    namespace Scenes
    {
        void levelMenu::chooseLevel(sf::RenderWindow& window, Engine::EntityManager& ecm)
        {
            // Adding custom font and styling for title
            sf::Font font;
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text title("Select Level", font, 88);
            title.setFillColor(sf::Color(255, 255, 224));
            title.setPosition({ 600.f, 100.f });

            // Creating gradient background colour
            sf::VertexArray sky(sf::Quads, 4);
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
            sf::RectangleShape levelOne({ 380.f, 65.f });
            levelOne.setPosition(600.f, 300.f);
            sf::RectangleShape levelTwo({ 380.f, 65.f });
            levelTwo.setPosition(600.f, 400.f);
            sf::RectangleShape levelThree({ 380.f, 65.f });
            levelThree.setPosition(600.f, 500.f);
            sf::RectangleShape returnMenu({ 380.f, 65.f });
            returnMenu.setPosition(600.f, 600.f);

            levelOne.setFillColor(sf::Color(255, 255, 224));
            levelTwo.setFillColor(sf::Color(255, 255, 224));
            levelThree.setFillColor(sf::Color(255, 255, 224));
            returnMenu.setFillColor(sf::Color(255, 255, 224));

            //Making labels for my buttons
            sf::Text LevelOne("Level One", font);
            LevelOne.setCharacterSize(40);
            LevelOne.setFillColor(sf::Color(11, 27, 44));
            LevelOne.setPosition(730.f, 300.f);

            sf::Text LevelTwo("Level Two", font);
            LevelTwo.setCharacterSize(40);
            LevelTwo.setFillColor(sf::Color(11, 27, 44));
            LevelTwo.setPosition(740.f, 400.f);


            sf::Text LevelThree("LevelThree", font);
            LevelThree.setCharacterSize(40);
            LevelThree.setFillColor(sf::Color(11, 27, 44));
            LevelThree.setPosition(710.f, 500.f);

            sf::Text ReturnMenu("Return", font);
            ReturnMenu.setCharacterSize(40);
            ReturnMenu.setFillColor(sf::Color(11, 27, 44));
            ReturnMenu.setPosition(740.f, 600.f);


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
        void levelMenu::handleEvent(sf::RenderWindow& window, sf::Event& event)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );
                if (levelOne.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Lvl1" << std::endl;

                    Engine::Physics::initialise();

                    Engine::EntityManager ecm;

                    //Game::Scenes::Level level1;

                    //level1.basicPhysicsSetUp(window, ecm);
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

            


    
