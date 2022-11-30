#include <iostream>
#include "LandSeige.hpp"
#pragma once
void LandSeige::drawObjects()
{
    // call draw functions of all the objects here
    for (int i{0}; i < user.size(); i++)
    {
        user[i]->move();
        user[i]->draw();

        user[i]->fire();

        if (user[i]->is_destroyed() == true)
        {
            delete user[i];
            user.erase(user.begin() + i);
            cout << "object of the bee that exited the screen has been destroyed" << endl;
        }
    }
    if (enemy.size() > 0)
    {
        for (int i{0}; i < enemy.size(); i++)
        {
            enemy[i]->draw();
            enemy[i]->move();

            if (enemy[i]->is_destroyed() == true) // checks if the bee hits the screen exit
            {
                delete enemy[i];                // deletes the bee, and the pointer becomes in a dangling state
                enemy.erase(enemy.begin() + i); // erases that dangling pointer after freeing the memory
                cout << "object of the bee that exited the screen has been destroyed" << endl;
            }
        }
    }
}

// creates new objects
void LandSeige::createEnemyEquipment()
{
    // this allows random generaion of the bee, butterfly or pigeon

    int rtm = rand() % 5;

    if (rtm <= 3)
    {
        enemy.push_back(objCreator.getObject(cash));
        cout << "enemy created" << endl;
    }
    // rtm++;
    // std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void LandSeige::createUserEquipment(int x, int y)
{
    int key = keypress.back();
    keypress.pop_back();
    war_equipment *temp = objCreator.getObject(x, y, key, cash);
    if (temp != nullptr)
    {
        user.push_back(temp);
    }
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
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