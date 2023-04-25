#pragma once

#include "pump.h"
#include <cmath>

class Wheel
{
    friend class Car;
    friend class Pump;

private:
    double radius;
    double rpm;
    double angle;
    double pressure;

public:
    Wheel(double radius) : radius(radius), rpm(0), angle(0), pressure(0) {}

    ~Wheel() {}

    bool operator==(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne == speedTwo;
    }

    bool operator!=(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne != speedTwo;
    }

    bool operator<(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne < speedTwo;
    }
    bool operator<=(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne <= speedTwo;
    }
    bool operator>(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne > speedTwo;
    }

    bool operator>=(const Wheel &compareToWheel) const
    {
        double speedOne = this->radius * this->rpm * M_PI * 2;
        double speedTwo = compareToWheel.radius * compareToWheel.rpm * M_PI * 2;
        return speedOne >= speedTwo;
    }

    bool setRpm(double newRpm)
    {
        if (newRpm >= 0 && newRpm <= 10000)
        {
            this->rpm = newRpm;
            return true;
        }
        else
        {
            return false;
        }
    }

    double getRpm() const
    {
        return rpm;
    }

    bool setAngle(double newAngle)
    {
        if (newAngle >= 0 && newAngle <= 40)
        {
            this->angle = newAngle;
            return true;
        }
        else
        {
            return false;
        }
    }

    double getAngle()
    {
        return angle;
    }

    double getPressure()
    {
        return pressure;
    }
};
