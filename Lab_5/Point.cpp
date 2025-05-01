///////////////////////////////////////////////////////////
// Point.cpp
#include <iostream>
#include "Point.h"

Point::Point(double x, double y) : x(x), y(y) {}

void Point::Show() const {
    std::cout << " (" << x << ", " << y << ")";
}
