#include "SDL.h"
#include "drawing.hpp"
#include "war_equipment.hpp"
#include "budget.hpp"
#pragma once

int b{0};
int c{0};

void war_equipment::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
bool war_equipment::is_destroyed() // this ensures that when fucntion is called for pigeon or butterfly there is no error because these two classes have no implementation of deleteCheck()
{
    if (health <= 0)
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
    moverRect = {x, y, xbox - 10, ybox - 10};
}

vector<ammunition *> &war_equipment::get_ammunition()
{
    return amm;
}

SDL_Rect war_equipment::get_moverRect() const
{
    return moverRect;
}
// child classes start here

generator::generator(int x, int y, budget &b) : war_equipment{x, y}
{
    health = 500;
    price = 300;
    srcRect = {80, 1450, 348, 308};
    b - price;
    cashmod = &b;
    name = "generator";
}
void generator::move()
{
    // moverRect.x += 3;
}

void generator::fire(bool foe)
{

    if ((SDL_GetTicks() - creation_time) % 1000 >= 0 && (SDL_GetTicks() - creation_time) % 1000 <= 10)
    {
        *(cashmod)+200;
    }
}

tanker::tanker(int x, int y, bool z, budget &b) : war_equipment{x, y}
{
    health = 750;
    price = 800;
    if (z == true)
    {
        srcRect = {461, 1826, 365, 270};
        b - price;
    }
    else
    {
        srcRect = {975, 1500, 443, 231};
    }

    
}
void war_equipment::destruction()
{
    srcRect= {141, 3133, 326, 285};
    cout << "YAY";
};
void war_equipment::fire(bool foe)
{
}

void war_equipment::fire_bullet(bool foe)
{
}

void tanker::fire(bool foe)
{
    if (rand() % 100 == 4)
    {
        if (foe)
        {
            amm.push_back(new bomb(moverRect.x + 145, moverRect.y + 15, foe));
        }
        else
        {
            amm.push_back(new bomb(moverRect.x - 20, moverRect.y + 10, foe));
        }
    };

    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move(foe);
        amm[i]->draw();
    };
}
void tanker::move()
{
    moverRect.x -= 1;
    
    
    // for(int i{0}; i < 500; i++)
    // {
    //     if (i%2==0)
    //     srcRect = {461, 1826, 365, 270};
    //     else if (i%3==0)
    //     srcRect = {2, 361, 159, 124};
    //     else
    //     srcRect = {7, 88, 155, 103};
    // }
}
landMG::landMG(int x, int y, budget &b) : war_equipment{x, y}
{
    srcRect = {511, 1449, 341, 315};
    health = 550;
    price = 600;
    b - price;
}
void landMG::fire(bool foe)
{
    // if
    // (b % 5 == 0)
    // {
    if (SDL_GetTicks() % 80 == 0 || SDL_GetTicks() % 80 == 5 || SDL_GetTicks() % 80 == 10 || SDL_GetTicks() % 80 == 15)
    {
        amm.push_back(new bullet1(moverRect.x + 192, moverRect.y + 20, foe));
    }

    b++;
}

void landMG::fire_bullet(bool foe)
{
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->draw();
        amm[i]->move(foe);
    }
}

void landMG::move()
{
}

landmine::landmine(int x, int y, budget &b) : war_equipment{x, y}
{

    srcRect = {1284, 2538, 298, 221};
    health = 150;
    price = 200;
    b - price;
}
void landmine::move()
{
}
void landmine::fire(bool foe)
{
    health--;
    if (health == 60)
    {
        srcRect = {141, 3133, 326, 285};
    }
    else if (health == 50)
    {
        srcRect = {141, 3427, 326, 285};
    }
}
turret::turret(int x, int y, budget &b) : war_equipment{x, y}
{
    srcRect = {142, 1831, 249, 214};

    health = 300;
    price = 300;
    b - price;
}
void turret::move()
{
    moverRect.x -= 1;
}
thunder::thunder(int x, int y, bool z, budget &b) : war_equipment{x, y}
{
    if (z == true)
    {
        srcRect = {902, 1809, 381, 267};
        b - price;
    }
    else
    {
        srcRect = {65, 2519, 486, 236};
    }
    health = 500;
    price = 1000;
}
void thunder::move()
{
    moverRect.x -= 2;
}
void thunder::fire(bool foe)
{
    if (rand() % 50 == 4)
    {
        if (foe)
        {
            amm.push_back(new bullet1(moverRect.x + 145, moverRect.y + 15, foe));
        }
        else
        {
            amm.push_back(new bullet1(moverRect.x - 20, moverRect.y + 52, foe));
        }
    };

    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move(foe);
        amm[i]->draw();
    };
}
void turret::fire(bool foe)
{
    if (rand() % 50 == 4)
    {
        amm.push_back(new bullet1(moverRect.x + 145, moverRect.y + 45, foe));
        
    };

    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move(foe);
        amm[i]->draw();
    };
}