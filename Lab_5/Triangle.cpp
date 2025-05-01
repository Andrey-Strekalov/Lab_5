///////////////////////////////////////////////////////////
// Triangle.cpp
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Triangle.h"

int Triangle::count = 0;

Triangle::Triangle(Point _v1, Point _v2, Point _v3, const std::string& ident)
    : v1(_v1), v2(_v2), v3(_v3), objID(ident) {

    std::ostringstream oss;
    oss << "Треугольник " << ++count;
    name = oss.str();

    CalculateSides();
    std::cout << "Constructor_1 for: " << objID
        << " (" << name << ")\n";
}

Triangle::Triangle(const std::string& ident) : objID(ident) {
    std::ostringstream oss;
    oss << "Треугольник " << ++count;
    name = oss.str();

    a = b = c = 0.0;
    std::cout << "Constructor_2 for: " << objID
        << " (" << name << ")\n";
}

Triangle::~Triangle() {
    std::cout << "Destructor for: " << objID << std::endl;
}

void Triangle::CalculateSides() {
    a = hypot(v1.x - v2.x, v1.y - v2.y);
    b = hypot(v2.x - v3.x, v2.y - v3.y);
    c = hypot(v1.x - v3.x, v1.y - v3.y);
}

void Triangle::Show() const {
    std::cout << name << ":";
    v1.Show();
    v2.Show();
    v3.Show();
    std::cout << std::endl;
}

void Triangle::ShowSideAndArea() const {
    const double p = (a + b + c) / 2.0;
    const double s = sqrt(p * (p - a) * (p - b) * (p - c));

    std::cout << " ---------------------- \n"
        << name << ":"
        << std::fixed << std::setprecision(4)
        << " a= " << std::setw(5) << a
        << ", b= " << std::setw(5) << b
        << ", c= " << std::setw(5) << c
        << ";\ts= " << s << std::endl;
}

