#include "moon.hpp"

namespace Game
{
    namespace Entities
    {
        Moon::Moon(sf::RenderWindow &window)
        {
            float sfmlPosX = window.getSize().x / 2;
            float sfmlPosY = Moon::SFML_DIAMETER / 2;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            Engine::Utils::createCircle(window, bodyId, shape, sfmlPosition, Moon::SFML_DIAMETER, Moon::DENSITY, Moon::FRICTION, Moon::RESTITUTION, Moon::COLOUR);
        }

        void Moon::update(sf::RenderWindow &window)
        {
            Moon::shape.setPosition(Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(b2Body_GetPosition(Moon::bodyId)), window.getSize().y));
            Moon::shape.setRotation(b2Rot_GetAngle(b2Body_GetRotation(Moon::bodyId)) * 180.f / B2_PI);
        }

        void Moon::render(sf::RenderWindow &window)
        {
            window.draw(Moon::shape);
        }
    }

}
