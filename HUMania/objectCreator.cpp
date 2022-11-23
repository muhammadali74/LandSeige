
#include "war_equipment.hpp"
#pragma once

class ObjectCreator
{
    public:
    war_equipment* getObject(int x, int y)
    {
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
};