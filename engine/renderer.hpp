/*

FROM THE LABS:


#pragma once //ensures that the file is included only once in a single compilation
#include <lib/SFML/Graphics.hpp>

namespace Renderer {
    void initialise(sf::RenderWindow &);
    sf::RenderWindow &get_window();

    void shutdown();
    void update(const float &);
    void queue(const sf::Drawable *s);
    void render();
};
*/