#pragma once
#include <iostream>
#include <SFML/System/Time.hpp>

namespace Game
{
    namespace Components
    {
        // OOP with an abstract class
       enum GameState
       {
            Menu,
            Playing,
            GameWin,
            GameLose
                       
       };
    }
}