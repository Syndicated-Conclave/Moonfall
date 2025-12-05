#include "physics.hpp"

namespace Engine
{
    b2WorldId Physics::_worldId = b2_nullWorldId; // initialise static variable with null value

    void Physics::initialise()
    {
        b2WorldDef worldDef = b2DefaultWorldDef();
        worldDef.gravity = b2Vec2({0.0f, GRAVITY});
        _worldId = b2CreateWorld(&worldDef);
    }

    void Physics::shutdown()
    {
        b2DestroyWorld(_worldId);
    }

    void Physics::update()
    {
        b2World_Step(_worldId, TIME_STEP, SUB_STEP_COUNT);
    }

    b2WorldId Physics::getWorldId()
    {
        return _worldId;
    }

    b2ContactEvents Physics::getContactEvents()
    {
        return b2World_GetContactEvents(_worldId);
    }

    sf::Vector2f Physics::box2dToSfmlScale(b2Vec2 box2dVec)
    {
        return sf::Vector2f(box2dVec.x * PHYSICS_SCALE, (box2dVec.y * PHYSICS_SCALE));
    }
    b2Vec2 Physics::sfmlToBox2dScale(sf::Vector2f sfmlVec)
    {
        return {sfmlVec.x * PHYSICS_SCALE_INV, sfmlVec.y * PHYSICS_SCALE_INV};
    }
    sf::Vector2f Physics::invertHeight(sf::Vector2f sfmlVec, int game_height)
    {
        return sf::Vector2f(sfmlVec.x, game_height - sfmlVec.y);
    }
}
