#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

// the physics engine was implemented by adapting the version created during a lab

// namespace used for all game engine specific classes, structs and variables
namespace Engine
{
    // PHYSICS

    // this class handles the box2d world and provides various helper functions
    class Physics
    {
    public:
        // FUNCTIONS

        // initialise the physics (box2d) world
        static void initialise();
        // close the physics engine
        static void shutdown();
        // step the simulation
        static void update();
        // returns the world's ID
        static b2WorldId getWorldId();
        // get all the contact events at the current time step
        static b2ContactEvents getContactEvents();
        // returns a scaled Vector2f from a b2Vec2
        static sf::Vector2f box2dToSfmlScale(b2Vec2 box2dVec);
        // returns a scaled b2Vec2 from a Vector2f
        static b2Vec2 sfmlToBox2dScale(sf::Vector2f sfmlVec);
        // convert from screenspace.y to physics.y
        static sf::Vector2f invertHeight(sf::Vector2f sfmlVec, int game_height);

        // PARAMETERS

        // 30 pixels = 1 meter
        static constexpr float PHYSICS_SCALE = 30.0f;
        // 1 meter = 30 pixels
        static constexpr float PHYSICS_SCALE_INV = 1.0f / PHYSICS_SCALE;
        // recommended number of sub steps according to the box2d documentation
        static constexpr int SUB_STEP_COUNT = 4;
        // 60FPS update
        static constexpr float TIME_STEP = 0.017f;
        // gravity constant
        static constexpr float GRAVITY = -0.98f;

    private:
        // holds world id once world has been initialised
        static b2WorldId _worldId;
    };
}
