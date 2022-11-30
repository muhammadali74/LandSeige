#include "budget.hpp"

using namespace std;

budget::budget() // constructor
{
    amount = 1000;
    cout << "budget initilaized" << endl;
}

int budget::getbudget()
{
    cout << "Your budget is: " << amount << endl;
    return amount;
}

void budget::increasebudget(int ptc) // overload em 
{
    amount += ptc;
    cout << "Your budget is increased to: " << amount << endl;
}

void budget::decreasebudget(int ptc)
{
    amount -= ptc;
    cout << "Your budget is decreased to: " << amount << endl;
}

bool budget::has_budget(int price) {
    if (amount >= price)
    {
        return true;
    }
    else
    {
        return false;
    }
}