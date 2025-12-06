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
#include "scenes/result.hpp"

int main()
{
    Game::State gameState = Game::State::Menu;

    sf::RenderWindow window(sf::VideoMode({Parameters::game_width, Parameters::game_height}), "Moonfall");
    Game::Components::AudioManager audioManager;
    audioManager.playMenuMusic();

    Game::Scenes::Menu menu;
    menu.mainMenu(window);

    Game::Scenes::levelMenu levelMenu;
    levelMenu.chooseLevel(window);

    Game::Scenes::Win win;
    win.showResult(window);

    Game::Scenes::Lose lose;
    lose.showResult(window);

    int levelSelection = 0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
            {
                gameState = Game::State::Exit;
            }
            else if (gameState == Game::State::Menu)
            {
                menu.handleEvent(window, audioManager, event, gameState);
            }
            else if (gameState == Game::State::LevelSelection)
            {
                levelSelection = levelMenu.handleEvent(window, audioManager, event, gameState);
            }
            else if (gameState == Game::State::GameWin)
            {
                win.handleEvent(window, event, gameState);
            }
            else if (gameState == Game::State::GameLose)
            {
                lose.handleEvent(window, event, gameState);
            }
        }

        switch (gameState)
        {
        case Game::State::Menu:
        {

            menu.draw(window);
            break;
        }
        case Game::State::LevelSelection:
        {
            levelMenu.draw(window);
        }
        case Game::State::Playing:
        {
            if (levelSelection)
            {
                audioManager.playGameplayMusic();
                Engine::Physics::initialise();

                Engine::EntityManager ecm;

                Game::Scenes::Level level;

                level.play(window, ecm, audioManager, gameState, levelSelection);
            }
            else
            {
                gameState = Game::State::LevelSelection;
            }

            break;
        }
        case Game::State::GameLose:
        {
            lose.draw(window);
            break;
        }
        case Game::State::GameWin:

        {
            win.draw(window);
            break;
        }
        case Game::State::Exit:
        {
            Engine::Physics::shutdown;
            window.close();
            break;
        }
        };
    }

    return 0;
}
