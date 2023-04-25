#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "vehicle.h"
#include "car.h"
#include "pump.h"
#include "wheel.h"
#include "bike.h"
#include "boat.h"
#include "amphicar.h"

int main(int argc, char const *argv[])
{
    Vehicle *car = new Car();
    Vehicle *bike = new Bike();
    car->print();
    bike->print();
    delete car;
    delete bike;

    Vehicle *amphicar = new Amphicar();
    amphicar->print();
    delete amphicar;

    return 0;
}
