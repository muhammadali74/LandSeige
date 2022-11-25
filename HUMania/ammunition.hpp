#include<SDL.h>
#pragma once
#include <iostream>
using namespace std;
class ammunition
{
    protected:
        SDL_Rect srcRect, moverRect;
        int impact;
        bool friend_or_foe;
    public:
        // add the fly function here as well.
        void draw();
        virtual void move() = 0;
        bool hit();
        friend class war_equipment;
    // may add other overloaded constructors here... 
};
// class bullet1 : public ammunition
// {
//     impact = 50;

// };
// class bullet : public ammunition
// {

//     impact = 25;

// };
// class bomb : public ammunition
// {
//     impact = 100;

// };