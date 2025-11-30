#pragma once
#include <box2d/box2d.h>
#include <SFML/Graphics.hpp>

namespace Engine
{
  struct Entity
  {
    std::vector<b2BodyId> physicsBodyIds;
    std::vector<std::unique_ptr<sf::Shape>> graphicsShapes;
    bool active = true;
  };

  class EntityManager
  {
  public:
    Entity *createEntity();
    void eraseEntity(Entity *entity);

  private:
    std::vector<std::unique_ptr<Entity>> _entities;
  };
}

/*

FROM THE LABS:


#pragma once

#include <lib/SFML/Graphics.hpp>
#include <memory>

class Component; // forward declare

class Entity
{
public:
  Entity() {}
  virtual ~Entity();

  virtual void update(const float &dt);
  virtual void render();

  template <typename T, typename... Targs>
  std::shared_ptr<T> add_component(Targs... params)
  {
    static_assert(std::is_base_of<Component, T>::value, "T != component");
    std::shared_ptr<T> sp(std::make_shared<T>(this, params...));
    _components.push_back(sp);
    return sp;
  }

  template <typename T>
  const std::vector<std::shared_ptr<T>> get_components() const
  {
    static_assert(std::is_base_of<Component, T>::value, "T != component");
    std::vector<std::shared_ptr<T>> ret;
    for (const auto c : _components)
    {
      if (typeid(*c) == typeid(T))
      {
        ret.push_back(std::dynamic_pointer_cast<T>(c));
      }
    }
    return std::move(ret);
  }

  template <typename T>
  const std::vector<std::shared_ptr<T>> get_compatible_components()
  {
    static_assert(std::is_base_of<Component, T>::value, "T != component");
    std::vector<std::shared_ptr<T>> ret;
    for (auto c : _components)
    {
      auto dd = dynamic_cast<T *>(&(*c));
      if (dd)
      {
        ret.push_back(std::dynamic_pointer_cast<T>(c));
      }
    }
    return ret;
  }

  const sf::Vector2f &get_position() const;
  void set_position(const sf::Vector2f &position);
  bool is_for_deletion() const;
  float get_rotation() const;
  void set_rotation(float rotation);
  bool is_alive() const;
  void set_alive(bool alive);
  void set_for_delete();
  bool is_visible() const;
  void set_visible(bool visible);

protected:
  std::vector<std::shared_ptr<Component>> _components;
  sf::Vector2f _position;
  float _rotation = 0;
  bool is_alive = true;         // should be updated
  bool is_visible = true;       // should be rendered
  bool is_for_deletion = false; // should be deleted
};

struct EntityManager
{
  std::vector<std::shared_ptr<Entity>> list;
  void update(const float &dt);
  void render();
};

class Component
{
public:
  Component() = delete;
  bool is_for_deletion() const;
  virtual void update(const float &dt) = 0;
  virtual void render() = 0;
  virtual ~Component();

protected:
  Entity *const _parent;
  bool is_for_deletion; // should be removed
  explicit Component(Entity *const p);
};


*/