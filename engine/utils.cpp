#include "utils.hpp"

namespace Engine
{
    sf::Color Utils::hexToSfmlColour(int hex)
    {
        int red = (hex >> 16) & 0xFF;  // shifts and cuts hex to extract red
        int green = (hex >> 8) & 0xFF; // shifts and cuts hex to extract green
        int blue = hex & 0xFF;         // cuts hex to extract blue

        return sf::Color(red, green, blue);
    }
}
