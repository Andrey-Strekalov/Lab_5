///////////////////////////////////////////////////////////
// Point.cpp
#include <iostream>
#include <cmath>
#include "Point.h"
#include "Triangle.h"

// ����������� ����� � ��������� ������������
Point::Point(double x, double y) : x(x), y(y) {}

// ����� ��������� ����� � �������
void Point::Show() const {
	std::cout << " (" << x << ", " << y << ")";
}

// �������� += ��� ����������� �����
void Point::operator +=(const Point& p) {
	x += p.x;
	y += p.y;
}

// �������� + ��� �������� ��������� �����
Point Point::operator +(const Point& p) const {
	return Point(x + p.x, y + p.y);
}

// �������� - ��� ��������� ��������� �����
Point Point::operator -(const Point& p) const {
	return Point(x - p.x, y - p.y);
}

// ���������� ����� ������� �� ������ ���������
double Point::Length() const {
	return sqrt(x * x + y * y);
}

// ������������� ��������� ����� ������������ �������
ORIENT Point::Classify(const Point& beg_p, const Point& end_p) const {
	Point p0 = *this;
	Point a = end_p - beg_p;  // ������ AB
	Point b = p0 - beg_p;     // ������ AP

	// ���������� ���������� ������������
	double sa = a.x * b.y - b.x * a.y;

	// ����������� ��������� �����
	if (sa > 0.0) return LEFT;
	if (sa < 0.0) return RIGHT;
	if ((a.x * b.x < 0.0) || (a.y * b.y < 0.0)) return BEHIND;
	if (a.Length() < b.Length()) return AHEAD;
	return BETWEEN;
}

// ��������, ��������� �� ����� ������ ������������
bool Point::InTriangle(const Triangle& tria) const {
	// �������� ��������� ����� ������������ ���� ������ ������������
	ORIENT or1 = Classify(tria.Get_v1(), tria.Get_v2());
	ORIENT or2 = Classify(tria.Get_v2(), tria.Get_v3());
	ORIENT or3 = Classify(tria.Get_v3(), tria.Get_v1());

	// ����� ������, ���� ��� ������ ��� �� ����� ���� ������
	return ((or1 == RIGHT || or1 == BETWEEN) &&
		(or2 == RIGHT || or2 == BETWEEN) &&
		(or3 == RIGHT || or3 == BETWEEN));
}