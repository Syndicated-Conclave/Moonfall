#pragma once
#include <iostream>
#include <SFML/System/Time.hpp>

namespace Game
{
    namespace Components
    {
        // OOP with an abstract class
       class State
       {
        public:
            State();
            virtual ~State(){};
            virtual void Init() = 0;
            virtual void ProcessInput() = 0;
            virtual void Update(sf::Time deltaTime) = 0;
            virtual void Draw() = 0;

            //blank implementation of optional methods for pause menu
            virtual void Pause(){};
            virtual void Start(){};            
       };
    }
}