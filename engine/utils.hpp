#pragma once
#include <SFML/Graphics.hpp>

// namespace used for all game engine specific classes, structs and variables
namespace Engine
{
    // UTILS

    // this class contains various utility functions
    class Utils
    {
    public:
        // function to convert a colour hex code to an sf::Color using RGB values
        static sf::Color hexToSfmlColour(int hex);
    };
}