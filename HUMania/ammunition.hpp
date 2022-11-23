#include<SDL.h>
#pragma once
#include <iostream>
using namespace std;
class ammunition
{
    protected:
        SDL_Rect srcRect, moverRect;
        string name;
        int impact, travel_speed;
        bool friend_or_foe;
        float reload_time;

    public:
        // add the fly function here as well.
        void draw();
        virtual void move() = 0;
        bool hit();
        friend class war_equipment;
    // may add other overloaded constructors here... 
};
