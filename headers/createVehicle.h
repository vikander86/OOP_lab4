#pragma once

#include <iostream>
#include <memory>
#include <string>

// function to create vehicle type objects based on string input
std::unique_ptr<Vehicle> createVehicle(const std::string &vehicleType)
{
    // if "car", return a unique pointer with a Vehicle object of the Car type
    if (vehicleType == "car")
    {
        return std::make_unique<Car>();
    }
    // if "boat", return a unique pointer with a Vehicle object of the Bpat type
    else if (vehicleType == "boat")
    {
        return std::make_unique<Boat>();
    }
    // if "amphicar", return a unique pointer with a Vehicle object of the Amphicar type
    else if (vehicleType == "amphicar")
    {
        return std::make_unique<Amphicar>();
    }
    // if "boat", return a unique pointer with a Vehicle object of the Bike type
    else if (vehicleType == "bike")
    {
        return std::make_unique<Bike>();
    }
    // else return a nullptr
    else
        return nullptr;
}