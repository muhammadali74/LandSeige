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

public:
    virtual void destruction();
    string name = "else";
    Uint64 creation_time = SDL_GetTicks();
    war_equipment(int x, int y);
    // ~war_equipment();
    void draw();
    virtual void move() = 0;
    virtual void fire(bool);
    virtual void fire_bullet(bool);
    bool is_destroyed();
    void health_change(int impact); // this is to delete bee when it exits the screen
    vector<ammunition *> &get_ammunition();
    SDL_Rect get_moverRect() const;
};

class generator : public war_equipment
{
    budget *cashmod = nullptr;

public:
    generator(int, int, budget &);
    void move();
    void fire(bool);
};
// class thunder: public war_equipment
// {
// <<<<<<< Updated upstream
// <<<<<<< Updated upstream
//     public:

// =======
// =======
// >>>>>>> Stashed changes
// //     thunder()
// //     {
// //         // srcRect = {}
// //         health = 450;
// //         price = 1000;
// //     };
// <<<<<<< Updated upstream
// >>>>>>> Stashed changes
// =======
// >>>>>>> Stashed changes
// };
// class landmine: public war_equipment
// {
//     moverRect =
//     srcRect =
//     health = 100;
//     price = 200;
// };
// class turret: public war_equipment
// {
//     moverRect =
//     srcRect =
//     health = 300;
//     price = 300;
// };
// <<<<<<< Updated upstream
// <<<<<<< Updated upstream
class tanker : public war_equipment
{
public:
    void fire(bool);
    tanker(int, int, bool, budget &);
    void move();
    // void fire();
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
// =======
// =======
// >>>>>>> Stashed changes
// class tanker: public war_equipment
// {
//     moverRect =
//     srcRect =
//     health = 750;
//     price = 800;
// };
// class landMG: public war_equipment
// {
//     moverRect =
//     srcRect =
//     health = 550;
//     price = 600;
// <<<<<<< Updated upstream
// // };
// >>>>>>> Stashed changes
// =======
// // };
// >>>>>>> Stashed changes
