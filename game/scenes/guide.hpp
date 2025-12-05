#include <SFML/Graphics.hpp>
#include "../../engine/ecm.hpp"
namespace Game
{
    namespace Scenes
    {
        class Guide
        {
        public:
            void instruct(sf::RenderWindow& window, Engine::EntityManager& ecm);
            //void Menu(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);
            sf::RectangleShape back;
            
        };

        
        

    }
}