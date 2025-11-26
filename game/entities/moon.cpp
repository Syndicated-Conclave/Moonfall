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

            b2BodyDef bodyDef = b2DefaultBodyDef();
            bodyDef.type = b2_dynamicBody;
            bodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(
                PhysicsEngine::invertHeight(sfmlPosition, window.getSize().y)));

            bodyId = b2CreateBody(PhysicsEngine::getWorldId(), &bodyDef);

            b2Circle box2dCircle = {{0.f, 0.f}, Moon::SFML_DIAMETER * PhysicsEngine::physicsScaleInv / 2};
            b2ShapeDef shapeDef = b2DefaultShapeDef();

            shapeDef.density = Moon::DENSITY;
            shapeDef.material.friction = Moon::FRICTION;       // glidiness
            shapeDef.material.restitution = Moon::RESTITUTION; // bounciness
            shapeDef.isSensor = false;

            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);

            shape.setRadius(Moon::SFML_DIAMETER / 2);
            shape.setFillColor(Engine::Utils::hexToSfmlColour(Moon::COLOUR));
            shape.setOrigin(Moon::SFML_DIAMETER / 2, Moon::SFML_DIAMETER / 2); // center origin
            shape.setPosition(sfmlPosition);
        }

        void Moon::update(sf::RenderWindow &window)
        {
            Moon::shape.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(b2Body_GetPosition(Moon::bodyId)), window.getSize().y));
            Moon::shape.setRotation(b2Rot_GetAngle(b2Body_GetRotation(Moon::bodyId)) * 180.f / B2_PI);
        }

        void Moon::render(sf::RenderWindow &window)
        {
            window.draw(Moon::shape);
        }
    }

}
