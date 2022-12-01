#include "ammunition.hpp"
#pragma once
#include "SDL.h"
#include "drawing.hpp"


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
    // int animation = moverRect.x % 3;
    // if (animation ==0)
    // {
    //     srcRect = {257, 182, 192, 214};
    // }
    // else if (animation ==1)
    // {
    //     srcRect = {248, 433, 247, 178};
    // }
    // else if (animation ==2)
    // {
    //     srcRect = {257, 24, 173, 134};
    // }
};
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
        // if (moverRect.x % 8 == 2)
        // {
        //     srcRect = {1592, 3758, 239, 120};
        // }
    }
    else
    {
        moverRect.x-=15;
    }
    // int animation = moverRect.x % 3;
    // if (animation ==0)
    // {
    //     srcRect = {257, 182, 192, 214};
    // }
    // else if (animation ==1)
    // {
    //     srcRect = {248, 433, 247, 178};
    // }
    // else if (animation ==2)
    // {
    //     srcRect = {257, 24, 173, 134};
    // }
};