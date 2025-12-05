#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"
#include "../game/gameStates.hpp"
#include "scenes/menu.hpp"


int main()
{
    Game::State gameState = Game::State::Menu;

    switch (gameState)
    {
    case Game::State::Menu:

        break;

    case Game::State::Playing:

        break;

    case Game::State::GameLose:

        break;

    case Game::State::GameWin:

        break;


    };

    

    sf::RenderWindow window(sf::VideoMode({ Parameters::game_width, Parameters::game_height }), "Moonfall");
    Engine::EntityManager ecm;

    Game::Scenes::Menu mainMenu;

    
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            window.clear();
            window.display();
            }

        }

        return 0;
    }

