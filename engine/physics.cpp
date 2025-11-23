#include "physics.hpp"

b2WorldId PhysicsEngine::_worldId;

void PhysicsEngine::initialise()
{
    b2WorldDef worldDef = b2DefaultWorldDef();
    worldDef.gravity = b2Vec2({0.0f, gravity});
    _worldId = b2CreateWorld(&worldDef);
}

void PhysicsEngine::shutdown()
{
    b2DestroyWorld(_worldId);
}

void PhysicsEngine::update(const float &time_step)
{
    b2World_Step(_worldId, time_step, subStepCount);
}

b2WorldId PhysicsEngine::getWorldId()
{
    return _worldId;
}

// COMPARED WITH DOCUMENTATION UP TO HERE

b2ContactEvents PhysicsEngine::getContactEvents()
{
    return b2World_GetContactEvents(_worldId);
}

// Convert from b2Vec2 to a Vector2f
const sf::Vector2f PhysicsEngine::box2dToSfmlScale(const b2Vec2 &in)
{
    return sf::Vector2f(in.x * physicsScale, (in.y * physicsScale));
}
// Convert from Vector2f to a b2Vec2
const b2Vec2 PhysicsEngine::sfmlToBox2dScale(const sf::Vector2f &in)
{
    return {in.x * physicsScaleInv, in.y * physicsScaleInv};
}
// Convert from screenspace.y to physics.y (as they are the other way around)
const sf::Vector2f PhysicsEngine::invertHeight(const sf::Vector2f &in, const int &game_height)
{
    return sf::Vector2f(in.x, game_height - in.y);
}
