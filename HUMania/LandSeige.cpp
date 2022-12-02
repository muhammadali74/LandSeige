#include <iostream>
#include "LandSeige.hpp"
#include <SDL_ttf.h>
#pragma once
int m;    // for enemy equipment blast display time
int n;    // for user equipment blast time
int g{0}; // for enemy ammunition blast display time
int h{0}; // for user equipment blast display time

LandSeige::LandSeige()
{
    int l = 5000;
    int x = 175;
    for (int i = 0; i < 6; i++)
    {
        reloaders[i] = Reloader{x, l};
        l += 2000;
        x += 163;
    }
}

void LandSeige::drawObjects()
{
    // call draw functions of all the objects here
    for (int i{0}; i < user.size(); i++)
    {
        user[i]->draw();
        if (objCreator.should_fire(user[i]->get_moverRect().y) == true || user[i]->name == "generator")
        {
            user[i]->fire(true);
            if (user[i]->name != "generator")
            {
                if (user[i]->has_fired() == true)
                {
                    shot = true;
                }
            }
        }
        for (int j{0}; j < enemy.size(); j++)
        {
            if (user[i]->get_moverRect().y == enemy[j]->get_moverRect().y)
            {
                for (int k{0}; k < enemy[j]->get_ammunition().size(); k++)
                {
                    if ((enemy[j]->get_ammunition()[k]->get_moverRect().x - user[i]->get_moverRect().x < 80))
                    {
                        if (g == 0)
                        {
                            user[i]->health_change(enemy[j]->get_ammunition()[k]->get_Damage());
                            hit = true;
                        }
                        enemy[j]->get_ammunition()[k]->set_srcRect(g);
                        // user[i]->fire(true);
                        g++;
                        if (g > 4)
                        {
                            enemy[j]->get_ammunition().erase(enemy[j]->get_ammunition().begin() + k);
                            cout << "impact user equiptment" << endl;
                            g = 0;
                        }
                    }
                }
            }
        }

        user[i]->fire_bullet(true);

        if (user[i]->is_destroyed() == true)
        {
            user[i]->destruction();
            user[i]->draw();
            m++;
            if (m > 10)
            {
                objCreator.free_grid2(user[i]->get_moverRect().x, user[i]->get_moverRect().y);
                delete user[i];
                user.erase(user.begin() + i);
                destroy = true;
                cout << "object of the user has been destroyed" << endl;
                m = 0;
            }
        }
    }
    if (enemy.size() > 0)
    {
        for (int i{0}; i < enemy.size(); i++)
        {
            enemy[i]->draw();
            if ((enemy[i]->get_moverRect().x) <= -150)
            {
                Lose = true;
            }
            // enemy[i]->fire();
            // cout << enemy[i]->get_moverRect().x << " " << enemy[i]->get_moverRect().y << endl;
            if (objCreator.check_grid((enemy[i]->get_moverRect().x) - 40, enemy[i]->get_moverRect().y) == true)
            {
                // cout << "dont move" << endl;
            }
            else
            {
                objCreator.set_grid_false(enemy[i]->get_moverRect().x - 40, enemy[i]->get_moverRect().y);
                enemy[i]->move();
            }
            // enemy[i]->move();

            for (int j{0}; j < user.size(); j++)
            {
                if (enemy[i]->get_moverRect().y == user[j]->get_moverRect().y)
                {
                    for (int k{0}; k < user[j]->get_ammunition().size(); k++)
                    {
                        if ((enemy[i]->get_moverRect().x - user[j]->get_ammunition()[k]->get_moverRect().x < 5))
                        {
                            if (h == 0)
                            {
                                enemy[i]->health_change(user[j]->get_ammunition()[k]->get_Damage());
                                hit = true;
                            }
                            user[j]->get_ammunition()[k]->set_srcRect(h);
                            h++;
                            if (h > 4)
                            {
                                user[j]->get_ammunition().erase(user[j]->get_ammunition().begin() + k);
                                cout << "imapact call " << endl;
                                h = 0;
                            }
                        }
                    }
                }
            }

            enemy[i]->fire(false);
            if (enemy[i]->has_fired() == true)
            {
                shot = true;
            }

            if (enemy[i]->is_destroyed() == true) // checks if the bee hits the screen exit
            {
                enemy[i]->destruction();
                enemy[i]->draw();
                n++;
                if (n > 10)
                {
                    objCreator.free_grid(enemy[i]->get_moverRect().x, enemy[i]->get_moverRect().y);
                    objCreator.set_row(enemy[i]->get_moverRect().y);
                    delete enemy[i];                // deletes the bee, and the pointer becomes in a dangling state
                    enemy.erase(enemy.begin() + i); // erases that dangling pointer after freeing the memory
                    destroy = true;
                    cout << "object of the enemy has been destroyed" << endl;
                    n = 0;
                }
            }
        }
    }

    else if (enemy.size() == 0 && SDL_GetTicks() > play_time)
    {
        Win = true;
        cout << "you win" << endl;
    }

    DrawText(cash.getbudget_4());
}

