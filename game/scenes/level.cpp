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

        float tiltSpeed = .02f;
        float maxTilt = 0.25f;

        float bumpVelocity = 10.f;
        float maxBump = 1.f;

        // vars
        float groundAngle = 0.f; // radians!

        // Initialise physics world
        PhysicsEngine::initialise();
        b2WorldId worldId = PhysicsEngine::getWorldId();
        std::cout << "Box2D: World creation done!\n";

        // window is 800, 400
        // using center origin

        // ground
        float cityscapeSfmlWidth = 2000.f;
        float cityscapeSfmlHeight = 200.f;

        float cityscapeSfmlPosX = window.getSize().x / 2;
        float cityscapeSfmlPosY = window.getSize().y; // partly off screen for bump to not reveal empty space

        sf::Vector2f cityscapeSfmlDimensions = sf::Vector2f(cityscapeSfmlWidth, cityscapeSfmlHeight);
        sf::Vector2f cityscapeSfmlPosition = sf::Vector2f(cityscapeSfmlPosX, cityscapeSfmlPosY);

        // dynamic

        float moonRadius = 100.f;
        float moonSfmlWidth = moonRadius;
        float moonSfmlHeight = moonRadius;

        float moonSfmlPosX = window.getSize().x / 2;
        float moonSfmlPosY = moonSfmlHeight / 2;

        sf::Vector2f moonSfmlDimensions = sf::Vector2f(moonSfmlWidth, moonSfmlHeight);
        sf::Vector2f moonSfmlPosition = sf::Vector2f(moonSfmlPosX, moonSfmlPosY);

        // BOX2D
        // Ground

        b2BodyDef cityscapeBodyDef = b2DefaultBodyDef();
        cityscapeBodyDef.type = b2_dynamicBody;
        cityscapeBodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(cityscapeSfmlPosition, window.getSize().y)));

        b2BodyId cityscapeId = b2CreateBody(worldId, &cityscapeBodyDef);

        b2Polygon cityscapeBox2dRect = b2MakeBox(cityscapeSfmlWidth * PhysicsEngine::physicsScaleInv / 2, cityscapeSfmlHeight * PhysicsEngine::physicsScaleInv / 2);

        b2ShapeDef cityscapeShapeDef = b2DefaultShapeDef();

        cityscapeShapeDef.density = 999999999999.f;
        cityscapeShapeDef.material.friction = 0.4f;    // glidiness
        cityscapeShapeDef.material.restitution = 0.0f; // bounciness
        cityscapeShapeDef.isSensor = false;
        b2Body_SetGravityScale(cityscapeId, 0.0f);

        b2CreatePolygonShape(cityscapeId, &cityscapeShapeDef, &cityscapeBox2dRect);

        std::cout << "Box2D: Ground creation done!\n";

        // Dynamic Box

        b2BodyDef moonBodyDef = b2DefaultBodyDef();
        moonBodyDef.type = b2_dynamicBody;
        moonBodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(moonSfmlPosition, window.getSize().y)));

        b2BodyId moonId = b2CreateBody(worldId, &moonBodyDef);

        b2Circle moonBox2dCircle = {{0.f, 0.f},
                                    moonSfmlWidth * PhysicsEngine::physicsScaleInv / 2};

        b2ShapeDef moonShapeDef = b2DefaultShapeDef();

        moonShapeDef.density = 1.0f;
        moonShapeDef.material.friction = 0.3f;    // glidiness
        moonShapeDef.material.restitution = 0.0f; // bounciness
        moonShapeDef.isSensor = false;

        b2CreateCircleShape(moonId, &moonShapeDef, &moonBox2dCircle);

        std::cout << "Box2D: Dynamic Ball creation done!\n";

        // SFML
        // Ground

        sf::RectangleShape cityscapeSfmlRect(cityscapeSfmlDimensions);
        cityscapeSfmlRect.setFillColor(cityscapeColour);
        cityscapeSfmlRect.setOrigin(cityscapeSfmlWidth / 2, cityscapeSfmlHeight / 2); // center origin
        cityscapeSfmlRect.setPosition(cityscapeSfmlPosition);
        std::cout << "SFML: Ground creation done!\n";

        // Dynamic Box

        sf::CircleShape moonSfmlCircle(moonSfmlWidth / 2);
        moonSfmlCircle.setFillColor(moonColour); // #F6F1D5
        moonSfmlCircle.setOrigin(moonSfmlWidth / 2, moonSfmlHeight / 2);
        moonSfmlCircle.setPosition(moonSfmlPosition);
        std::cout << "SFML: Dynamic Ball creation done!\n";

        // Loop

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
                if (groundAngle < maxTilt)
                {
                    groundAngle += tiltSpeed * PhysicsEngine::timeStep;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (groundAngle > -maxTilt)
                {
                    groundAngle -= tiltSpeed * PhysicsEngine::timeStep;
                }
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && b2Body_GetPosition(cityscapeId).y < PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight((cityscapeSfmlPosition), window.getSize().y)).y + maxBump)
            {
                bumpVelocity = 1.f;
                b2Body_SetLinearVelocity(cityscapeId, {0, bumpVelocity});
            }
            else
            {
                if (b2Body_GetPosition(cityscapeId).y > PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight((cityscapeSfmlPosition), window.getSize().y)).y)
                {
                    b2Body_SetLinearVelocity(cityscapeId, {0, -bumpVelocity});
                }
                else
                {
                    b2Body_SetLinearVelocity(cityscapeId, {0, 0});
                }
            }

            b2Body_SetAngularVelocity(cityscapeId, groundAngle);

            b2Body_SetTransform(cityscapeId, b2Body_GetPosition(cityscapeId), {{cos(groundAngle)}, sin(groundAngle)});

            // ground
            b2Vec2 cityscapePos = b2Body_GetPosition(cityscapeId);
            cityscapeSfmlRect.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(cityscapePos), window.getSize().y));
            cityscapeSfmlRect.setRotation(-b2Rot_GetAngle(b2Body_GetRotation(cityscapeId)) * 180.f / B2_PI);

            // dynamic
            b2Vec2 moonPos = b2Body_GetPosition(moonId);
            b2Rot moonRot = b2Body_GetRotation(moonId);

            moonSfmlCircle.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(moonPos), window.getSize().y));

            moonSfmlCircle.setRotation(b2Rot_GetAngle(moonRot) * 180.f / B2_PI);

            // Draw everything
            window.clear(nightskyColour);
            window.draw(cityscapeSfmlRect);
            window.draw(moonSfmlCircle);
            window.display();
        }

        // Cleanup lab physics world
        PhysicsEngine::shutdown();
    }

} // namespace Level
