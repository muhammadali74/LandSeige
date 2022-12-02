#include "SDL.h"
#pragma once
#include "ammunition.hpp"
using namespace std;
#include <iostream>
#include <vector>
#include "budget.hpp"
class war_equipment
{
protected:
    SDL_Rect srcRect, moverRect;
    int health, price, ammunition_capacity;
    bool z;
    vector<ammunition *> amm;
    int prev_amm_size = 0;

public:
    ~war_equipment();
    void delete_amm(int k);
    virtual void destruction();
    string name = "else";
    Uint64 creation_time = SDL_GetTicks();
    war_equipment(int x, int y);
    void draw();
    virtual void move() = 0;
    virtual void fire(bool);
    virtual void fire_bullet(bool);
    bool is_destroyed();
    void health_change(int impact); 
    vector<ammunition *> &get_ammunition();
    SDL_Rect get_moverRect() const;
    bool has_fired();
};

class generator : public war_equipment
{
    budget *cashmod = nullptr;

public:
    generator(int, int, budget &);
    void move();
    void fire(bool);
};

class tanker : public war_equipment
{
public:
    void fire(bool);
    tanker(int, int, bool, budget &);
    void move();
   
};

class landMG : public war_equipment
{
public:
    landMG(int, int, budget &);
    void move();
    void fire(bool);
    void fire_bullet(bool);
};

class landmine : public war_equipment
{
    int k{0};

public:
    landmine(int, int, budget &);
    void move();
    void fire(bool);
};

class turret : public war_equipment
{
public:
    turret(int, int, budget &);
    void move();
    void fire(bool);
};

class thunder : public war_equipment
{
public:
    thunder(int, int, bool, budget &);
    void move();
    void fire(bool);
};

