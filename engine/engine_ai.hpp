#pragma once
#include "engine_ai.cpp"
#include "engine_em.hpp"
#include "engine_em.cpp"
#include "engine_gs.hpp"
#include "engine_gs.cpp"
#include "engine_phys.hpp"
#include "engine_phys.cpp"
#include "engine_renderer.hpp"
#include "engine_renderer.cpp"
#include <vector>

//steering behaviour output
struct SteeringOutput
{
    // Direction of travel.
    sf::Vector2f direction;
    // Rotation of travel.
    float rotation;
};

// Base class for steering behaviour
class SteeringBehaviour{
public:
    virtual ~SteeringBehaviour() = default;
    
    // Getsoutput from a steering behaviour.
    virtual SteeringOutput getSteering() const noexcept = 0;
};



class Flee : public SteeringBehaviour{
private:
    Entity* _character;
    Entity* _target;
    float _maxSpeed;
    public:
    Flee() = delete;
    Flee(Entity *character, Entity *target, float maxSpeed)
    : _character(character), _target(target), _maxSpeed(maxSpeed) { }
    SteeringOutput getSteering() const noexcept;
};