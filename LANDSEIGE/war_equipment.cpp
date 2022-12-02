#include "SDL.h"
#include "drawing.hpp"
#include "war_equipment.hpp"
#include "budget.hpp"
#pragma once

// Parent class functions
void war_equipment::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}

bool war_equipment::is_destroyed() // checks if equipemnt can be destroyed
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

void war_equipment::health_change(int impact) // Modifies health
{
    health -= impact;
}

war_equipment::war_equipment(int x, int y) // constructor
{
    int xbox = 1441 / 7.5;
    int ybox = 810 / 5.25;
    moverRect = {x, y, xbox - 10, ybox - 10};
}

bool war_equipment::has_fired() // checks if ammunition has been fired
{
    if (amm.size() > prev_amm_size)
    {
        prev_amm_size = amm.size();
        return true;
    }
    else
    {
        return false;
    }
}

vector<ammunition *> &war_equipment::get_ammunition() // stores ammunition
{
    return amm;
}

SDL_Rect war_equipment::get_moverRect() const // used to check collision between ammunition and equipment
{
    return moverRect;
}

war_equipment::~war_equipment() // releases the memory on heap
{
    for (int i{0}; i < amm.size(); i++)
    {
        delete amm[i];
    }
}

void war_equipment::delete_amm(int k) // releases the memory on heap once the ammunition colllides with the equipment
{
    delete amm[k];
}

void war_equipment::destruction() // this allows blast animation to be displayed
{
    srcRect = {141, 3133, 326, 285};
    cout << "YAY";
};

void war_equipment::fire(bool foe)
{
}

void war_equipment::fire_bullet(bool foe) // used for MG
{
}

// child classes start here

// Generator
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
}

void generator::fire(bool foe)
{

    if ((SDL_GetTicks() - creation_time) % 1000 >= 0 && (SDL_GetTicks() - creation_time) % 1000 <= 10)
    {
        *(cashmod) + 200;
    }
}

// Tanker

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
}

void tanker::fire_bullet(bool foe)
{
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move(foe);
        amm[i]->draw();
    };
}

void tanker::move()
{
    moverRect.x -= 1;
}

// LandMG
landMG::landMG(int x, int y, budget &b) : war_equipment{x, y}
{
    srcRect = {511, 1449, 341, 315};
    health = 550;
    price = 600;
    b - price;
}

void landMG::fire(bool foe)
{
    if (SDL_GetTicks() % 80 == 0 || SDL_GetTicks() % 80 == 5 || SDL_GetTicks() % 80 == 10 || SDL_GetTicks() % 80 == 15)
    {
        amm.push_back(new bullet1(moverRect.x + 192, moverRect.y + 20, foe));
    }
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

// Landmine
landmine::landmine(int x, int y, budget &b) : war_equipment{x, y}
{

    srcRect = {1284, 2538, 298, 221};
    health = 800;
    price = 200;
    b - price;
}

void landmine::move()
{
}

void landmine::fire(bool foe)
{
}

// turret

turret::turret(int x, int y, budget &b) : war_equipment{x, y}
{
    srcRect = {142, 1831, 249, 214};

    health = 300;
    price = 300;
    b - price;
}

void turret::fire(bool foe)
{
    if (rand() % 50 == 4)
    {
        amm.push_back(new bullet1(moverRect.x + 145, moverRect.y + 45, foe));
    };
}

void turret::fire_bullet(bool foe)
{
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->draw();
        amm[i]->move(foe);
    }
}

void turret::move()
{
    moverRect.x -= 1;
}

// thunder
thunder::thunder(int x, int y, bool z, budget &b) : war_equipment{x, y}
{
    health = 500;
    price = 1050;
    if (z == true)
    {
        srcRect = {902, 1809, 381, 267};
        b - price;
    }
    else
    {
        srcRect = {65, 2519, 486, 236};
    }
}

void thunder::move()
{
    moverRect.x -= 2;
}

void thunder::fire(bool foe)
{

    if (foe)
    {
        if (rand() % 10 == 1)
        {
            amm.push_back(new bullet1(moverRect.x + 145, moverRect.y + 15, foe));
            cout << "what";
        }
    }
    else
    {
        if (rand() % 20 == 1)
        {
            amm.push_back(new bullet1(moverRect.x - 20, moverRect.y + 52, foe));
        }
    }
}

void thunder::fire_bullet(bool foe)
{
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->draw();
        amm[i]->move(foe);
    }
}
