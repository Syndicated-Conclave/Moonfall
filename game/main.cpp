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

  // Adding custom font and styling for counter text
    int CollectedPoints = 0;
    int RequiredPoints;
    
    sf::Text counterText("Star Dust Collected: " + CollectedPoints, font, 28);
    counterText.setFillColor(sf::Color(255, 255, 224));
    counterText.setPosition({380.f, 40.f});

    // Creating boxes for timer text
    sf::RectangleShape counterBlock({400.f, 65.f});
    counterBlock.setPosition(380.f, 40.f);
    sf::RectangleShape counterBox({180.f, 35.f});
    counterBox.setPosition(380.f, 40.f);
    
    counterBlock.setFillColor(sf::Color(11, 11, 24));
    counterBox.setFillColor(sf::Color(8, 10, 43));
    
    // Adding custom font and styling for countdown text   
    sf::Text timerText("Time Till Sunrise: ", font, 28);
    timerText.setFillColor(sf::Color(255, 255, 224));
    timerText.setPosition({1200.f, 30.f});

    // Creating boxes for timer text
    sf::RectangleShape timerBlock({400.f, 65.f});
    timerBlock.setPosition(1180.f, 20.f);
    sf::RectangleShape timerBox({180.f, 35.f });
    timerBox.setPosition(1180.f, 33.f); 
    
    timerBlock.setFillColor(sf::Color(11, 11, 24));
    timerBox.setFillColor(sf::Color(8, 10, 43));

    //timer functionality
    sf::Clock timer;
    /*Setting game time to two minutes*/
    int gameTime = 120;
    sf::Text TimerText(" : ", font, 28);
    TimerText.setFillColor(sf::Color(255, 255, 224));
    TimerText.setPosition(890.f, 35.f);
 
  
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
      {
        
        window.close();
      }
      float timeLeft = timer.getElapsedTime().asSeconds();
      float timertext = gameTime - timeLeft;
      if(timertext < 0) timertext = 0;
      TimerText.setString(std::to_string((int)timertext));
      

    }

    window.clear();
    window.draw(sky);
    window.draw(timerBlock);
    window.draw(timerBox);
    window.draw(timerText);
    window.draw(TimerText);

    window.draw(counterBlock);
    window.draw(counterBox);
    window.draw(counterText);
    window.display();
  }
  return 0;
}
