#include "StateManager.hpp"

Game::Components::StateManager::StateManager()
{

}

Game::Components::StateManager::~StateManager()
{
    
}

void Game::Components::Add(std::unique_ptr<Game::Components::State> toAdd, bool replace = false)
{

}
void Game::Components::PopCurrent()
{

}
void Game::Components::ProcessStateChange()
{

}
std::unique_ptr<Game::Components::State>& getCurrent()
{
    
}