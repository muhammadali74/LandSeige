#include "budget.hpp"

using namespace std;

budget::budget() // constructor
{
    amount = 1001;
    cout << "budget initilaized" << endl;
}

char *budget::getbudget_4()
{
    cout << "Your budget is: " << amount << endl;
    // if (amount == 0)
    // {
    //     char arr[] = "0";
    //     return arr;
    // }

    int m = amount;
    int n = amount;
    int digit = 0;
    while (m)
    {
        digit++;
        m /= 10;
    }

    // Declare char array for result
    char *arr = new char[digit + 1];

    int temp = 0;
    for (int i = digit - 1; i >= 0; i--)
    {
        temp = n % 10;
        n /= 10;
        arr[i] = char(temp + 48);
    }

    arr[digit] = '\0';

        // Return char array
    return arr;
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

bool budget::has_budget(int price)
{
    if (amount >= price)
    {
        return true;
    }
    else
    {
        return false;
    }
}