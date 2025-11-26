#include "cityscape.hpp"
#include <iostream>

namespace Game
{
    namespace Entities
    {
        Cityscape::Cityscape(sf::RenderWindow &window)
        {
            float sfmlPosX = window.getSize().x / 2;
            float sfmlPosY = window.getSize().y;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            Engine::Utils::createRectangle(window, bodyId, shape, sfmlPosition, Cityscape::SFML_WIDTH, Cityscape::SFML_HEIGHT, Cityscape::DENSITY, Cityscape::FRICTION, Cityscape::RESTITUTION, Cityscape::COLOUR);
            std::cout << "Created cityscape rectangle\n";
            angle = 0.f;
            std::cout << "Setting cityscape gravity scale...\n";
            b2Body_SetGravityScale(bodyId, 0.0f);
            std::cout << "Set cityscape gravity scale.\n";
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (angle < MAX_TILT)
                {
                    angle += TILT_SPEED * Engine::Physics::timeStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (angle > -MAX_TILT)
                {
                    angle -= TILT_SPEED * Engine::Physics::timeStep;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && b2Body_GetPosition(bodyId).y < Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y)).y + MAX_BUMP)
            {
                b2Body_SetLinearVelocity(bodyId, {0, BUMP_VELOCITY});
            }
            else
            {
                if (b2Body_GetPosition(bodyId).y > Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y)).y)
                {
                    b2Body_SetLinearVelocity(bodyId, {0, -BUMP_VELOCITY});
                }
                else
                {
                    b2Body_SetLinearVelocity(bodyId, {0, 0});
                }
            }

            b2Body_SetAngularVelocity(bodyId, angle);

            b2Body_SetTransform(bodyId, b2Body_GetPosition(bodyId), {{cos(angle)}, sin(angle)});

            b2Vec2 cityscapePos = b2Body_GetPosition(Cityscape::bodyId);
            Cityscape::shape.setPosition(Engine::Physics::invertHeight(Engine::Physics::box2dToSfmlScale(cityscapePos), window.getSize().y));
            Cityscape::shape.setRotation(-b2Rot_GetAngle(b2Body_GetRotation(Cityscape::bodyId)) * 180.f / B2_PI);
        }

        void Cityscape::render(sf::RenderWindow &window)
        {
            window.draw(Cityscape::shape);
        }
    }

}
