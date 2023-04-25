#pragma once

#include "wheel.h"
#include "vehicle.h"
#include <cmath>

class Car : virtual public Vehicle
{
public:
    friend class Wheel;
    enum class Color
    {
        Red,
        Blue,
        White,
        Black
    };

private:
    Color color;
    int weight;
    std::string model;
    double liniarVelocity;
    double angularVelocity;
    Wheel *flwheel;
    Wheel *frwheel;
    Wheel *rlwheel;
    Wheel *rrwheel;

public:
    // default constructer
    Car() : color(Color::Red), weight(0), model(""), liniarVelocity(0), angularVelocity(0),
            flwheel(new Wheel(0)), frwheel(new Wheel(0)), rlwheel(new Wheel(0)), rrwheel(new Wheel(0))
    {
        std::cout << "Creating default car" << std::endl;
    }

    // copy constructer
    Car(const Car &other)
        : angularVelocity(other.angularVelocity), liniarVelocity(other.liniarVelocity), color(other.color),
          weight(other.weight), model(other.model)
    {
        flwheel = new Wheel(*(other.flwheel));
        frwheel = new Wheel(*(other.frwheel));
        rlwheel = new Wheel(*(other.rlwheel));
        rrwheel = new Wheel(*(other.rrwheel));
        std::cout << "Creating copy, with copy constructor of car model: " << other.model << std::endl;
    }

    // desctructor
    ~Car()
    {
        delete flwheel;
        delete frwheel;
        delete rlwheel;
        delete rrwheel;
        std::cout << "Car d-tor" << std::endl;
    }

    // assigment constructor
    Car &operator=(const Car &other)
    {
        if (this != &other)
        {
            delete flwheel;
            delete frwheel;
            delete rlwheel;
            delete rrwheel;

            angularVelocity = other.angularVelocity;
            liniarVelocity = other.liniarVelocity;
            color = other.color;
            weight = other.weight;
            model = other.model;

            flwheel = new Wheel(*(other.flwheel));
            frwheel = new Wheel(*(other.frwheel));
            rlwheel = new Wheel(*(other.rlwheel));
            rrwheel = new Wheel(*(other.rrwheel));
            std::cout << "Copying car with assigment operator of car model: " << other.model << std::endl;
        }
        return *this;
    }

    // move constructor
    Car(Car &&other) noexcept
        : color(other.color), weight(other.weight), model(std::move(other.model)), liniarVelocity(other.liniarVelocity), angularVelocity(other.angularVelocity),
          flwheel(other.flwheel), frwheel(other.frwheel), rlwheel(other.rlwheel), rrwheel(other.rrwheel)
    {
        other.flwheel = nullptr;
        other.frwheel = nullptr;
        other.rlwheel = nullptr;
        other.rrwheel = nullptr;
        std::cout << "Invoking move constructor! Moving car model: " << model << std::endl;
    }

    // move assignment operator
    Car &operator=(Car &&other) noexcept
    {
        if (this != &other)
        {
            delete flwheel;
            delete frwheel;
            delete rlwheel;
            delete rrwheel;

            color = other.color;
            weight = other.weight;
            model = std::move(other.model);
            liniarVelocity = other.liniarVelocity;
            angularVelocity = other.angularVelocity;
            flwheel = other.flwheel;
            frwheel = other.frwheel;
            rlwheel = other.rlwheel;
            rrwheel = other.rrwheel;

            other.flwheel = nullptr;
            other.frwheel = nullptr;
            other.rlwheel = nullptr;
            other.rrwheel = nullptr;
            std::cout << "Invoking MoveAssigmentOperator! Moving car model: " << model << std::endl;
        }
        return *this;
    }

    // none default constructor
    Car(Color color)
        : color(color), angularVelocity(0), liniarVelocity(0), weight(0), model(""),
          flwheel(new Wheel(0)), frwheel(new Wheel(0)), rlwheel(new Wheel(0)), rrwheel(new Wheel(0))
    {
        std::cout << "Creating car with non-default constructor." << std::endl;
    }

    void setModelName(std::string modelName)
    {
        model = modelName;
    }

    std::string getModelName() const
    {
        return model;
    }

    std::string getColor() const
    {
        std::string colorTemp;
        switch (color)
        {
        case Color::Red:
            colorTemp = "Red";
            return colorTemp;
        case Color::White:
            colorTemp = "White";
            break;
        case Color::Black:
            colorTemp = "Black";
            break;
        case Color::Blue:
            colorTemp = "Blue";
            break;
        default:
            break;
        }
        return colorTemp;
    }

    void setWheelRadius(double radius)
    {
        flwheel->radius = radius;
        frwheel->radius = radius;
        rlwheel->radius = radius;
        rrwheel->radius = radius;
    }

    void setWeight(double weight)
    {
        this->weight = weight;
    }

    double getWeight() const
    {
        return weight;
    }

    void setSpeed(double speed)
    {
        double RPM = speed / (2 * flwheel->radius * M_PI);
        flwheel->setRpm(RPM);
        frwheel->setRpm(RPM);
        rlwheel->setRpm(RPM);
        rrwheel->setRpm(RPM);
        liniarVelocity = speed;
    }

    void setTurningAngle(double angle)
    {
        flwheel->setAngle(angle);
        frwheel->setAngle(angle);
        rlwheel->setAngle(angle);
        rrwheel->setAngle(angle);
        angularVelocity = angle;
    }

    void print()
    {
        std::cout << "I'm a car" << std::endl;
    }

    void printWheelInfo()
    {
        std::cout << "FrontLeft-> RPM: " << flwheel->getRpm() << " Angle: " << flwheel->angle << std::endl;
        std::cout << "FrontRight-> RPM: " << frwheel->getRpm() << " Angle: " << frwheel->angle << std::endl;
        std::cout << "RearLeft-> RPM: " << rlwheel->getRpm() << " Angle: " << rlwheel->angle << std::endl;
        std::cout << "RearRight-> RPM: " << rrwheel->getRpm() << " Angle: " << rrwheel->angle << std::endl;
    }
};