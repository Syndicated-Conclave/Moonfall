#include "engine_renderer.hpp"
#include <queue>

//queue for sprites
static std::queue<const sf::Drawable *> sprites;
static sf::RenderWindow *rw;

void Renderer::initialise(sf::RenderWindow &r) { rw = &r; }

sf::RenderWindow &Renderer::get_window() { return *rw; }

void Renderer::shutdown() {
  while (!sprites.empty())
    sprites.pop();
}

void Renderer::update(const float &) {}

void Renderer::render() {
  if (rw == nullptr) {
    throw("cant render window, no window set!");
  }
  while (!sprites.empty()) {
    rw->draw(*sprites.front());
    sprites.pop();
  }
}

void Renderer::queue(const sf::Drawable *s) { sprites.push(s); }