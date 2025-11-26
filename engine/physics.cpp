#include "physics.hpp"

namespace Engine
{
    b2WorldId Physics::_worldId = b2_nullWorldId;

    void Physics::initialise()
    {
        b2WorldDef worldDef = b2DefaultWorldDef();
        worldDef.gravity = b2Vec2({0.0f, gravity});
        _worldId = b2CreateWorld(&worldDef);
    }

    void Physics::shutdown()
    {
        b2DestroyWorld(_worldId);
    }

    void Physics::update(const float &time_step)
    {
        b2World_Step(_worldId, time_step, subStepCount);
    }

    b2WorldId Physics::getWorldId()
    {
        return _worldId;
    }

    // COMPARED WITH DOCUMENTATION UP TO HERE

    b2ContactEvents Physics::getContactEvents()
    {
        return b2World_GetContactEvents(_worldId);
    }

    // Convert from b2Vec2 to a Vector2f
    const sf::Vector2f Physics::box2dToSfmlScale(const b2Vec2 &in)
    {
        return sf::Vector2f(in.x * physicsScale, (in.y * physicsScale));
    }
    // Convert from Vector2f to a b2Vec2
    const b2Vec2 Physics::sfmlToBox2dScale(const sf::Vector2f &in)
    {
        return {in.x * physicsScaleInv, in.y * physicsScaleInv};
    }
    // Convert from screenspace.y to physics.y (as they are the other way around)
    const sf::Vector2f Physics::invertHeight(const sf::Vector2f &in, const int &game_height)
    {
        return sf::Vector2f(in.x, game_height - in.y);
    }

}
