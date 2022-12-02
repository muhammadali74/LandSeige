#include "progressbar.cpp"
#pragma once

using namespace std;
#include <iostream>

class WeaponSelector : public ProgressBar

{

public:
    WeaponSelector()
    {
        srcRect = {235, 395, 204, 141};
        destRect = {176, 10, 0, 0};
        cout << "selcetor made" << endl;
    }

    void select_current(int key)
    {
        if (key == 1)
        {
            destRect = {175, 10, 152, 100};
        }
        else if (key == 2)
        {
            destRect = {343, 10, 152, 100};
        }
        else if (key == 3)
        {
            destRect = {510, 10, 152, 100};
        }
        else if (key == 4)
        {
            destRect = {674, 10, 152, 100};
        }
        else if (key == 5)
        {
            destRect = {839, 10, 152, 100};
        }
        else if (key == 6)
        {
            destRect = {1000, 10, 152, 100};
        }
        else
        {
            destRect = {0, 0, 0, 0};
        }
    }
};
