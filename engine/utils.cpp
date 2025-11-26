#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "utils.hpp"

namespace Engine
{
    int Utils::RNG()
    {
        int x = time(0);
        srand(x);
        return 1;
    }

    sf::Color Utils::hexToSfmlColour(int hex)
    {
        std::cout << "Reached hexToSfmlColour\n\n";
        int red = (hex >> 16) & 0xFF;
        int green = (hex >> 8) & 0xFF;
        int blue = hex & 0xFF;

        return sf::Color(red, green, blue);
    }

    void Utils::createCircle(sf::RenderWindow &window, b2BodyId &bodyId, sf::CircleShape &shape, sf::Vector2f sfmlPosition, float sfmlDiameter, float density, float friction, float restitution, int colour)
    {
        std::cout << "Reached createCirlce\n\n";
        bodyId = setUpBodyId(sfmlPosition, window);
        std::cout << "Set up circle body id\n\n";

        b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
        std::cout << "Set up circle shape def\n\n";

        b2Circle box2dCircle = {{0.f, 0.f}, sfmlDiameter * Engine::Physics::physicsScaleInv / 2};
        std::cout << "Defined box2dCircle\n\n";

        b2CreateCircleShape(bodyId, &shapeDef, &box2dCircle);
        std::cout << "Created circle shape\n";

        shape.setRadius(sfmlDiameter / 2);
        shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
        shape.setOrigin(sfmlDiameter / 2, sfmlDiameter / 2); // center origin
        shape.setPosition(sfmlPosition);
        std::cout << "Set circle shape attributes\n";
    }

    void Utils::createRectangle(sf::RenderWindow &window, b2BodyId &bodyId, sf::RectangleShape &shape, sf::Vector2f sfmlPosition, float sfmlWidth, float sfmlHeight, float density, float friction, float restitution, int colour)
    {
        std::cout << "Reached createRectangle\n";
        bodyId = setUpBodyId(sfmlPosition, window);
        std::cout << "Set up rectangle body id\n";

        b2ShapeDef shapeDef = setUpShapeDef(density, friction, restitution);
        std::cout << "Set up rectangle shape def\n";

        b2Polygon box2dRect = b2MakeBox(sfmlWidth * Engine::Physics::physicsScaleInv / 2, sfmlHeight * Engine::Physics::physicsScaleInv / 2);
        std::cout << "Defined box2dRect\n";

        b2CreatePolygonShape(bodyId, &shapeDef, &box2dRect);
        std::cout << "Created polygon shape\n";

        shape.setSize({sfmlWidth, sfmlHeight});
        shape.setFillColor(Engine::Utils::hexToSfmlColour(colour));
        shape.setOrigin(sfmlWidth / 2, sfmlHeight / 2); // center origin
        shape.setPosition(sfmlPosition);
        std::cout << "Set polygon shape attributes\n";
    }

    b2BodyId Utils::setUpBodyId(sf::Vector2f sfmlPosition, sf::RenderWindow &window)
    {
        std::cout << "Reached setUpBodyId\n";
        b2BodyDef bodyDef = b2DefaultBodyDef();
        bodyDef.type = b2_dynamicBody;
        bodyDef.position = b2Vec2(Engine::Physics::sfmlToBox2dScale(
            Engine::Physics::invertHeight(sfmlPosition, window.getSize().y)));

        return b2CreateBody(Engine::Physics::getWorldId(), &bodyDef);
    }

    b2ShapeDef Utils::setUpShapeDef(float density, float friction, float restitution)
    {
        std::cout << "Reached setUpShapeDef\n";
        b2ShapeDef shapeDef = b2DefaultShapeDef();

        shapeDef.density = density;
        shapeDef.material.friction = friction;       // glidiness
        shapeDef.material.restitution = restitution; // bounciness

        return shapeDef;
    }

}
