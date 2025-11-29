#include <iostream>

namespace Game
{
    namespace Components
    {
        struct GameState 
        {
            virtual GameState* handleEvent(const sf::Event&) = 0;
            virtual void update(sf::Time) = 0;
            virtual void render() = 0;
            virtual ~GameState() = default; 
        };
    }

}
