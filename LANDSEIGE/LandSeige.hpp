#include <SDL.h>
#include "budget.hpp"
#include "war_equipment.hpp"
#include "ammunition.hpp"
#include "objectCreator.cpp"
#include "progressbar.cpp"
#include "WeaponSelector.cpp"
#include "reloader.cpp"
#include <vector>
#include <list>
using namespace std;
#pragma once

#define play_time 300000

class LandSeige
{
    ObjectCreator &objCreator{ObjectCreator::get_instance()}; //toensure just one objectcreator is created
    ;
    vector<war_equipment *> enemy;
    vector<war_equipment *> user;
    budget cash;
    ProgressBar progressbar;
    WeaponSelector weaponSelector{};
    Reloader reloaders[6];
    bool Win{false};
    bool Lose{false};
    Uint64 init_time;

public:
    vector<int> keypress;
    int keypressed = 0;
    bool shot = false;
    bool hit = false;
    bool destroy = false;

    ~LandSeige();
    LandSeige();
    void drawObjects();
    void createUserEquipment(int, int);
    void createEnemyEquipment();
    bool has_budget(int price);
    bool has_won();
    bool has_lost();
    void Remove_equipment(int, int);
    void handleprogress(); //progress bar
    void handlereloader(); //loading animation
    void DrawText(const char *msg);
    
};