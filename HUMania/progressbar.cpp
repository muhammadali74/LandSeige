#include <SDL.h>
#include "drawing.hpp"
#pragma once

class ProgressBar
{
protected:
    SDL_Rect srcRect = {0, 0, 0, 0};
    SDL_Rect destRect = {1017, 773, 100, 20};

public:
    void draw()
    {
        SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &destRect);
    }

    void state(Uint64 time)
    {
        if (time > 10000 && time < 30000)
        {
            srcRect = {1772, 2411, 177, 38};
            destRect = {1017, 773, 30, 20};
        }
        else if (time >= 30000 && time < 60000)
        {
            destRect = {1017, 773, 60, 20};
        }
        else if (time >= 60000 && time <= 90000)
        {

            destRect = {1017, 773, 90, 20};
        }
        else if (time >= 90000 && time <= 120000)
        {
            destRect = {1017, 773, 120, 20};
        }
        else if (time >= 120000 && time <= 150000)
        {
            destRect = {1017, 773, 150, 20};
        }
        else if (time >= 150000 && time <= 180000)
        {
            destRect = {1017, 773, 180, 20};
        }
        else if (time >= 180000 && time <= 210000)
        {
            destRect = {1017, 773, 210, 20};
        }
        else if (time >= 210000 && time <= 240000)
        {
            destRect = {1017, 773, 240, 20};
        }
        else if (time >= 240000 && time <= 270000)
        {
            destRect = {1017, 773, 270, 20};
        }
        else if (time >= 270000 && time <= 300000)
        {
            destRect = {1017, 773, 300, 20};
        }
    }
};