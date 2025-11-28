#include "ecm.hpp"

namespace Engine
{
  Entity *EntityManager::createEntity()
  {
    auto entity = std::make_unique<Entity>();
    Entity *pointer = entity.get();
    _entities.push_back(std::move(entity));
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

/*

FROM THE LABS:


#include "engine_em.hpp"
#include "engine_renderer.hpp"

void EntityManager::update(const float &dt){
  for (size_t i = 0; i < list.size(); i++) {
    if (list[i]->is_for_deletion()) {
      list.erase(list.begin() + i);
      --i;
      continue;
    }
    if (list[i]->is_alive()) {
      list[i]->update(dt);
    }
  }
}

void EntityManager::render(){
  for(std::shared_ptr<Entity> &e: list)
    if(e->is_visible())
      e->render();
}

const sf::Vector2f &Entity::get_position() const { return _position;}

void Entity::set_position(const sf::Vector2f &pos) {
  _position = pos;
}

void Entity::update(const float &dt) {
  for(std::shared_ptr<Component> &comp: _components)
    comp->update(dt);
}

void Entity::render(){
  for(std::shared_ptr<Component> &comp: _components)
    comp->render();
}

bool Entity::is_for_deletion() const{
  return _for_deletion;
}

float Entity::get_rotation() const{
  return _rotation;
}

void Entity::set_rotation(float rotation){
  _rotation = rotation;
}

bool Entity::is_alive() const{
  return _alive;
}

void Entity::set_alive(bool alive){
  _alive = alive;
}
void Entity::set_for_delete(){
  _for_deletion = true;
  _alive = false;
  _visible = false;}

bool Entity::is_visible() const{
  return _visible;
}

void Entity::set_visible(bool visible){
  _visible = visible;
}
Entity::~Entity() {
  // Components can inter-depend on each other, so deleting them may take
  // multiple passes.Keep deleting components until you can't delete any
  // more
  int deli = 0;
  while (deli != _components.size()) {
    deli = _components.size();
    _components.erase(
        remove_if(_components.begin(), _components.end(),
                  [](auto& sp) { return (sp.use_count() <= 1); }),
        _components.end());
  }

  if (_components.size() > 0) {
    throw std::runtime_error(
        "Can't delete entity, something is grabbing a component!");
  }

  _components.clear();
}

Component::Component(Entity *const p) : _parent(p), _for_deletion(false){}

bool Component::is_for_deletion() const{
  return _for_deletion;
}

Component::~Component(){}

*/
