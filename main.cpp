#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>

#include "headers/vehicle.h"
#include "headers/car.h"
#include "headers/pump.h"
#include "headers/wheel.h"
#include "headers/bike.h"
#include "headers/boat.h"
#include "headers/amphicar.h"
#include "headers/createVehicle.h"


int main(int argc, char const *argv[])
{
    // Vehicle *car = new Car();
    // Vehicle *bike = new Bike();
    // car->print();
    // bike->print();
    // delete car;
    // delete bike;

    // Vehicle *amphicar = new Amphicar();
    // amphicar->print();
    // delete amphicar;

    // creating a vector of unique pointers to different type of Vehicle objects
    std::vector<std::unique_ptr<Vehicle>> vehiclesList;

    // initiate file input stream
    std::ifstream File("vehicles.txt");

    // variable to storethe vehicle type read from the input file
    std::string vehicleType;

    // reading file while there's something to read
    while (std::getline(File, vehicleType))
    {
        // creating a vehicle pointer with call to createVehicle function
        std::unique_ptr<Vehicle> vehicle = createVehicle(vehicleType);
        if (vehicle)
        {
            // if return value is not a nullptr, add vehicle to the vector
            vehiclesList.push_back(std::move(vehicle));
        }
    }
    // iterate through vehiclesList and call print function for the Vehicle type.
    for (auto &vehicle : vehiclesList)
    {
        vehicle->print();
    }

    return 0;
}
