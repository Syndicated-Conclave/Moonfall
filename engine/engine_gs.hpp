#pragma once
#include <memory>
#include <vector>
#include <lib/SFML/Graphics.hpp>
#include "engine_em.hpp"

class Scene;//forward definition

class GameSystem{
public:
    static void start(unsigned int width, unsigned int height, 
                      const std::string& name, const float& time_step,
                      bool physics_enabled = false);
    static void clean();
    static void reset();
    static void set_active_scene(const std::shared_ptr<Scene>& act_sc);
    static std::shared_ptr<Scene> &get_active_scene(){return _active_scene;}

private:
    static void _init();
    static void _update(const float &dt);
    static void _render();
    static std::shared_ptr<Scene> _active_scene;
    static bool _physics_enabled;
};

class Scene {
public:
  Scene() = default;

  virtual ~Scene() = default;
  virtual void update(const float &dt);
  virtual void render();
  virtual void load() = 0;
  virtual void unload();

  const std::shared_ptr<Entity> &make_entity();

  std::vector<std::shared_ptr<Entity>> &get_entities(){return _entities.list;}

protected:
  EntityManager _entities;
};
