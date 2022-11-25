
#include "war_equipment.hpp"
#pragma once

class ObjectCreator
{
    const float rows = 5.25, cols = 7.5;
    // char *grid = new char[rows * cols];
    const float width = 1440, height = 810;
    float xbox = width / cols;
    float ybox = height / rows;

public:
    war_equipment *getObject()
    {
        // int colNum = (x / xbox) + 0.72;
        // int rowNum = (y / ybox) + 0.2;
        int colNum = (rand() % 7) + 1;
        int rowNum{(rand() % 4) + 1};
        // int x_axis = colNum * xbox - 155;
        int x_axis = 1442;
        int y_axis = rowNum * ybox - 41;

        // if ( random == 0)
        // {
        //     return new enemy1{x_axis,y_axis};
        // }
        // else if (random == 1)
        // {
        //     return new enemy2{x_axis,y_axis};
        // }
    }

    war_equipment *getObject(int x, int y, int key)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        int x_axis = colNum * xbox - 155;
        int y_axis = rowNum * ybox - 41;

        if (key == 1)
        {
            cout << colNum << " " << rowNum << endl;
            cout << x_axis << " " << y_axis;
            return new generator{x_axis, y_axis};
            
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