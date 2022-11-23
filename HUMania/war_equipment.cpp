#include "SDL.h"
#include "drawing.hpp"
#include "war_equipment.hpp"
#pragma once

void war_equipment::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
bool war_equipment::is_destroyed() //this ensures that when fucntion is called for pigeon or butterfly there is no error because these two classes have no implementation of deleteCheck()
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
    health-=impact;
}