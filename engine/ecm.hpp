#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

// namespace used for all game engine specific classes, structs and variables
namespace Engine
{
  // ENTITY

  // this structure is used for all game entities
  struct Entity
  {
    // a list of all physics bodies an entity may have
    std::vector<b2BodyId> physicsBodyIds;
    // a list of all graphics shapes an entity may have
    std::vector<std::unique_ptr<sf::Shape>> graphicsShapes;
    // a bool to store whether the entity is active or not, default true
    bool active = true;
  };

  // ENTITY MANAGER

  // this class creates, erases and stores all entities
  class EntityManager
  {
  public:
    // creates and adds new blank entity to the end of the the entities list and returns a pointer to it
    Entity *createEntity();
    // erases the entity whose pointer was passed in
    void eraseEntity(Entity *entity);

  private:
    // stores all entities
    std::vector<std::unique_ptr<Entity>> _entities;
  };
}
