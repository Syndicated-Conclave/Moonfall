#include "physics.hpp"
#include "../entities/cityscape.hpp"
#include <iostream>

namespace Game
{
    namespace Components
    {

        // Buildings & Cityscape
        void Physics::createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, std::vector<Game::Entities::Building> city, float density, float friction, float restitution)
        {
            // std::cout << "Reached createRectangle\n";
            bodyId = setUpBodyId(sfmlPosition, window);
            b2Body_SetType(bodyId, b2_kinematicBody);

            // std::cout << "Set up rectangle body id\n";

            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            // std::cout << "Set up rectangle shape def\n";

            std::vector<b2Polygon> box2dRects;

            // create first building
            box2dRects.push_back(b2MakeBox(city[0].width * Engine::Physics::PHYSICS_SCALE_INV / 2, city[0].height * Engine::Physics::PHYSICS_SCALE_INV / 2));
            b2CreatePolygonShape(bodyId, &shapeDef, &box2dRects[0]);

            // init offset
            sf::Vector2f offset = {0, 0};

            // loop for second++ buildings and offset
            for (size_t i = 1; i < city.size(); i++)
            {
                // set offset
                offset.x += city[i].width / 2 + city[i - 1].width / 2;

                // create building
                box2dRects.push_back(b2MakeBox(city[i].width * Engine::Physics::PHYSICS_SCALE_INV / 2, city[i].height * Engine::Physics::PHYSICS_SCALE_INV / 2));
                for (int j = 0; j < box2dRects[i].count; j++)
                {
                    box2dRects[i].vertices[j] += b2Vec2(Engine::Physics::sfmlToBox2dScale(offset));
                }
                b2CreatePolygonShape(bodyId, &shapeDef, &box2dRects[i]);
            }

            // std::cout << "Defined box2dRect\n";

            // b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created polygon shape\n";

            // std::cout << "Setting cityscape gravity scale...\n";
            // std::cout << "Set cityscape gravity scale.\n";
        }

