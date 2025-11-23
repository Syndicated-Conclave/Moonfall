#include "level.hpp"
#include <vector>
#include <iostream>

namespace Level
{

    void physics_playground(sf::RenderWindow &window)
    {
        // Initialise physics world
        PhysicsEngine::initialise();
        b2WorldId worldId = PhysicsEngine::getWorldId();
        std::cout << "Box2D: World creation done!\n";

        // window is 800, 400
        // using center origin

        // ground
        float groundSfmlWidth = 800.f;
        float groundSfmlHeight = 50.f;

        float groundSfmlPosX = window.getSize().x / 2;
        float groundSfmlPosY = window.getSize().y - (groundSfmlHeight / 2);

        sf::Vector2f groundSfmlDimensions = sf::Vector2f(groundSfmlWidth, groundSfmlHeight);
        sf::Vector2f groundSfmlPosition = sf::Vector2f(groundSfmlPosX, groundSfmlPosY);

        // dynamic

        float dynamicSfmlWidth = 25.f;
        float dynamicSfmlHeight = 25.f;

        float dynamicSfmlPosX = window.getSize().x / 2;
        float dynamicSfmlPosY = dynamicSfmlHeight / 2;

        sf::Vector2f dynamicSfmlDimensions = sf::Vector2f(dynamicSfmlWidth, dynamicSfmlHeight);
        sf::Vector2f dynamicSfmlPosition = sf::Vector2f(dynamicSfmlPosX, dynamicSfmlPosY);

        // BOX2D
        // Ground

        b2BodyDef groundBodyDef = b2DefaultBodyDef();

        groundBodyDef.type = b2_staticBody;

        groundBodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(groundSfmlPosition, window.getSize().y)));
        b2BodyId groundId = b2CreateBody(worldId, &groundBodyDef);
        b2Polygon groundBox = b2MakeBox(groundSfmlWidth * PhysicsEngine::physicsScaleInv / 2, groundSfmlHeight * PhysicsEngine::physicsScaleInv / 2);
        b2ShapeDef groundShapeDef = b2DefaultShapeDef();

        /*
        groundShapeDef.material.friction = 0.9f;
        groundShapeDef.material.restitution = 0.0f;
        groundShapeDef.isSensor = false;
        */

        b2CreatePolygonShape(groundId, &groundShapeDef, &groundBox);

        std::cout << "Box2D: Ground creation done!\n";

        // Dynamic Box

        b2BodyDef bodyDef = b2DefaultBodyDef();

        bodyDef.type = b2_dynamicBody;

        bodyDef.position = b2Vec2(PhysicsEngine::sfmlToBox2dScale(PhysicsEngine::invertHeight(dynamicSfmlPosition, window.getSize().y)));
        b2BodyId dynamicId = b2CreateBody(worldId, &bodyDef);
        b2Polygon dynamicBox = b2MakeBox(dynamicSfmlWidth * PhysicsEngine::physicsScaleInv / 2, dynamicSfmlHeight * PhysicsEngine::physicsScaleInv / 2);
        b2ShapeDef shapeDef = b2DefaultShapeDef();

        /*
        shapeDef.density = 1.0f;
        shapeDef.material.friction = 0.3f;
        shapeDef.material.restitution = 0.0f;
        shapeDef.isSensor = false;
        */

        b2CreatePolygonShape(dynamicId, &shapeDef, &dynamicBox);

        std::cout << "Box2D: Dynamic Box creation done!\n";

        // SFML
        // Ground

        sf::RectangleShape groundRect(groundSfmlDimensions);
        groundRect.setFillColor(sf::Color::Green);
        groundRect.setOrigin(groundSfmlWidth / 2, groundSfmlHeight / 2); // center origin
        groundRect.setPosition(groundSfmlPosition);
        std::cout << "SFML: Ground creation done!\n";

        // Dynamic Box

        sf::RectangleShape dynamicRect(dynamicSfmlDimensions);
        dynamicRect.setFillColor(sf::Color::Red);
        dynamicRect.setOrigin(dynamicSfmlWidth / 2, dynamicSfmlHeight / 2);
        dynamicRect.setPosition(dynamicSfmlPosition);
        std::cout << "SFML: Dynamic Box creation done!\n";

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

            // ground
            b2Vec2 groundPos = b2Body_GetPosition(groundId);
            groundRect.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(groundPos), window.getSize().y));

            // dynamic
            b2Vec2 dynamicPos = b2Body_GetPosition(dynamicId);
            b2Rot dynamicRot = b2Body_GetRotation(dynamicId);

            dynamicRect.setPosition(PhysicsEngine::invertHeight(PhysicsEngine::box2dToSfmlScale(dynamicPos), window.getSize().y));

            dynamicRect.setRotation(b2Rot_GetAngle(dynamicRot) * 180.f / B2_PI);

            // Draw everything
            window.clear(sf::Color::Black);
            window.draw(groundRect);
            window.draw(dynamicRect);
            window.display();
        }

        // Cleanup lab physics world
        PhysicsEngine::shutdown();
    }

} // namespace Level
