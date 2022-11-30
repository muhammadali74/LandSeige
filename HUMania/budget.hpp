#include <iostream>
#pragma once

using namespace std;

class budget
{
protected:
    int amount;
    float bonus;

public:
    budget();
    int getbudget();
    void increasebudget(int);
    void decreasebudget(int);
    bool has_budget(int);
    // friend class LandSeige;
};
