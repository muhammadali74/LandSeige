#include "war_equipment.hpp"
#pragma once
#include <vector>

class ObjectCreator
{
    bool occupied[4][7];
    const float rows = 5.25, cols = 7.5;
    // char *grid = new char[rows * cols];
    const float width = 1440, height = 810;
    float xbox = width / cols;
    float ybox = height / rows;

public:
    war_equipment *getObject(budget &b)
    {
        // int colNum = (x / xbox) + 0.72;
        // int rowNum = (y / ybox) + 0.2;
        int colNum = (rand() % 7) + 1;
        int rowNum{(rand() % 4) + 1};
        int random{(rand() % 2)};

        // int x_axis = colNum * xbox - 155;
        int x_axis = 1442;
        int y_axis = rowNum * ybox - 41;

        if (random == 0)
        {
            return new tanker{x_axis, y_axis, false, b};
        }
        else if (random == 1)
        {
            return new thunder{x_axis, y_axis, false, b};
        }
    }

    war_equipment *getObject(int x, int y, int key, budget &cash)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        int x_axis = colNum * xbox - 155;
        int y_axis = rowNum * ybox - 41;
        cout << colNum << " " << rowNum << endl;

        if (occupied[rowNum - 1][colNum - 1] == false)
        {

            if (key == 1)
            {
                cout << colNum << " " << rowNum << endl;
                cout << x_axis << " " << y_axis;

                if (cash.has_budget(300) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new generator{x_axis, y_axis, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }
            }
            else if (key == 2)
            {

                if (cash.has_budget(300) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new turret{x_axis, y_axis, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }

                cout << x_axis, y_axis;
            }
            else if (key == 3)
            {

                if (cash.has_budget(200) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new landmine{x_axis, y_axis, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }
                cout << x_axis, y_axis;
            }
            else if (key == 4)
            {
                if (cash.has_budget(800) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new tanker{x_axis, y_axis, true, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }
                cout << x_axis, y_axis;
            }
            else if (key == 5)
            {
                if (cash.has_budget(1000) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new thunder{x_axis, y_axis, true, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }
                cout << x_axis, y_axis;
            }
            else if (key == 6)
            {
                if (cash.has_budget(600) == true)
                {
                    occupied[rowNum - 1][colNum - 1] = true;
                    return new landMG{x_axis, y_axis, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this" << endl;
                    return nullptr;
                }
                cout << x_axis, y_axis;
            }
        }
        else
        {
            return nullptr;
        }
    }
};