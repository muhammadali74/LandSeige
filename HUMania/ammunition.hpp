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
        virtual void move(bool) = 0;
        bool hit();
        int get_Damage();
        SDL_Rect get_moverRect() const;
        void set_srcRect(int) ;
    // may add other overloaded constructors here... 
};
class bullet1 : public ammunition
{
    public:
    bullet1(int, int, bool);
    void move(bool);

};
class bomb: public ammunition
{
    public:
    bomb(int, int, bool);
    void move(bool);

};
// class bullet : public ammunition
// {

//     impact = 25;

// };
// class bomb : public ammunition
// {
//     impact = 100;

// };