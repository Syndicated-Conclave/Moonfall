/*

FROM THE LABS:


#include "engine_ai_comp.hpp"
#include <vector>

using namespace sf;

void SteeringComponent::update(double dt)
{

  if (length(_parent->getPosition() - _player->getPosition()) <
      50.0f)
  {
    auto output = _flee.getSteering();
    move(output.direction * (float)dt);
  }
}

SteeringComponent::SteeringComponent(Entity *p, Entity *player)
    : _player(player),
      _flee(Flee(p, player, 100.0f)), Component(p) {}

bool SteeringComponent::validMove(const sf::Vector2f &pos) const
{
  if (pos.x < 0.0f || pos.x > Engine::GetWindow().getSize().x ||
      pos.y < 0.0f || pos.y > Engine::GetWindow().getSize().y)
  {
    return false;
  }
  return true;
}

void SteeringComponent::move(const sf::Vector2f &p)
{
  auto new_pos = _parent->getPosition() + p;
  if (validMove(new_pos))
  {
    _parent->setPosition(new_pos);
  }
}

void SteeringComponent::move(float x, float y) { move(Vector2f(x, y)); }

#pragma region STEERING BEHAVIOURS
SteeringOutput Flee::getSteering() const noexcept
{
  SteeringOutput steering;
  steering.direction = _character->getPosition() - _target->getPosition();
  steering.direction = normalize(steering.direction);
  steering.direction *= _maxSpeed;
  steering.rotation = 0.0f;
  return steering;
}

#pragma endregion
*/