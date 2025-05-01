///////////////////////////////////////////////////////////
// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include <string>

class Triangle {
public:
    Triangle(Point v1, Point v2, Point v3, const std::string& ident);
    Triangle(const std::string& ident);
    ~Triangle();

    Point Get_v1() const { return v1; }
    Point Get_v2() const { return v2; }
    Point Get_v3() const { return v3; }
    const char* GetName() const { return name.c_str(); }

    void Show() const;
    void ShowSideAndArea() const;

    static int count;

private:
    void CalculateSides();

    std::string objID;
    std::string name;
    Point v1, v2, v3;
    double a, b, c;
};

#endif // TRIANGLE_H

