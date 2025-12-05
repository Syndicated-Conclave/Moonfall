guide.hpp
namespace Game
{
    namespace Scenes
    {
        class Guide
        {
        public:
            void mainMenu(sf::RenderWindow& window, Engine::EntityManager& ecm);
            void handleEvent(sf::RenderWindow& window, sf::Event& event);

        };

    }
}