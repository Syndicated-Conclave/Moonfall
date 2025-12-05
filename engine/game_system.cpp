/*

FROM THE LABS:



#include <iostream>
#include "engine_gs.hpp"
#include "engine_phys.hpp"
#include "engine_renderer.hpp"

std::shared_ptr<Scene> GameSystem::_active_scene;
bool GameSystem::_physics_enabled;

void GameSystem::start(unsigned int width, unsigned int height,
                      const std::string& name, const float &time_step,
                      bool physics_enabled){
  _physics_enabled = physics_enabled;
  sf::RenderWindow window(sf::VideoMode({width, height}), name);
  Renderer::initialise(window);
  _init();
  sf::Event event;
  while(window.isOpen()){
    static sf::Clock clock;
    float dt = clock.restart().asSeconds();
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
        clean();
        return;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
      window.close();
    }
    window.clear();
    _update(dt);
    _render();
    sf::sleep(sf::seconds(time_step));
    //Wait for Vsync
    window.display();
  }
  window.close();
  clean();
}

void GameSystem::set_active_scene(const std::shared_ptr<Scene> &act_sc){
  _active_scene = act_sc;
}

void GameSystem::_init() {

}

void GameSystem::clean(){
  _active_scene->unload();
}

void GameSystem::_update(const float &dt){
  _active_scene->update(dt);
  if(_physics_enabled)
    Physics::update(Physics::time_step);
  Renderer::update(dt);
}

void GameSystem::_render(){
  _active_scene->render();
  Renderer::render();
}

void Scene::update(const float &dt){
  for(std::shared_ptr<Entity> &ent: _entities.list){
    ent->update(dt);
  }
}

void Scene::render(){
    for(std::shared_ptr<Entity> &ent: _entities.list){
      ent->render();
    }
}

void Scene::unload(){
  _entities.list.clear();
}

const std::shared_ptr<Entity> &Scene::make_entity(){
  std::shared_ptr<Entity> entity = std::make_shared<Entity>();
  _entities.list.push_back(entity);
  return _entities.list.back();
}

*/