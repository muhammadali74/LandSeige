#include <iostream>
#pragma once

using namespace std;

class budget
{
protected:
    unsigned int amount;
    float bonus;

public:
    budget();
    char *getbudget_4();
    int getbudget();
    void increasebudget(int);
    void decreasebudget(int);
    bool has_budget(int);

    // friend class LandSeige;
};
