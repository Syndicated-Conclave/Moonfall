#include "cityscape.hpp"

namespace Game
{
    namespace Entities
    {
        Cityscape::Cityscape(sf::RenderWindow &window)
        {
            float sfmlPosX = window.getSize().x / 2;
            float sfmlPosY = window.getSize().y;

            sfmlPosition = sf::Vector2f(sfmlPosX, sfmlPosY);

            angle = 0.f;

            b2BodyDef bodyDef = b2DefaultBodyDef();
            bodyDef.type = b2_dynamicBody;
            bodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(
                PhysicsEngine::invertHeight(sfmlPosition, window.getSize().y)));

            bodyId = b2CreateBody(PhysicsEngine::getWorldId(), &bodyDef);

            b2Polygon box2dRect = b2MakeBox(Cityscape::SFML_WIDTH * PhysicsEngine::physicsScaleInv / 2, Cityscape::SFML_HEIGHT * PhysicsEngine::physicsScaleInv / 2);

            b2ShapeDef shapeDef = b2DefaultShapeDef();

            shapeDef.density = Cityscape::DENSITY;
            shapeDef.material.friction = Cityscape::FRICTION;       // glidiness
            shapeDef.material.restitution = Cityscape::RESTITUTION; // bounciness
            shapeDef.isSensor = false;
            b2Body_SetGravityScale(bodyId, 0.0f);

            b2CreatePolygonShape(bodyId, &shapeDef, &box2dRect);

            shape.setSize({Cityscape::SFML_WIDTH, Cityscape::SFML_HEIGHT});
            shape.setFillColor(Engine::Utils::hexToSfmlColour(Cityscape::COLOUR));
            shape.setOrigin(Cityscape::SFML_WIDTH / 2, Cityscape::SFML_HEIGHT / 2); // center origin
            shape.setPosition(sfmlPosition);
        }

        void Cityscape::update(sf::RenderWindow &window)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (angle < MAX_TILT)
                {
                    angle += TILT_SPEED * PhysicsEngine::timeStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (angle > -MAX_TILT)
                {
                    angle -= TILT_SPEED * PhysicsEngine::timeStep;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && b2Body_GetPosition(bodyId).y < PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight((sfmlPosition), window.getSize().y)).y + MAX_BUMP)
            {
                b2Body_SetLinearVelocity(bodyId, {0, BUMP_VELOCITY});
            }
            else
            {
                if (b2Body_GetPosition(bodyId).y > PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight((sfmlPosition), window.getSize().y)).y)
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
            Cityscape::shape.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(cityscapePos), window.getSize().y));
            Cityscape::shape.setRotation(-b2Rot_GetAngle(b2Body_GetRotation(Cityscape::bodyId)) * 180.f / B2_PI);
        }

        void Cityscape::render(sf::RenderWindow &window)
        {
            window.draw(Cityscape::shape);
        }
    }

}
