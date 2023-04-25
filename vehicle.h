#pragma once
class Vehicle
{
public:
    Vehicle()
    {
        std::cout << "I'm a vehicle" << std::endl;
    }
    virtual ~Vehicle()
    {
        std::cout << "Vehicle d-tor" << std::endl;
    }

    virtual void print() = 0;
};