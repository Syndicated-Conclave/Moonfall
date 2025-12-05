#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode({1600, 900}), "Moonfall");

  Engine::Physics::initialise();

  Engine::EntityManager ecm;

  Game::Scenes::Level levels;

  levels.level1(window, ecm);
}
