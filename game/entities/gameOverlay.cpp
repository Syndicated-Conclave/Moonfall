#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <game/entities/gameOverlay.hpp>
#include <iostream>

namespace Game::Entities
{
    class DawnTimer()::UI
    {
        /*Adding custom font and styling for UI*/
        sf::Font font;
        font.loadFromFile("resources/HUSKYSTA.otf");
        sf::Text text("Time Left: ", font, 48);
        title.setFillColor(sf::Color(255, 255, 225));
        title.setPosition({20.f, 10.f});

        init();
        update();
        render();
    }

    class DustCounterUI()::UI
    {
        /*Adding custom font and styling for UI*/
        sf::Font font;
        font.loadFromFile("resources/HUSKYSTA.otf");
        sf::Text text("Dust Collected: ", font, 48);
        title.setFillColor(sf::Color(255, 255, 225));
        title.setPosition({-20.f, 10.f});

        init();
        update();
        render();
    }
}


