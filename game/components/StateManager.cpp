#include "StateManager.hpp"
#include "gameStates.hpp"

Game::Components::StateManager::StateManager() : m_add(false), m_replace(false), m_remove(false)
{

}

Game::Components::StateManager::~StateManager()
{
    
}

void Game::Components::StateManager::Add(std::unique_ptr<Game::Components::State> toAdd, bool replace = false)
{
    m_add = true;
    m_newState = std::move(toAdd);

    m_replace = replace;
}

void Game::Components::StateManager::PopCurrent()
{
    m_remove = true;
}

void Game::Components::StateManager::ProcessStateChange()
{
    if(m_remove && (!m_stateStack.empty()))
    {
        m_stateStack.pop();
        
        if(!m_stateStack.empty())
        {
            m_stateStack.top()->Start();
        }

        m_remove = false;
    }

    if(m_add)
    {
        if(m_replace && (!m_stateStack.empty()))
        {
            m_stateStack.pop();
            m_replace = false;
        }

        if(m_stateStack.empty())
        {
            m_stateStack.top()->Pause();
        }

        m_stateStack.push(std::move(m_newState));
        m_add = false;
    }
}
std::unique_ptr<Game::Components::State>& Game::Components::StateManager::GetCurrent()
{
    return m_stateStack.top();
}