#include "budget.hpp"

using namespace std;

budget::budget() // constructor
{
    amount = 1250; 
    cout << "budget initilaized" << endl;
}

char *budget::getbudget_4()
{   
    if(amount==0)
    {
        char arr[]= "Zero";
        return arr;
    }
    cout << "Your budget is: " << amount << endl;
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