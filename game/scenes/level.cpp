#include "level.hpp"
#include <vector>
#include <iostream>

namespace Level
{

    void physics_playground(sf::RenderWindow &window)
    {
        // consts
        sf::Color moonColour(246, 241, 213);
        sf::Color cityscapeColour(40, 40, 40);
        sf::Color nightskyColour(24, 50, 100);

        //

        float tiltSpeed = .02f;
        float groundAngle = 0.f; // radians!

        // Initialise physics world
        PhysicsEngine::initialise();
        b2WorldId worldId = PhysicsEngine::getWorldId();
        std::cout << "Box2D: World creation done!\n";

        // window is 800, 400
        // using center origin

        // ground
        float groundSfmlWidth = 2000.f;
        float groundSfmlHeight = 200.f;

        float groundSfmlPosX = window.getSize().x / 2;
        float groundSfmlPosY = window.getSize().y; // partly off screen for bump to not reveal empty space

        sf::Vector2f groundSfmlDimensions = sf::Vector2f(groundSfmlWidth, groundSfmlHeight);
        sf::Vector2f groundSfmlPosition = sf::Vector2f(groundSfmlPosX, groundSfmlPosY);

        // dynamic

        float moonRadius = 100.f;
        float dynamicSfmlWidth = moonRadius;
        float dynamicSfmlHeight = moonRadius;

        float dynamicSfmlPosX = window.getSize().x / 2;
        float dynamicSfmlPosY = dynamicSfmlHeight / 2;

        sf::Vector2f dynamicSfmlDimensions = sf::Vector2f(dynamicSfmlWidth, dynamicSfmlHeight);
        sf::Vector2f dynamicSfmlPosition = sf::Vector2f(dynamicSfmlPosX, dynamicSfmlPosY);

        // BOX2D
        // Ground

        b2BodyDef groundBodyDef = b2DefaultBodyDef();
        groundBodyDef.type = b2_dynamicBody;
        groundBodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(groundSfmlPosition, window.getSize().y)));

        b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);

        b2Polygon groundBox = b2MakeBox(groundSfmlWidth * PhysicsEngine::physicsScaleInv / 2, groundSfmlHeight * PhysicsEngine::physicsScaleInv / 2);

        b2ShapeDef groundShapeDef = b2DefaultShapeDef();

        groundShapeDef.density = 999999999999.f;
        groundShapeDef.material.friction = 0.4f;    // glidiness
        groundShapeDef.material.restitution = 0.0f; // bounciness
        groundShapeDef.isSensor = false;
        b2Body_SetGravityScale(groundId, 0.0f);

        b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

        std::cout << "Box2D: Ground creation done!\n";

        // Dynamic Box

        b2BodyDef bodyDef = b2DefaultBodyDef();
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(dynamicSfmlPosition, window.getSize().y)));

        b2BodyId dynamicId = b2CreateBody(worldId, &bodyDef);

        b2Circle dynamicBall = {{0.f, 0.f},
                                dynamicSfmlWidth * PhysicsEngine::physicsScaleInv / 2};

        b2ShapeDef circleShapeDef = b2DefaultShapeDef();

        circleShapeDef.density = 1.0f;
        circleShapeDef.material.friction = 0.3f;    // glidiness
        circleShapeDef.material.restitution = 0.0f; // bounciness
        circleShapeDef.isSensor = false;

        b2CreateCircleShape(dynamicId, &circleShapeDef, &dynamicBall);

        std::cout << "Box2D: Dynamic Ball creation done!\n";

        // SFML
        // Ground

        sf::RectangleShape groundRect(groundSfmlDimensions);
        groundRect.setFillColor(cityscapeColour);
        groundRect.setOrigin(groundSfmlWidth / 2, groundSfmlHeight / 2); // center origin
        groundRect.setPosition(groundSfmlPosition);
        std::cout << "SFML: Ground creation done!\n";

        // Dynamic Box

        sf::CircleShape dynamicCircle(dynamicSfmlWidth / 2);
        dynamicCircle.setFillColor(moonColour); // #F6F1D5
        dynamicCircle.setOrigin(dynamicSfmlWidth / 2, dynamicSfmlHeight / 2);
        dynamicCircle.setPosition(dynamicSfmlPosition);
        std::cout << "SFML: Dynamic Ball creation done!\n";

        // Loop

        sf::Clock clock;
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            // Step the physics world
            PhysicsEngine::update(PhysicsEngine::timeStep);

            // Update SFML shape positions

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                groundAngle += tiltSpeed * PhysicsEngine::timeStep;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                groundAngle -= tiltSpeed * PhysicsEngine::timeStep;
            }

            float bumpVelocity = 10.f;

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                bumpVelocity = 1.f;
                b2Body_SetLinearVelocity(groundId, {0, bumpVelocity});
            }
            else
            {
                if (b2Body_GetPosition(groundId).y > PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight((groundSfmlPosition), window.getSize().y)).y)
                {
                    b2Body_SetLinearVelocity(groundId, {0, -bumpVelocity});
                }
                else
                {
                    b2Body_SetLinearVelocity(groundId, {0, 0});
                }
            }

            b2Body_SetAngularVelocity(groundId, groundAngle);

            b2Body_SetTransform(groundId, b2Body_GetPosition(groundId), {{cos(groundAngle)}, sin(groundAngle)});

            // ground
            b2Vec2 groundPos = b2Body_GetPosition(groundId);
            groundRect.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(groundPos), window.getSize().y));
            groundRect.setRotation(-b2Rot_GetAngle(b2Body_GetRotation(groundId)) * 180.f / B2_PI);

            // dynamic
            b2Vec2 dynamicPos = b2Body_GetPosition(dynamicId);
            b2Rot dynamicRot = b2Body_GetRotation(dynamicId);

            dynamicCircle.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(dynamicPos), window.getSize().y));

            dynamicCircle.setRotation(b2Rot_GetAngle(dynamicRot) * 180.f / B2_PI);

            // Draw everything
            window.clear(nightskyColour);
            window.draw(groundRect);
            window.draw(dynamicCircle);
            window.display();
        }

        // Cleanup lab physics world
        PhysicsEngine::shutdown();
    }

} // namespace Level
