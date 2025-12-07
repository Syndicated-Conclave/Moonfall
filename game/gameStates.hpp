#pragma once
#include <iostream>

namespace Game
{

    // enum that holds states for Menu and game levels
    enum State
    {
        Menu,
        LevelSelection,
        Guide,
        Playing,
        GameWin,
        GameLose,
        Exit,

    };

}