        void Physics::updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && b2Body_GetPosition(bodyId).y < Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y)).y + maxBump)
            {
                b2Body_SetLinearVelocity(bodyId, {0, bumpVelocity});
            }
            else
            {
                if (b2Body_GetPosition(bodyId).y > Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y)).y)
                {
                    b2Body_SetLinearVelocity(bodyId, {0, -bumpVelocity});
                }
                else
                {
                    b2Body_SetLinearVelocity(bodyId, {0, 0});
                }
            }
        }

        // Stars & Stardust
        void Physics::createStar(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution)
        {
            // std::cout << "Reached createCirlce\n\n";
            bodyId = setUpBodyId(sfmlPosition, window);
            b2Body_SetType(bodyId, b2_kinematicBody);

            // std::cout << "Set up circle body id\n\n";

            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            shapeDef.isSensor = false;
            //    std::cout << "Set up circle shape def\n\n";

            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::PHYSICS_SCALE_INV / 2};
            // std::cout << "Defined box2dCircle\n\n";

            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
            b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created circle shape\n";
        }

        void Physics::updateStardust(sf::RenderWindow &window, std::vector<b2BodyId> bodyIds, sf::Vector2f direction, float speed)
        {
            // std::cout << "....\n";

            b2ContactEvents events = Engine::Physics::getContactEvents();

            for (size_t i = 0; i < bodyIds.size(); i++)
            {
                for (int e = 0; e < events.beginCount; e++)
                {
                    if ((B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdA), bodyIds[i])) || (B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdB), bodyIds[i])))
                    {
                        // std::cout << "YAAAY\n";
                        if (i == 0)
                        {
                            for (size_t j = 0; j < bodyIds.size(); j++)
                            {
                                b2Body_Disable(bodyIds[j]);
                            }

                            // ++ points
                        }
                        else
                        {
                            b2Body_Disable(bodyIds[i]);
                        }
                    }
                }

                b2Vec2 velocity = b2MulSV(speed, Engine::Physics::sfmlToBox2dScale({direction.x, -direction.y}));
                sf::Vector2f maxHeight(0, 0);
                sf::Vector2f minHeight(0, window.getSize().y);

                for (size_t i = 0; i < bodyIds.size(); i++)
                {
                    b2Vec2 currentPosition = b2Body_GetPosition(bodyIds[i]);

                    if ((currentPosition.y <= Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight(minHeight, window.getSize().y)).y && velocity.y < 0) || (currentPosition.y >= Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight(maxHeight, window.getSize().y)).y && velocity.y > 0))
                    {
                        velocity.y = 0;
                    }
                }
                for (size_t i = 0; i < bodyIds.size(); i++)
                {
                    b2Body_SetLinearVelocity(bodyIds[i], velocity);
                }
            }
        }

        // Moon
        void Physics::createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution)
        {
            // std::cout << "Reached createCirlce\n\n";
            bodyId = setUpBodyId(sfmlPosition, window);

            // std::cout << "Set up circle body id\n\n";

            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);

            // std::cout << "Set up circle shape def\n\n";

            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::PHYSICS_SCALE_INV / 2};
            // std::cout << "Defined box2dCircle\n\n";

            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
            b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created circle shape\n";
        }

        void Physics::updateMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, int cooldown, int &counter)
        {
            if (counter > 0)
            {
                counter--;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (counter == 0)
                {
                    b2Body_ApplyForceToCenter(bodyId, {0, 2000}, true);
                    counter = cooldown;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                b2Body_ApplyForceToCenter(bodyId, {1000, 0}, true);

                // b2Body_SetLinearVelocity(bodyId, {5, 0});
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                // b2Body_SetLinearVelocity(bodyId, {-5, 0});

                b2Body_ApplyForceToCenter(bodyId, {-1000, 0}, true);
            }
            b2Vec2 velocity = b2Body_GetLinearVelocity(bodyId);

            if (velocity.x > 1.f)
            {
                velocity.x = 1.f;
            }
            else if (velocity.x < -1.f)
            {
                velocity.x = -1.f;
            }

            if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) && !(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
            {
                velocity.x *= 0.9f;
            }

            b2Body_SetLinearVelocity(bodyId, velocity);

            /*
           if (event.type == sf::Event::KeyPressed)
           { // CHANGE BACK TO KEYBOARD CHECK

               if (event.key.code == sf::Keyboard::Up)
               {

                   b2Body_ApplyForce(bodyId, {0, 1000}, box2dPosition, true);
               }
               else
            if (event.key.code == sf::Keyboard::Right)
            {
                // b2Body_SetLinearVelocity(bodyId, {5, 0});

                b2Body_ApplyForce(bodyId, {1000, 0}, box2dPosition, true);
                // b2Body_ApplyTorque(bodyId, -30.f, true);
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                // b2Body_SetLinearVelocity(bodyId, {-5, 0});

                b2Body_ApplyForce(bodyId, {-1000, 0}, box2dPosition, true);
                // b2Body_ApplyTorque(bodyId, 30.f, true);
            }
        }
        else if (event.type == sf::Event::KeyReleased)
        {
            if (event.key.code == sf::Keyboard::Right)
            {
                // b2Body_SetLinearVelocity(bodyId, {0, 0});

                // b2Body_ApplyForce(bodyId, {500, 0}, box2dPosition, true);
            }
            else if (event.key.code == sf::Keyboard::Left)
            {
                // b2Body_SetLinearVelocity(bodyId, {0, 0});

                // b2Body_ApplyForce(bodyId, {-500, 0}, box2dPosition, true);
            }
        }
        */
        }

        // Helper functions
        b2BodyId Physics::setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window)
        {
            // std::cout << "Reached setUpBodyId\n";
            b2BodyDef bodyDef = b2DefaultBodyDef();
            bodyDef.type = b2_dynamicBody;
            bodyDef.position = b2Vec2(Engine::Physics::sfmlToBox2dScale(
                Engine::Physics::invertHeight(sfmlPosition, window.getSize().y)));

            return b2CreateBody(Engine::Physics::getWorldId(), &bodyDef);
        }

        b2ShapeDef Physics::setUpShapeDef(float density, float friction, float restitution)
        {
            // std::cout << "Reached setUpShapeDef\n";
            b2ShapeDef shapeDef = b2DefaultShapeDef();

            shapeDef.density = density;
            shapeDef.material.friction = friction;       // glidiness
            shapeDef.material.restitution = restitution; // bounciness

            return shapeDef;
        }
    }
}