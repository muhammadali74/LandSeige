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
    bool has_budget(int);
    void operator+(int money)  //when generator creates money the budget needs to be increased
    {
        amount += money;
    }
    void operator-(int money) //when user buys an equipment then the budget needs to be decreased
    {
        amount -= money;
        cout << "sub" << endl;
    }
};
