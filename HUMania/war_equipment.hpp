#include "SDL.h"
#pragma once
#include "ammunition.hpp"
using namespace std;
#include <iostream>
class war_equipment
{
protected:
    SDL_Rect srcRect, moverRect;
    int health, price, ammunition_capacity;
    bool friend_or_foe;

public:
    war_equipment(int x, int y);
    // ~war_equipment();
    void draw();
    virtual void move() = 0;
    bool is_destroyed();
    void health_change(int impact); // this is to delete bee when it exits the screen
};

class generator: public war_equipment
{ 
    public:
    generator(int, int);
    void move();
};
// class thunder: public war_equipment
// {
<<<<<<< Updated upstream
<<<<<<< Updated upstream
//     public:

=======
=======
>>>>>>> Stashed changes
//     thunder()
//     {
//         // srcRect = {}
//         health = 450;
//         price = 1000;
//     };
<<<<<<< Updated upstream
>>>>>>> Stashed changes
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
<<<<<<< Updated upstream
class tanker: public war_equipment
{
    public:
    tanker(int, int, bool);
    void move();
};
class landMG: public war_equipment
{
    public:
    landMG(int, int);
    void move();
};
class landmine: public war_equipment
{
    public:
    landmine(int, int);
    void move();
};
class turret: public war_equipment
{
    public:
    turret(int, int);
    void move();
};
=======
=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
// };
>>>>>>> Stashed changes
=======
// };
>>>>>>> Stashed changes
