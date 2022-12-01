#include "war_equipment.hpp"
#pragma once
#include <vector>

#define l1 5000
#define l2 7000
#define l3 9000
#define l4 11000
#define l5 13000

class ObjectCreator
{
    bool occupied[5][8];
    const float rows = 5.25, cols = 7.5;
    // char *grid = new char[rows * cols];
    const float width = 1440, height = 810;
    float xbox = width / cols;
    float ybox = height / rows;
    int row1 = 0;
    int row2 = 0;
    int row3 = 0;
    int row4 = 0;
    bool e1, e2, e3, e4, e5, e6;
    int t1{0}, t2{0}, t3{0}, t4{0}, t5{0}, t6{0};

public:
    ObjectCreator()
    {

        for (int i = 1; i < 5; i++)
        {
            for (int j = 1; j < 8; j++)
            {
                occupied[i][j] = false;
            }
        }
    };
    war_equipment *getObject(budget &b)
    {
        // int colNum = (x / xbox) + 0.72;
        // int rowNum = (y / ybox) + 0.2;
        int colNum = (rand() % 7) + 1;
        int rowNum{(rand() % 4) + 1};
        int random{(rand() % 2)};
        if (rowNum == 1)
        {
            cout << "added to row1" << row1 << endl;
            row1++;
        }
        else if (rowNum == 2)
        {
            cout << "added to row2" << row2 << endl;
            row2++;
        }
        else if (rowNum == 3)
        {
            cout << "added to row3" << row3 << endl;
            row3++;
        }
        else if (rowNum == 4)
        {
            cout << "added to row4" << row4 << endl;
            row4++;
        }

        // int x_axis = colNum * xbox - 155;
        int x_axis = 1400;
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

        if (occupied[rowNum][colNum] == false)
        {

            if (key == 1)
            {

                cout << colNum << " " << rowNum << endl;
                cout << x_axis << " " << y_axis;

                if (cash.has_budget(300) == true && (SDL_GetTicks() - t1 >= l1))
                {
                    occupied[rowNum][colNum] = true;
                    t1 = SDL_GetTicks();
                    return new generator{x_axis, y_axis, cash};
                }
                else
                {
                    cout << "You don't have enough money to buy this or the item hasnt reloaded yet" << endl;
                    return nullptr;
                }
            }
            else if (key == 2)
            {

                if (cash.has_budget(300) == true && (SDL_GetTicks() - t2 >= l2))
                {
                    occupied[rowNum][colNum] = true;
                    t2 = SDL_GetTicks();
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

                if (cash.has_budget(200) == true && (SDL_GetTicks() - t3 >= l3))
                {
                    occupied[rowNum][colNum] = true;
                    t3 = SDL_GetTicks();
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
                if (cash.has_budget(800) == true && (SDL_GetTicks() - t4 >= l4))
                {
                    occupied[rowNum][colNum] = true;
                    t4 = SDL_GetTicks();
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
                if (cash.has_budget(1000) == true && (SDL_GetTicks() - t5 >= l5))
                {
                    occupied[rowNum][colNum] = true;
                    t5 = SDL_GetTicks();
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
                if (cash.has_budget(600) == true && (SDL_GetTicks() - t6 >= l5))
                {
                    occupied[rowNum][colNum] = true;
                    t6 = SDL_GetTicks();
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

    void free_grid(int x, int y)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        occupied[rowNum + 1][colNum] = false;
        cout << " grid is freed" << endl;
    }

    void free_grid2(int x, int y)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        occupied[rowNum + 1][colNum + 1] = false;
        cout << " grid is freed" << rowNum << colNum << endl;
    }

    bool check_grid(int x, int y)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        // cout << colNum << " " << rowNum << endl;
        // cout << "occupied?" << endl;
        if (occupied[rowNum + 1][colNum] == false)
        {
            return false;
        }
        else
        {
            occupied[rowNum + 1][colNum + 1] = true;
            return true;
        }
    }

    void set_grid_false(int x, int y)
    {
        int colNum = (x / xbox) + 0.72;
        int rowNum = (y / ybox) + 0.2;
        occupied[rowNum + 1][colNum + 1] = false;
    }

    bool should_fire(int y)
    {
        int rowNum = (y / ybox) + 0.2;
        // cout << "row num is" << rowNum << endl;
        rowNum++;
        if (rowNum == 1)
        {
            if (row1 > 0)
            {
                // cout << "fire in row1" << endl;
                return true;
            }
        }
        else if (rowNum == 2)
        {
            if (row2 > 0)
            {
                // cout << "fire in row2" << endl;
                return true;
            }
        }
        else if (rowNum == 3)
        {
            if (row3 > 0)
            {
                // cout << "fire in row3" << endl;
                return true;
            }
        }
        else if (rowNum == 4)
        {
            if (row4 > 0)
            {
                // cout << "fire in row4" << endl;
                return true;
            }
        }
        return false;
    }

    void set_row(int y)
    {
        int rowNum = (y / ybox) + 0.2;
        rowNum++;
        if (rowNum == 1)
        {
            cout << "decreased in row1" << endl;
            row1--;
        }
        else if (rowNum == 2)
        {
            cout << "decreased in row2" << endl;
            row2--;
        }
        else if (rowNum == 3)
        {
            cout << "decreased in row3" << endl;
            row3--;
        }
        else if (rowNum == 4)
        {
            cout << "decreased in row4" << endl;
            row4--;
        }
    }

    int get_creation_time(int s)
    {
        if (s == 1)
        {
            return t1;
        }
        else if (s == 2)
        {
            return t2;
        }
        else if (s == 3)
        {
            return t3;
        }
        else if (s == 4)
        {
            return t4;
        }
        else if (s == 5)
        {
            return t5;
        }
        else if (s == 6)
        {
            return t6;
        }
    }
};