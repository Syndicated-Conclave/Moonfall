#pragma once
#include <SFML/Graphics.hpp>
#include "physics.hpp"

namespace Engine
{
    class Utils
    {
    public:
        static int RNG();
        static sf::Color hexToSfmlColour(int hex);
    };
}