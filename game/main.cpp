#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "parameters.hpp"
#include "../engine/physics.hpp"
#include "../engine/ecm.hpp"
#include "scenes/level.hpp"


int main()
{
    sf::RenderWindow window(sf::VideoMode({ Parameters::game_width, Parameters::game_height }), "Moonfall");


    // Adding custom font and styling for title
    sf::Font font;
    font.loadFromFile("resources/HUSKYSTA.otf");
    sf::Text title("Moonfall", font, 88);
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
    star.scale({ 1.75f,1.75f });
    // Creating Menu Buttons
    sf::RectangleShape guide({ 380.f, 65.f });
    guide.setPosition(600.f, 300.f);
    sf::RectangleShape play({ 380.f, 65.f });
    play.setPosition(600.f, 400.f);
    sf::RectangleShape controls({ 380.f, 65.f });
    controls.setPosition(600.f, 500.f);
    sf::RectangleShape exit({ 380.f, 65.f });
    exit.setPosition(600.f, 600.f);
    guide.setFillColor(sf::Color(255, 255, 224));
    play.setFillColor(sf::Color(255, 255, 224));
    controls.setFillColor(sf::Color(255, 255, 224));
    exit.setFillColor(sf::Color(255, 255, 224));


    sf::Text Guide("Guide", font);
    Guide.setCharacterSize(40);
    Guide.setFillColor(sf::Color(11, 27, 44));
    Guide.setPosition(730.f, 300.f);

    sf::Text Play("Play", font);
    Play.setCharacterSize(40);
    Play.setFillColor(sf::Color(11, 27, 44));
    Play.setPosition(740.f, 400.f);


    sf::Text Controls("Controls", font);
    Controls.setCharacterSize(40);
    Controls.setFillColor(sf::Color(11, 27, 44));
    Controls.setPosition(710.f, 500.f);

    sf::Text Exit("Exit", font);
    Exit.setCharacterSize(40);
    Exit.setFillColor(sf::Color(11, 27, 44));
    Exit.setPosition(740.f, 600.f);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
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
                    Engine::Physics::initialise();

                    Engine::EntityManager ecm;

                    Game::Scenes::Level level;

                    level.level1(window, ecm);


                }
                if (controls.getGlobalBounds().contains(mouse))
                {
                    std::cout << "Controls" << std::endl;
                }
            }
        }



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
        window.draw(Guide);
        window.draw(play);
        window.draw(Play);
        window.draw(controls);
        window.draw(Controls);
        window.draw(exit);
        window.draw(Exit);
        window.display();
    }

    return 0;
}
