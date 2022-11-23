#include "SDL.h"
#pragma once
#include "ammunition.hpp"
using namespace std;
#include <iostream>
class war_equipment
{
    protected:
        SDL_Rect srcRect, moverRect;
        string name;
        int health, price, ammunition_capacity;
        bool friend_or_foe;

    public:
        void draw();
        virtual void move() = 0;
        bool is_destroyed();  
        void health_change(int impact);//this is to delete bee when it exits the screen
};