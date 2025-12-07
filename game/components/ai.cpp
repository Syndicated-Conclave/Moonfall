#include "ai.hpp"

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
        newDirection = {0, 0}; // stationary
        break;
      case 2:
        newDirection = getLyraDirection(previousDirection, spawnPosition, currentPosition);
        break;
      case 3:
        newDirection = getLeoDirection(spawnPosition, currentPosition, moonPosition);
        break;
      default:
        newDirection = {0, 0}; // should not occur, only here as a failsafe
      }
      return newDirection;
    }

    sf::Vector2f AI::getLyraDirection(sf::Vector2f previousDirection, sf::Vector2f spawnPosition, sf::Vector2f currentPosition)
    {
      sf::Vector2f newDirection;

      sf::Vector2f relationalPosition = currentPosition - spawnPosition;
      

      // coordinates of the different points the stardust will move between
      std::vector<sf::Vector2f> points = {{0, 0}, {37.5,22.5}, {4, 33}, {12.5, 60}};

      for (size_t i = 0; i < points.size(); i++)
      {
        if (goalReached(relationalPosition, points[i])) // check if a point has been reached
        {
          // set direction to the change vector between the next and the current point
          return normaliseDirection(points[(i + 1) % points.size()] - points[i]);
        }
      }
      return previousDirection;
    }

    sf::Vector2f AI::getLeoDirection(sf::Vector2f spawnPosition, sf::Vector2f currentPosition, sf::Vector2f moonPosition)
    {
      sf::Vector2f distanceVector = moonPosition - currentPosition; // change vector between the moon and the stardust

      float distance = std::sqrt(distanceVector.x * distanceVector.x + distanceVector.y * distanceVector.y);

      if (distance < FLEE_DISTANCE)
      {
        return normaliseDirection(-distanceVector) * FLEE_SPEED; // flee in the opposite direction
      }
      else if (!goalReached(currentPosition, spawnPosition)) // check if at spawn position
      {
        return normaliseDirection(spawnPosition - currentPosition); // move to spawn position
      }

      return {0, 0};
    }

    sf::Vector2f AI::normaliseDirection(sf::Vector2f direction)
    {
      // scales all vectors to length 1
      float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
      if (length != 0) // length = 0 can't be normalised so is returned as is
      {
        return sf::Vector2f(direction.x / length, direction.y / length);
      }
      return direction;
    }

    bool AI::goalReached(sf::Vector2f current, sf::Vector2f goal)
    {
      // rounding to avoid floating point mismatch
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
