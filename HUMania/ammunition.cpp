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

bullet1::bullet1(int x, int y, bool z)
{
    friend_or_foe = z;
    impact = 50;
    srcRect = {1186, 2928, 177, 30};
    moverRect = {x, y, 50,10};
}

void bullet1::move()
{
    moverRect.x+=12;
    
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
    srcRect = {1597, 3545,234,156};
    moverRect = {x, y, 50,50};
}

void bomb::move()
{
    moverRect.x+=8;
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