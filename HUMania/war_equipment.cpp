#include "SDL.h"
#include "drawing.hpp"
#include "war_equipment.hpp"
#pragma once

void war_equipment::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
bool war_equipment::is_destroyed() // this ensures that when fucntion is called for pigeon or butterfly there is no error because these two classes have no implementation of deleteCheck()
{
    if (health == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void war_equipment::health_change(int impact)
{
    health -= impact;
}

war_equipment::war_equipment(int x, int y)
{
    int xbox = 1441 / 7.5;
    int ybox = 810 / 5.25;
    // it will display pigeon on x = 30, y = 40 location, the size of pigeon is 50 width, 60 height
    moverRect = {x, y, xbox - 10, ybox - 10};
}
generator::generator(int x, int y) : war_equipment{x,y}
{
    health = 500;
    price = 300;
    srcRect = {80, 1450, 348, 308};
}
void generator::move()
{
    moverRect.x += 3;
}