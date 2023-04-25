#pragma once
class Pump
{
public:
    void setPressure(Wheel &wheel, double newPressure)
    {
        wheel.pressure = newPressure;
    }
};