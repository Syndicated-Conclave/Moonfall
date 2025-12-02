#include "ecm.hpp"

namespace Engine
{
  Entity *EntityManager::createEntity()
  {
    auto entity = std::make_unique<Entity>(); // creates new entity with unique_ptr (exclusive ownership)
    Entity *pointer = entity.get();
    _entities.push_back(std::move(entity)); // transfers ownership to _entities
    return pointer;
  }

  void EntityManager::eraseEntity(Entity *entity)
  {
    if (entity == NULL)
    {
      return;
    }

    for (size_t i = 0; i < _entities.size(); i++)
    {
      if (_entities[i].get() == entity)
      {
        _entities.erase(_entities.begin() + i);
        break;
      }
    }
  }
}
