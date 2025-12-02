#include "physics.hpp"
#include "../entities/cityscape.hpp" // to access the Building struct
#include <iostream>

namespace Game
{
    namespace Components
    {

        // Buildings & Cityscape
        void Physics::createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, std::vector<Game::Entities::Building> city, float density, float friction, float restitution)
        {
            bodyId = setUpBodyId(sfmlPosition, window); // one body id for the whole cityscape entity
            b2Body_SetType(bodyId, b2_kinematicBody);
            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            std::vector<b2Polygon> box2dRects; // one rectangle shape for each building including gaps

            // create first building, where the center origin is set to the position passed into this function
            box2dRects.push_back(b2MakeBox(city[0].width * Engine::Physics::PHYSICS_SCALE_INV / 2, city[0].height * Engine::Physics::PHYSICS_SCALE_INV / 2));
            b2CreatePolygonShape(bodyId, &shapeDef, &box2dRects[0]);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop all other buildings, applying an offset to each to line them up next to each other, from left to right
            for (size_t i = 1; i < city.size(); i++)
            {
                // set offset
                offset.x += city[i].width / 2 + city[i - 1].width / 2; // half of the current building and half of the last to line them up seamlessly

                // create building
                box2dRects.push_back(b2MakeBox(city[i].width * Engine::Physics::PHYSICS_SCALE_INV / 2, city[i].height * Engine::Physics::PHYSICS_SCALE_INV / 2));
                for (int j = 0; j < box2dRects[i].count; j++) // offset is applied to each vertex of the rectangle
                {
                    box2dRects[i].vertices[j] += b2Vec2(Engine::Physics::sfmlToBox2dScale(offset));
                }
                b2CreatePolygonShape(bodyId, &shapeDef, &box2dRects[i]);
            }
        }

        void Physics::updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity)
        {
            b2Vec2 box2dPosition = Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y));

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && b2Body_GetPosition(bodyId).y < box2dPosition.y + maxBump)
            {
                // moves up if space is pressed & height limit has not been reached
                b2Body_SetLinearVelocity(bodyId, {0, bumpVelocity});
            }
            else
            {
                if (b2Body_GetPosition(bodyId).y > box2dPosition.y)
                {
                    b2Body_SetLinearVelocity(bodyId, {0, -bumpVelocity}); // return to original position
                }
                else
                {
                    b2Body_SetLinearVelocity(bodyId, {0, 0}); // stop moving
                }
            }
        }

        // Stars & Stardust
        void Physics::createStar(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution)
        {
            bodyId = setUpBodyId(sfmlPosition, window);
            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::PHYSICS_SCALE_INV / 2};
            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);

            // change from dynamic (default from helper function) to kinematic, since all star movement is manually determined not physics based
            b2Body_SetType(bodyId, b2_kinematicBody);
            // adding contact events since its a collectible
            b2Body_EnableContactEvents(bodyId, true);
        }

        void Physics::updateStardust(sf::RenderWindow &window, std::vector<b2BodyId> bodyIds, sf::Vector2f direction, float speed)
        {
            b2ContactEvents events = Engine::Physics::getContactEvents();

            for (size_t i = 0; i < bodyIds.size(); i++)
            {
                for (int e = 0; e < events.beginCount; e++)
                {
                    // check if event includes star
                    if ((B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdA), bodyIds[i])) ||
                        (B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdB), bodyIds[i])))
                    {
                        if (i == 0) // contact star is the central star, all stars of the stardust entity are collected
                        {
                            for (size_t j = 0; j < bodyIds.size(); j++)
                            {
                                b2Body_Disable(bodyIds[j]);
                                // ++ points
                            }
                        }
                        else // just the contact star is collected
                        {
                            b2Body_Disable(bodyIds[i]);
                            // ++ points
                        }
                    }
                }

                b2Vec2 velocity = b2MulSV(speed, Engine::Physics::sfmlToBox2dScale({direction.x, -direction.y}));

                // boundary values to avoid leaving the window
                sf::Vector2f maxHeight(0, 0);
                sf::Vector2f minHeight(0, window.getSize().y);

                for (size_t i = 0; i < bodyIds.size(); i++)
                {
                    b2Vec2 currentPosition = b2Body_GetPosition(bodyIds[i]);

                    // boundary check
                    if ((currentPosition.y <= Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight(minHeight, window.getSize().y)).y && velocity.y < 0) ||
                        (currentPosition.y >= Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight(maxHeight, window.getSize().y)).y && velocity.y > 0))
                    {
                        velocity.y = 0;
                    }
                }

                // apply movement
                for (size_t i = 0; i < bodyIds.size(); i++)
                {
                    b2Body_SetLinearVelocity(bodyIds[i], velocity);
                }
            }
        }

        // Moon
        void Physics::createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution)
        {
            bodyId = setUpBodyId(sfmlPosition, window);
            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::PHYSICS_SCALE_INV / 2};
            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
        }

        void Physics::updateMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, int cooldown, int &counter)
        {
            if (counter > 0)
            {
                counter--; // counts down til the jump cooldown is over
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (counter == 0) // applying cooldown to avoid spamming the up key and rising higher than intended
                {
                    b2Body_ApplyForceToCenter(bodyId, {0, 2000}, true);
                    counter = cooldown;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                b2Body_ApplyForceToCenter(bodyId, {1000, 0}, true);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {

                b2Body_ApplyForceToCenter(bodyId, {-1000, 0}, true);
            }

            b2Vec2 velocity = b2Body_GetLinearVelocity(bodyId);

            // clamp left & right movement speed
            if (velocity.x > 1.f)
            {
                velocity.x = 1.f;
            }
            else if (velocity.x < -1.f)
            {
                velocity.x = -1.f;
            }

            // makes moon come to a halt horizontally when neither right nor left key are pressed
            if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
            {
                velocity.x *= 0.9f;
            }

            b2Body_SetLinearVelocity(bodyId, velocity);
        }

        // Helper functions
        b2BodyId Physics::setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window)
        {
            b2BodyDef bodyDef = b2DefaultBodyDef();
            bodyDef.type = b2_dynamicBody; // default
            bodyDef.position = b2Vec2(Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight(sfmlPosition, window.getSize().y)));

            return b2CreateBody(Engine::Physics::getWorldId(), &bodyDef);
        }

        b2ShapeDef Physics::setUpShapeDef(float density, float friction, float restitution)
        {
            b2ShapeDef shapeDef = b2DefaultShapeDef();
            shapeDef.density = density;
            shapeDef.material.friction = friction;
            shapeDef.material.restitution = restitution;

            return shapeDef;
        }
    }
}