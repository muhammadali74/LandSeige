
#include "war_equipment.hpp"
#pragma once

class ObjectCreator
{
    const int rows = 4, cols = 7;
    // char *grid = new char[rows * cols];
    const int width = 1440, height = 600;
    int xbox = width / cols;
    int ybox = height / rows;

public:
    war_equipment *getObject(int x, int y)
    {
        int colNum = (x / xbox);
        int rowNum = (y / ybox) + 1;
        int x_axis = colNum;
        int y_axis = rowNum;
        int random{(rand() % 6)};
        // if ( random == 0)
        // {
        //     return new Pigeon{x,y};
        // }
        // else if (random == 1)
        // {
        //     return new butterfly{x,y};
        // }
    }

    war_equipment *getObject(int x, int y, int key)
    {
        int colNum = (x / xbox) + 1;
        int rowNum = (y / ybox) + 1;
        int x_axis = colNum * xbox;
        int y_axis = rowNum * ybox;

        if (key == 1)
        {
            // return new generator{x_axis, y_axis};
            cout << x_axis << " " << y_axis;
        }
        else if (key == 2)
        {
            // return new turret{x_axis, y_axis};
            cout << x_axis, y_axis;
        }
        else if (key == 3)
        {
            // return new landmine{x_axis, y_axis};
            cout << x_axis, y_axis;
        }
        else if (key == 4)
        {
            // return new tank{x_axis, y_axis};
            cout << x_axis, y_axis;
        }
        else if (key == 5)
        {
            // return new thunder{x_axis, y_axis};
            cout << x_axis, y_axis;
        }
        else if (key == 6)
        {
            // return new landMG{x_axis, y_axis};
            cout << x_axis, y_axis;
        }
    }
};