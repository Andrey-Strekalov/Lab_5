///////////////////////////////////////////////////////////
// Point.h
#ifndef POINT_H
#define POINT_H

class Point {
public:
    Point(double x = 0.0, double y = 0.0);
    void Show() const;
    double x, y;
};

#endif // POINT_H
