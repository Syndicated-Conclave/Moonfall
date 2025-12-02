
#include "ai.hpp"
#include "../../engine/utils.hpp"
#include <iostream>

namespace Game
{
  namespace Components
  {
    sf::Vector2f AI::getDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition, int type)
    {
      sf::Vector2f newDirection;
      switch (type)
      {
      case 1:
        newDirection = {0, 0};
        break;
      case 2:
        newDirection = getLyraDirection(previousDirection, spawnPosition, currentPosition);
        break;
      case 3:
        newDirection = getLeoDirection(spawnPosition, currentPosition, moonPosition);
        break;
      default:
        newDirection = {0, 0};
      }
      return newDirection;
    }

    sf::Vector2f AI::getLyraDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition)
    {
      sf::Vector2f newDirection;

      sf::Vector2f relationalPosition = currentPosition - spawnPosition;
      float rectSize = 100;

      std::vector<sf::Vector2f> points = {{0, 0}, {rectSize, 0}, {rectSize, rectSize}, {0, rectSize}};

      std::vector<sf::Vector2f> directions = {{rectSize, 0}, {0, rectSize}, {-rectSize, 0}, {0, -rectSize}};

      for (size_t i = 0; i < points.size(); i++)
      {
        if (goalReached(relationalPosition, points[i]))
        {
          return normaliseDirection(directions[i]);
        }
      }
      return previousDirection;
    }

    sf::Vector2f AI::getLeoDirection(sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition)
    {
      sf::Vector2f distanceVector = currentPosition - moonPosition;

      float distance = std::sqrt(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

      if (distance < FLEE_DISTANCE)
      {
        return normaliseDirection(distanceVector) * FLEE_SPEED;
      }
      else if (!goalReached(currentPosition, spawnPosition))
      {
        // std::cout << "\ncurrent: " << currentPosition.x << ", " << currentPosition.y;
        // std::cout << "\spawn: " << spawnPosition.x << ", " << spawnPosition.y;

        return normaliseDirection(spawnPosition - currentPosition);
      }

      return {0, 0};
    }

    sf::Vector2f AI::normaliseDirection(sf::Vector2f direction)
    {
      float len = std::sqrt(direction.x * direction.x + direction.y * direction.y);
      if (len != 0)
      {
        return sf::Vector2f(direction.x / len, direction.y / len);
      }
      return direction;
    }

    bool AI::goalReached(sf::Vector2f current, sf::Vector2f goal)
    {
      sf::Vector2f roundedCurrent = {std::round(current.x), std::round(current.y)};
      sf::Vector2f roundedGoal = {std::round(goal.x), std::round(goal.y)};

      if (roundedCurrent == roundedGoal)
      {
        return true;
      }

      return false;
    }

  }
}

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