#pragma once
#include <iostream>
#include <SFML/System/Time.hpp>

namespace Game
{
    namespace Components
    {
        // enum that holds states for Menu and game levels
       enum State
       {
            Menu,
            Playing,
            GameWin,
            GameLose
                       
       };
    }
}