// creates new objects
void LandSeige::createEnemyEquipment()
{
    // this allows random generaion of the bee, butterfly or pigeon
    if (SDL_GetTicks() < play_time)
    {
        int rtm = rand() % 5;

        if (rtm <= 3)
        {
            enemy.push_back(objCreator.getObject(cash));
            cout << "enemy created" << endl;
        }
    }
    else
    {
        cout << "not geenrating enemies now" << endl;
    }
    // rtm++;
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void LandSeige::createUserEquipment(int x, int y)
{

    // if (keypress.size() > 0)
    if (keypressed > 0)
    {
        // int key = keypress.back();
        // keypress.pop_back();
        war_equipment *temp = objCreator.getObject(x, y, keypressed, cash);
        keypressed = 0;
        if (temp != nullptr)
        {
            user.push_back(temp);
        }
        std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
    }
    else if (keypressed == -1)
    {
        keypressed = 0;
        // Remove_equipment(x, y);
    }
    else
    {
        cout << "please select an equipment (keys 1-6)" << endl;
    }
}

LandSeige::~LandSeige() // this destructor ensures that all the memor that was dynamically allocated is deallocated.
{
    for (int i{0}; i < enemy.size(); i++)
    {
        delete enemy[i];
    }
    for (int i{0}; i < user.size(); i++)
    {
        delete user[i];
    }
    cout << "destructor called";
}

bool LandSeige::has_budget(int price)
{
    if (cash.getbudget() >= price)
    {
        return true;
    }
    else
    {
        return false;
    }
};

bool LandSeige::has_lost()
{
    return Lose;
}

bool LandSeige::has_won()
{
    return Win;
}

void LandSeige::Remove_equipment(int x, int y)
{
    for (int i{0}; i < user.size(); i++)
    {
        if (user[i]->get_moverRect().x == x && user[i]->get_moverRect().y == y)
        {
            objCreator.free_grid2(user[i]->get_moverRect().x, user[i]->get_moverRect().y);
            delete user[i];
            user.erase(user.begin() + i);
            cout << "object of the user has been removed by user" << endl;
        }
    }
}

void LandSeige::handleprogress()
{
    progressbar.draw();
    progressbar.state(SDL_GetTicks());
    weaponSelector.draw();
    weaponSelector.select_current(keypressed);
}

void LandSeige::handlereloader()
{
    for (int i = 0; i < 6; i++)
    {
        reloaders[i].draw();
        reloaders[i].reload(SDL_GetTicks() - objCreator.get_creation_time(i + 1));
    }
}

void LandSeige::DrawText(const char *msg)
{
    SDL_Surface *surface;
    SDL_Texture *texture;
    TTF_Font *font = TTF_OpenFont("orbitron.ttf", 24);
    SDL_Color color;
    color.r = 0;
    color.g = 255;
    color.b = 0;
    color.a = 255;
    SDL_Rect rect;
    surface = TTF_RenderText_Solid(font, msg, color);
    texture = SDL_CreateTextureFromSurface(Drawing::gRenderer, surface);
    rect.x = 51;
    rect.y = 23;
    rect.w = surface->w;
    rect.h = surface->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(Drawing::gRenderer, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
}
