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
    char *getbudget_4();
    int getbudget();
    void increasebudget(int);
    void decreasebudget(int);
    bool has_budget(int);
    void operator+(int money)
    {
        amount += money;
    }
    void operator-(int money)
    {
        amount -= money;
        cout << "sub" << endl;
    }
    // friend class LandSeige;
};
