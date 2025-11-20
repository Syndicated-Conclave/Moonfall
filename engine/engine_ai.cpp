#include "engine_em.hpp"
#include "engine_em.cpp"
#include <vector>

#pragma region STEERING BEHAVIOURS
SteeringOutput Flee::getSteering() const noexcept{
    SteeringOutput steering;
    steering.direction = _character->getPosition() - _target->getPosition();
    steering.direction = normalize(steering.direction);
    steering.direction *= _maxSpeed;
    steering.rotation = 0.0f;
    return steering;
}

#pragma endregion