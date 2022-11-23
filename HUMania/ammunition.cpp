#include "ammunition.hpp"
#pragma once
#include "SDL.h"
#include "drawing.hpp"


void ammunition::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}