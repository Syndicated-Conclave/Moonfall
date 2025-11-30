#pragma once
#include <stack>
#include <memory>
#include <gameStates.hpp>

namespace Game
{
    namespace Components
    {
        class StateManager
        {
            private:
                std::stack<std::unique_ptr<Game::Components::State>> m_stateStack;
                std::unique_ptr<Game::Components::State> m_newState;
                
                bool m_add;
                bool m_replace;
                bool m_remove;
            
            public:
                StateManager();
                ~StateManager();

                void Add(std::unique_ptr<Game::Components::State> toAdd, bool replace = false);
                void PopCurrent();
                void ProcessStateChange();
                std::unique_ptr<Game::Components::State>& getCurrent();
        };

    }
}
