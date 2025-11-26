#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

namespace Engine
{
    class Physics
    {
    public:
        static void initialise();          // initialise the box2d world
        static void shutdown();            // close the physics engine
        static void update(const float &); // step the simulation

        static b2WorldId getWorldId();

        // COMPARED WITH DOCUMENTATION UP TO HERE

        static b2ContactEvents getContactEvents(); // get all the contact events at the current time step

        // Convert from b2Vec2 to a Vector2f (box2d -> sfml)
        static const sf::Vector2f box2dToSfmlScale(const b2Vec2 &in);
        // Convert from Vector2f to a b2Vec2 (sfml -> box2d)
        static const b2Vec2 sfmlToBox2dScale(const sf::Vector2f &in);

        // Convert from screenspace.y to physics.y (as they are the other way around)
        static const sf::Vector2f invertHeight(const sf::Vector2f &in, const int &game_height);

        // General parameters related to the physic engine
        static constexpr float physicsScale = 30.0f; // 30 pixels = 1 meter
        static constexpr float physicsScaleInv = 1.0f / physicsScale;
        static constexpr int subStepCount = 4;    // specific box2d parameter (see box2d API)
        static constexpr float timeStep = 0.017f; // 60FPS update
        static constexpr float gravity = -0.3f;   // gravity constant DIFFERENT ON THIS FICTIONAL PLANET
    private:
        static b2WorldId _worldId;
    };
}
