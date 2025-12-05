#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"
#include "scenes/menu.hpp"
#include "../game/gameStates.hpp"
#include "../game/components/AudioManager.hpp"

int main()
{
    Game::State gameState = Game::State::Menu;

    sf::RenderWindow window(sf::VideoMode({Parameters::game_width, Parameters::game_height}), "Moonfall");
    Game::Components::AudioManager audioManager;
    audioManager.playMenuMusic();

    Game::Scenes::Menu menu;
    menu.mainMenu(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (gameState == Game::State::Menu)
            {
                menu.handleEvent(window, event, gameState);
            }
        }

        switch (gameState)
        {
        case Game::State::Menu:
        {

            menu.draw(window);
            break;
        }
        case Game::State::Playing:
        {
            audioManager.playGameplayMusic();
            Engine::Physics::initialise();

            Engine::EntityManager ecm;

            Game::Scenes::Level level;

            level.play(window, ecm, gameState, 2); // 1 for level 1, when testing your levels just change this number so play starts that while level menu is still being made
            break;
        }
        case Game::State::GameLose:
        {
            break;
        }
        case Game::State::GameWin:

        {
            break;
        }
        };
    }

    return 0;
}
