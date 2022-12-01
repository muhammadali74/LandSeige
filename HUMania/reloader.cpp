#include "progressbar.cpp"
#pragma once

using namespace std;
#include <iostream>

class Reloader : public ProgressBar

{
    float rl_time;

public:
    Reloader() {}

    Reloader(int x, int inc_time)
    {
        srcRect = {408, 2186, 194, 98};
        destRect = {x, 10, 152, 100};
        rl_time = float(inc_time);
    }

    void reload(Uint64 time)
    {
        int t = (float(time) / rl_time) * 100;

        if (t > 0 && t < 20)
        {
            destRect.h = 80;
        }
        else if (t < 40 && t >= 20)
        {
            destRect.h = 60;
            cout << t << endl;
        }
        else if (t >= 40 && t < 60)
        {
            destRect.h = 40;
        }
        else if (t >= 60 && t < 80)
        {
            destRect.h = 20;
        }
        else if (t >= 80 && t < 95)
        {
            destRect.h = 5;
        }
        else
        {
            destRect.h = 0;
        }
    }
};
