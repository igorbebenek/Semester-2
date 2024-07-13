#pragma once
#include <iostream>
#include <string>

class Discount {
public:
    Discount() : percentage(0.0) {}
    Discount(double p) : percentage(p) {}
    double getPercentage() const { return percentage; }
    void setPercentage(double p) { percentage = p; }

private:
    double percentage;
};
