#include "ammunition.hpp"
#pragma once
#include "SDL.h"
#include "drawing.hpp"

//PArent class ammunition functions
void ammunition::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

int ammunition::get_Damage()
{
    return impact;
}

SDL_Rect ammunition::get_moverRect() const
{
    return moverRect;
}

void ammunition::set_srcRect(int v) 
{
    
    moverRect.w = (60);
    moverRect.h = 40;
    
    if (v < 2)
    {
        srcRect = {1197, 3154,234,146};
    }
    else
    {
        srcRect = {528, 3135,292, 236};
    }
    cout << "yupe" << endl;
}

//child class bullet1
bullet1::bullet1(int x, int y, bool z)
{
    friend_or_foe = z;
    impact = 50;
    if (z)
    {
        srcRect = {1186, 2928, 177, 30};
    }
    else
    {
        srcRect= {910, 2930, 177, 30};
    }
    
    moverRect = {x, y, 50,10};
}

void bullet1::move(bool foe)
{
    if(foe)
    {
         moverRect.x+=14;
    }
    else
    {
         moverRect.x-=14;
    }
};

//child class bomb
bomb::bomb(int x, int y, bool z)
{
    friend_or_foe = z;
    impact = 50;
    if (z)
    {
        srcRect ={1592, 3758, 239, 120};
    }
    else
    {
        srcRect = {950, 3144, 234, 156};
    }
    
    moverRect = {x, y, 50,50};
}

void bomb::move(bool foe)
{
    if (foe)
    {
        moverRect.x+=15;
    }
    else
    {
        moverRect.x-=15;
    }
};