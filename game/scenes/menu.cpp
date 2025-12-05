
#include "menu.hpp"
#include "levelMenu.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

namespace Game
{
    namespace Scenes
    {
        void Menu::mainMenu(sf::RenderWindow& window)
        {
            // Adding custom font and styling for title
            font.loadFromFile("resources/HUSKYSTA.otf");
            sf::Text localTitle("Moonfall", font, 88);
            title = localTitle;
            title.setFillColor(sf::Color(255, 255, 224));
            title.setPosition({ 600.f, 100.f });

            // Creating gradient background colour
            sf::VertexArray localSky(sf::Quads, 4);
            sky = localSky;
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

            // Creating star object
            sf::ConvexShape localStar;
            star = localStar;
            star.setPointCount(10);
            star.setPoint(0, sf::Vector2f(8, -2));
            star.setPoint(1, sf::Vector2f(10, 3));
            star.setPoint(2, sf::Vector2f(15, 3));
            star.setPoint(3, sf::Vector2f(11, 6));
            star.setPoint(4, sf::Vector2f(12, 11));
            star.setPoint(5, sf::Vector2f(8, 8));
            star.setPoint(6, sf::Vector2f(4, 11));
            star.setPoint(7, sf::Vector2f(5, 6));
            star.setPoint(8, sf::Vector2f(1, 3));
            star.setPoint(9, sf::Vector2f(6, 3));
            star.setFillColor(sf::Color(255, 253, 208));
            star.scale({ 1.75f,1.75f });

            // Creating Menu Buttons
            guide.setSize({ 380.f,65.f });
            guide.setPosition(600.f, 300.f);
            play.setSize({ 380.f,65.f });
            play.setPosition(600.f, 400.f);
            controls.setSize({ 380.f,65.f });
            controls.setPosition(600.f, 500.f);
            exit.setSize({ 380.f,65.f });
            exit.setPosition(600.f, 600.f);

            guide.setFillColor(sf::Color(255, 255, 224));
            play.setFillColor(sf::Color(255, 255, 224));
            controls.setFillColor(sf::Color(255, 255, 224));
            exit.setFillColor(sf::Color(255, 255, 224));

            //Making labels for my buttons
            sf::Text localGuideText("Guide", font);
            guideText = localGuideText;
            guideText.setCharacterSize(40);
            guideText.setFillColor(sf::Color(11, 27, 44));
            guideText.setPosition(730.f, 300.f);

            sf::Text localPlayText("Play", font);
            playText = localPlayText;
            playText.setCharacterSize(40);
            playText.setFillColor(sf::Color(11, 27, 44));
            playText.setPosition(740.f, 400.f);


            sf::Text localControlsText("Controls", font);
            controlsText = localControlsText;
            controlsText.setCharacterSize(40);
            controlsText.setFillColor(sf::Color(11, 27, 44));
            controlsText.setPosition(710.f, 500.f);

            sf::Text localExitText("Exit", font);
            exitText = localExitText;
            exitText.setCharacterSize(40);
            exitText.setFillColor(sf::Color(11, 27, 44));
            exitText.setPosition(740.f, 600.f);
        }

        void Menu::draw(sf::RenderWindow& window)
        {

            window.clear();
            window.draw(sky);
            window.draw(title);
            star.setPosition({ 590.f, 200.f });
            window.draw(star);
            star.setPosition({ 620.f, 200.f });
            window.draw(star);
            star.setPosition({ 720.f, 200.f });
            window.draw(star);
            star.setPosition({ 750.f, 200.f });
            window.draw(star);
            star.setPosition({ 780.f, 200.f });
            window.draw(star);
            star.setPosition({ 810.f, 200.f });
            window.draw(star);
            star.setPosition({ 840.f, 200.f });
            window.draw(star);
            star.setPosition({ 870.f, 200.f });
            window.draw(star);
            star.setPosition({ 900.f, 200.f });
            window.draw(star);
            star.setPosition({ 930.f, 200.f });
            window.draw(star);
            star.setPosition({ 960.f, 200.f });
            window.draw(star);
            window.draw(guide);
            window.draw(guideText);
            window.draw(play);
            window.draw(playText);
            window.draw(controls);
            window.draw(controlsText);
            window.draw(exit);
            window.draw(exitText);
            window.display();



        }







        void Menu::handleEvent(sf::RenderWindow& window, sf::Event& event, Game::State& gameState)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window)
                );
                if (exit.getGlobalBounds().contains(mouse))
                {
                    window.close();
                }
                if (guide.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Guide" << std::endl;
                }
                if (play.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Play" << std::endl;

                    Engine::EntityManager ecm;
                    gameState = Game::State::Playing;
                    std::cout << gameState;
                }
                if (controls.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Controls" << std::endl;
                }

            }


        }
    }
}