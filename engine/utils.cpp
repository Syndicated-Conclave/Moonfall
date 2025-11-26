#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utils.hpp>

namespace Engine
{
    int Utils::RNG()
    {
        int x = time(0);
        srand(x);
        return 1;
    }

    sf::Color Utils::hexToSfmlColour(int hex)
    {
        int red = (hex >> 16) & 0xFF;
        int green = (hex >> 8) & 0xFF;
        int blue = hex & 0xFF;

        return sf::Color(red, green, blue);
    }

}
