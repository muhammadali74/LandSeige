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
        
    // may add other overloaded constructors here... 
};
class bullet1 : public ammunition
{
    public:
    bullet1(int, int, bool);
    void move();

};
// class bullet : public ammunition
// {

//     impact = 25;

// };
// class bomb : public ammunition
// {
//     impact = 100;

// };