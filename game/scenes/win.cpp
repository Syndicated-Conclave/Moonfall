#pragma once
#include "result.hpp"
#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
#include "../gameStates.hpp"
#include "parameters.hpp"

namespace Game
{
    namespace Scenes
    {
        void Win::showResult(sf::RenderWindow &window)
        {
            // Adding custom font
            font.loadFromFile("resources/HUSKYSTA.otf");

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

            // Creating Menu Buttons
            win.setSize({380.f, 65.f});
            win.setPosition(Parameters::game_width / 2 - win.getGlobalBounds().width / 2, 300.f);
            back.setSize({380.f, 65.f});
            back.setPosition(Parameters::game_width / 2 - back.getGlobalBounds().width / 2, 500.f);

            win.setFillColor(sf::Color(11, 11, 24));
            back.setFillColor(sf::Color(255, 255, 224));

            // Making labels for my buttons
            sf::Text localwinText("You've won!", font);
            winText = localwinText;
            winText.setCharacterSize(40);
            winText.setFillColor(sf::Color(255, 255, 224));
            winText.setPosition(Parameters::game_width / 2 - winText.getGlobalBounds().width / 2 + 20, 300.f);

            sf::Text localbackText("Return to menu", font);
            backText = localbackText;
            backText.setCharacterSize(40);
            backText.setFillColor(sf::Color(11, 27, 44));
            backText.setPosition(Parameters::game_width / 2 - backText.getGlobalBounds().width / 2, 500.f);
        }

        void Win::draw(sf::RenderWindow &window)
        {

            window.clear();
            window.draw(sky);
            window.draw(win);
            window.draw(winText);
            window.draw(back);
            window.draw(backText);
            window.display();
        }

        void Win::handleEvent(sf::RenderWindow &window, sf::Event &event, Game::State &gameState)
        {
            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2f mouse = window.mapPixelToCoords(
                    sf::Mouse::getPosition(window));
                if (back.getGlobalBounds().contains(mouse))
                {

                    gameState = Game::State::Menu;
                    // std::cout << "Return to menu" << std::endl;
                }
            }
        }
    }
}
