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
    vector<war_equipment *> enemy; //this stores all the randomly generated equipment
    vector<war_equipment *> user;  //this stores all the equipment bought by the user
    budget cash; //it is the budget of the user
    ProgressBar progressbar; //used for loading the progress which is in the down corner of the screen
    WeaponSelector weaponSelector{}; //to create  agreen box around the selected equipment when a key is pressed
    Reloader reloaders[6]; //animation to indicate if the object is loaded or not and can be deployed or not
    bool Win{false}; //used to change screens 
    bool Lose{false}; //used to change the screens
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