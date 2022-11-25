#include <SDL.h>
#include "budget.hpp"
#include "war_equipment.hpp"
#include "ammunition.hpp"
#include "objectCreator.cpp"
#include <vector>
#include <list>
using namespace std;
#pragma once

class LandSeige
{

    // Right now we're creating one pigeon, just for practice. for details follow the guidlines
    ObjectCreator objCreator;
    vector<war_equipment *> enemy;
    vector<war_equipment *> user;
    budget cash;

    // Create your list here
public:
    vector<int> keypress;

    ~LandSeige();
    void drawObjects();
    void createUserEquipment(int, int);
    void createEnemyEquipment();
    bool has_budget(int price);
    // create destructor which deletes all dynamic objects
};