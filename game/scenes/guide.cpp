
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "../../engine/ecm.hpp"
#include "guide.hpp"


namespace Game
{
    namespace Scenes
    {
        void Guide::instruct(sf::RenderWindow& window, Engine::EntityManager& ecm)
        {
            // Adding custom font and styling for title
            sf::Font font;
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text title("How to play Moonfall", font, 88);
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


            //Creating Instruction Box
            sf::RectangleShape instruct({ 380.f, 100.f });
            instruct.setPosition(600.f, 300.f);
            instruct.setFillColor(sf::Color(255, 255, 224));

            //Making text label to place over box
            sf::Text example("Example", font);
            example.setCharacterSize(40);
            example.setFillColor(sf::Color(11, 27, 44));
            example.setPosition(730.f, 300.f);



            // Creating Menu Buttons
            sf::RectangleShape back({ 380.f, 65.f });
            back.setPosition(600.f, 800.f);
            back.setFillColor(sf::Color(255, 255, 224));


            //Making labels for my buttons
            sf::Text Back("Return", font);
            Back.setCharacterSize(40);
            Back.setFillColor(sf::Color(11, 27, 44));
            Back.setPosition(730.f, 300.f);


            window.clear();
            window.draw(sky);
            window.draw(title);
            window.draw(back);
            window.draw(Back);
            window.display();



        }
        void Guide::handleEvent(sf::RenderWindow& window, sf::Event& event)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );
                if (back.getGlobalBounds().contains(mouse));
                {
                    Engine::EntityManager ecm;
                    //Menu.mainMenu(window, ecm);
                }



            }
        }


    }
} 