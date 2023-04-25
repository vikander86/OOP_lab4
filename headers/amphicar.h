#pragma once

#include <iostream>
#include "boat.h"
#include "car.h"

class Amphicar : public Boat, public Car
{
public:
    Amphicar()
    {
        std::cout << "Creating Amphicar" << std::endl;
    }

    ~Amphicar()
    {
        std::cout << "Amphicar d-tor" << std::endl;
    }

    void print()
    {
        std::cout << "I'm both a boat and a car" << std::endl;
    }
};