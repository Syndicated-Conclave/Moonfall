#include "physics.hpp"
#include <iostream>

namespace Game
{
    namespace Components
    {

        // Buildings & Cityscape
        void Physics::createCityscape(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, float density, float friction, float restitution)
        {
            // std::cout << "Reached createRectangle\n";
            bodyId = setUpBodyId(sfmlPosition, window);
            b2Body_SetType(bodyId, b2_kinematicBody);

            // std::cout << "Set up rectangle body id\n";

            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            // std::cout << "Set up rectangle shape def\n";

            b2Polygon box2dRect = b2MakeBox(sfmlWidth * Engine::Physics::physicsScaleInv / 2, sfmlHeight * Engine::Physics::physicsScaleInv / 2);
            // std::cout << "Defined box2dRect\n";

            b2CreatePolygonShape(bodyId, &shapeDef, &box2dRect);
            // b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created polygon shape\n";

            // std::cout << "Setting cityscape gravity scale...\n";
            // std::cout << "Set cityscape gravity scale.\n";
        }

        void Physics::updateCityscape(sf::RenderWindow &window, b2BodyId &bodyId, float &angle, float maxTilt, float tiltSpeed, sf::Vector2f sfmlPosition, float maxBump, float bumpVelocity)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (angle < maxTilt)
                {
                    angle += tiltSpeed * Engine::Physics::timeStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (angle > -maxTilt)
                {
                    angle -= tiltSpeed * Engine::Physics::timeStep;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && b2Body_GetPosition(bodyId).y < Engine::Physics::sfmlToBox2dScale(Engine::Physics::invertHeight((sfmlPosition), window.getSize().y)).y + maxBump)
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

            b2Body_SetAngularVelocity(bodyId, angle);

            b2Body_SetTransform(bodyId, b2Body_GetPosition(bodyId), {{cos(angle)}, sin(angle)});
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

            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::physicsScaleInv / 2};
            // std::cout << "Defined box2dCircle\n\n";

            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
            b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created circle shape\n";
        }

        void Physics::updateStardust(sf::RenderWindow &window, std::vector<b2BodyId> bodyIds, sf::Vector2f direction, float speed)
        {
            // std::cout << "....\n";

            b2ContactEvents events = b2World_GetContactEvents(Engine::Physics::getWorldId());
            if (events.beginCount != 0)
            {
                // std::cout << "beginCount = " << events.beginCount << "\n";
            }

            for (size_t i = 0; i < bodyIds.size(); i++)
            {
                for (int e = 0; e < events.beginCount; e++)
                {
                    if ((B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdA), bodyIds[i])) || (B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents[e].shapeIdB), bodyIds[i])))
                    {
                        // std::cout << "YAAAY\n";
                        b2Body_Disable(bodyIds[i]);
                        // ++ points
                    }

                    /*
                    auto bodyA = b2Shape_GetBody(events.beginEvents[e].shapeIdA);
                    auto bodyB = b2Shape_GetBody(events.beginEvents[e].shapeIdB);

                    std::cout
                        << "Comparing bodyIds[" << i << "]:\n Star:\t index=" << bodyIds[i].index1 << " gen=" << bodyIds[i].generation << " world=" << bodyIds[i].world0 << "\n";

                    std::cout
                        << "Event A:\t index=" << bodyA.index1 << " gen=" << bodyA.generation << " world=" << bodyA.world0 << "\n";

                    std::cout
                        << "Event B:\t index=" << bodyB.index1 << " gen=" << bodyB.generation << " world=" << bodyB.world0 << "\n\n";
                    */
                }
            }

            /*
            b2SensorEvents events = b2World_GetSensorEvents(Engine::Physics::getWorldId());
            std::cout << "beginCount = " << events.beginCount << "\n";

            for (size_t i = 0; i < bodyIds.size(); i++)
            {
                for (int e = 0; e < events.beginCount; e++)
                {
                    if (B2_ID_EQUALS(b2Shape_GetBody(events.beginEvents->sensorShapeId), bodyIds[i]))
                    {
                        b2Body_Disable(bodyIds[i]);
                        // ++ points
                    }
                }
            }


           for (size_t i = 0; i < bodyIds.size(); i++)
           {
               b2ContactData contactData;

               int numOfElements = b2Body_GetContactData(bodyIds[i], &contactData, 1);
               // std::cout << "Yay\n" << numOfElements << "\n";
               if (numOfElements == 0)
               {
                   b2Body_Disable(bodyIds[i]);
               }
               // ++  points
           }
           */
            b2Vec2 velocity = b2MulSV(speed, Engine::Physics::sfmlToBox2dScale(direction));
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

        // Moon
        void Physics::createMoon(sf::RenderWindow &window, b2BodyId &bodyId, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution)
        {
            // std::cout << "Reached createCirlce\n\n";
            bodyId = setUpBodyId(sfmlPosition, window);

            // std::cout << "Set up circle body id\n\n";

            b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
            // std::cout << "Set up circle shape def\n\n";

            b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::physicsScaleInv / 2};
            // std::cout << "Defined box2dCircle\n\n";

            b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
            b2Body_EnableContactEvents(bodyId, true);

            // std::cout << "Created circle shape\n";
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