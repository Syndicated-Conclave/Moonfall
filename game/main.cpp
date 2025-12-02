#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"
#include "../game/components/gameStates.hpp"

int main()
{
  Game::Components::GameState gameState = Game::Components::GameState::Menu;
  
  switch(gameState)
  {
    case Game::Components::GameState::Menu:
    
    break;

    case Game::Components::GameState::Playing:
    
    break;

    case Game::Components::GameState::GameLose:
    
    break;

    case Game::Components::GameState::GameWin:
    
    break;


  };
  
  sf::RenderWindow window(sf::VideoMode({Parameters::game_width, Parameters::game_height}), "Moonfall");

  Engine::Physics::initialise();

  Engine::EntityManager ecm;

  Game::Scenes::Level level;

  level.basicPhysicsSetUp(window, ecm);

  /*
  // Adding custom font and styling for title
  sf::Font font;
  font.loadFromFile("resources/HUSKYSTA.otf");
  sf::Text title("Moonfall", font, 48);
  title.setFillColor(sf::Color(255, 255, 224));
  title.setPosition({300.f, 30.f});

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

  // Creating star object
  sf::ConvexShape star;
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

  // Creating Menu Buttons
  sf::RectangleShape guide({180.f, 35.f});
  guide.setPosition(300.f, 130.f);
  sf::RectangleShape play({180.f, 35.f});
  play.setPosition(300.f, 180.f);
  sf::RectangleShape controls({180.f, 35.f});
  controls.setPosition(300.f, 230.f);
  sf::RectangleShape exit({180.f, 35.f});
  exit.setPosition(300.f, 280.f);
  guide.setFillColor(sf::Color(255, 255, 224));
  play.setFillColor(sf::Color(255, 255, 224));
  controls.setFillColor(sf::Color(255, 255, 224));
  exit.setFillColor(sf::Color(255, 255, 224));

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        window.close();
      }
    }

    window.clear();
    window.draw(sky);
    window.draw(title);
    star.setPosition({299.f, 87.f});
    window.draw(star);
    star.setPosition({360.f, 87.f});
    window.draw(star);
    star.setPosition({409.f, 87.f});
    window.draw(star);
    star.setPosition({464.f, 87.f});
    window.draw(star);
    window.draw(guide);
    window.draw(play);
    window.draw(controls);
    window.draw(exit);
    window.display();
  }
  */
  return 0;
}
