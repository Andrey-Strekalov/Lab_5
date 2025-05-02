///////////////////////////////////////////////////////////
// Point.cpp
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Triangle.h"

// Конструктор точки с заданными координатами
Point::Point(double x, double y) : x(x), y(y) {}

// Вывод координат точки в консоль
void Point::Show() const {
	std::cout << " (" << x << ", " << y << ")";
}

// Оператор += для перемещения точки
void Point::operator +=(const Point& p) {
	x += p.x;
	y += p.y;
}

// Оператор + для сложения координат точек
Point Point::operator +(const Point& p) const {
	return Point(x + p.x, y + p.y);
}

// Оператор - для вычитания координат точек
Point Point::operator -(const Point& p) const {
	return Point(x - p.x, y - p.y);
}

// Вычисление длины вектора от начала координат
double Point::Length() const {
	return sqrt(x * x + y * y);
}

// Классификация положения точки относительно вектора
ORIENT Point::Classify(const Point& beg_p, const Point& end_p) const {
	Point p0 = *this;
	Point a = end_p - beg_p;  // Вектор AB
	Point b = p0 - beg_p;     // Вектор AP

	// Вычисление векторного произведения
	double sa = a.x * b.y - b.x * a.y;

	// Определение положения точки
	if (sa > 0.0) return LEFT;
	if (sa < 0.0) return RIGHT;
	if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND;
	if (a.Length() < b.Length()) return AHEAD;
	return BETWEEN;
}

// Проверка, находится ли точка внутри треугольника
bool Point::InTriangle(const Triangle& tria) const {
	// Проверка положения точки относительно всех сторон треугольника
	ORIENT or1 = Classify(tria.Get_v1(), tria.Get_v2());
	ORIENT or2 = Classify(tria.Get_v2(), tria.Get_v3());
	ORIENT or3 = Classify(tria.Get_v3(), tria.Get_v1());

	// Точка внутри, если она справа или на грани всех сторон
	return ((or1 == RIGHT || or1 == BETWEEN) &&
		(or2 == RIGHT || or2 == BETWEEN) &&
		(or3 == RIGHT || or3 == BETWEEN));
}