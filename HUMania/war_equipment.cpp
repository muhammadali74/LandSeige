#include "SDL.h"
#include "drawing.hpp"
#include "war_equipment.hpp"
#pragma once

int b{0};

void war_equipment::draw()
{
    SDL_RenderCopy(Drawing::gRenderer, Drawing::assets, &srcRect, &moverRect);
}
bool war_equipment::is_destroyed() // this ensures that when fucntion is called for pigeon or butterfly there is no error because these two classes have no implementation of deleteCheck()
{
    if (health <= 0 )
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
tanker:: tanker(int x, int y, bool z): war_equipment{x,y}
{
    if (z==true)
    {
        srcRect = {461, 1826, 365, 270};
    }
    else
    {
        srcRect = {975, 1500, 443, 231};
    }
    
    health = 750;
    price = 800;
}
void war_equipment::fire()
{

}
void tanker::fire()
{
    if (rand()%10 == 4)
    {
        amm.push_back(new bomb(moverRect.x+192, moverRect.y, true));
    };
    
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move();
        amm[i]->draw();
    };
}
void tanker::move()
{
    moverRect.x += 4;
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
landMG::landMG(int x, int y): war_equipment{x,y}
{
    srcRect = {511, 1449, 341, 315};
    health = 550;
    price = 600;
}
void landMG::fire()
{
    if (b%5 ==0)
    {
        amm.push_back(new bullet1(moverRect.x+192, moverRect.y + 20, true));
    };
    b++;
    for (int i{0}; i < amm.size(); i++)
    {
        amm[i]->move();
        amm[i]->draw();
    };
}
void landMG::move()
{
    
}

landmine::landmine(int x, int y): war_equipment{x,y}
{
    

    srcRect = {1284, 2538, 298,221};
    health = 150;
    price = 200;
}
void landmine::move()
{
    // k++;
    health--;
}
void landmine::fire()
{
    if(health == 60)
    {
        srcRect={141,3133,326,285};
        
    }
    else if (health ==50)
    {
        srcRect = {141,3427,326,285};
    }
    // if (k==140)
    // {
    //     health=0;
    // }
    
}
turret::turret(int x, int y): war_equipment{x,y}
{
    srcRect = {142, 1831, 249,214};

    health = 300;
    price = 300;
}
void turret::move()
{

}
thunder::thunder(int x, int y, bool z): war_equipment{x,y}
{
    if (z==true)
    {
        srcRect = {902, 1809, 381, 267};
    }
    else
    {
        srcRect= {65, 2519, 486, 236};
    }
    health = 500;
    price = 1000;
}
void thunder::move()
{

}

