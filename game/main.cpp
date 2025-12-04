#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"

int main()
{
  sf::RenderWindow window(sf::VideoMode({ 1600, 900 }), "Moonfall");


  // Engine::Physics::initialise();

  // Engine::EntityManager ecm;

  // Game::Scenes::Level levels;

  // levels.level1(window, ecm);

  
  // Adding custom font and styling for title
  sf::Font font;
  font.loadFromFile("resources/HUSKYSTA.otf");
  sf::Text title("Time Till Sunrise: ", font, 28);
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

  
  // Creating Menu Buttons
  sf::RectangleShape block({400.f, 65.f});
  block.setPosition(600.f, 20.f);
  sf::RectangleShape countdownBox({180.f, 35.f});
  countdownBox.setPosition(880.f, 33.f); 
 
  block.setFillColor(sf::Color(11, 11, 24));
  countdownBox.setFillColor(sf::Color(8, 10, 43));

  //timer
  sf::Clock countdown;
  /*Setting game time to two minutes*/
  int gameTime = 120;
  sf::Text CountdownText(" : ", font, 28);
  CountdownText.setFillColor(sf::Color(255, 255, 224));
  CountdownText.setPosition(890.f, 35.f); 
 


  
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        
        window.close();
      }
      float timeLeft = countdown.getElapsedTime().asSeconds();
      float countdowntext = gameTime - timeLeft;
      if(countdowntext < 0) countdowntext = 0;
      CountdownText.setString(std::to_string((int)countdowntext));
      

    }

    window.clear();
    window.draw(sky);
    window.draw(block);
    window.draw(countdownBox);
    window.draw(title);
    window.draw(CountdownText);
    window.display();
  }
  return 0;
}
