#pragma once

#include <iostream>
#include "vehicle.h"

class Boat : virtual public Vehicle
{
public:
    Boat()
    {
        std::cout << "Creating boat" << std::endl;
    }

    ~Boat()
    {
        std::cout << "Boat d-tor" << std::endl;
    }

    void print()
    {
        std::cout << "I'm a boat" << std::endl;
    }
};