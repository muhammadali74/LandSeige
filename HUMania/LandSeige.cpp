#include <iostream>
#include "LandSeige.hpp"
#pragma once
void LandSeige::drawObjects()
{
    // call draw functions of all the objects here
    for(int i{0}; i<enemy.size(); i++)
    {
        if (enemy[i]->is_destroyed() == true) //checks if the bee hits the screen exit 
        {
            delete enemy[i]; //deletes the bee, and the pointer becomes in a dangling state
            enemy.erase(enemy.begin() + i); //erases that dangling pointer after freeing the memory
            cout << "object of the bee that exited the screen has been destroyed" << endl;
        }
        enemy[i]->draw();
        enemy[i]->move();
        
    } 
}


// creates new objects 
void LandSeige::createEnemyEquipment(int x, int y)
{
    //this allows random generaion of the bee, butterfly or pigeon
    enemy.push_back(objCreator.getObject(x,y));
    std::cout << "Mouse clicked at: " << x << " -- " << y << std::endl;
}

void LandSeige::createUserEquipment(int x,int y)
{

}
LandSeige::~LandSeige() //this destructor ensures that all the memor that was dynamically allocated is deallocated.
{
    for(int i{0} ; i < enemy.size() ; i++)
    {
        delete enemy[i];
    }
    for(int i{0} ; i < user.size() ; i++)
    {
        delete user[i];
    }
    cout << "destructor called";
}

bool LandSeige::has_budget(int price)
{
    if(cash.amount >= price)
    {
        return true;
    }
    else
    {
        return false;
    }
};