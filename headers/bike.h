#pragma once

#include "vehicle.h"
#include <iostream>

class Bike : public Vehicle
{
public:
    Bike()
    {
        std::cout << "Creating default bike" << std::endl;
    }

    ~Bike()
    {
        std::cout << "Bike d-tor" << std::endl;
    }

    void print()
    {
        std::cout << "I'm a bike" << std::endl;
    }
};