
///////////////////////////////////////////////////////////
// Triangle.cpp
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Triangle.h"

int Triangle::count = 0; // ������������� ������������ ��������

// ����������� � ���������
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const std::string& ident)
	: v1(_v1), v2(_v2), v3(_v3), objID(ident)
{
	// ��������� ����������� �����
	std::ostringstream oss;
	oss << "����������� " << ++count;
	name = oss.str();

	CalculateSides(); // ������� ���� ������
	std::cout << "Constructor_1 for: " << objID << " (" << name << ")\n";
}

// ����������� ������� ������������
Triangle::Triangle(const std::string& ident) : objID(ident)
{
	std::ostringstream oss;
	oss << "����������� " << ++count;
	name = oss.str();
	a = b = c = 0.0;
	std::cout << "Constructor_2 for: " << objID << " (" << name << ")\n";
}

// ����������
Triangle::~Triangle() {
	std::cout << "Destructor for: " << objID << std::endl;
}

// ������ ���� ������ ������������
void Triangle::CalculateSides() {
	a = hypot(v1.x - v2.x, v1.y - v2.y);
	b = hypot(v2.x - v3.x, v2.y - v3.y);
	c = hypot(v1.x - v3.x, v1.y - v3.y);
}

// ����������� ���������� � ������������
void Triangle::Show() const {
	std::cout << name << ":";
	v1.Show();
	v2.Show();
	v3.Show();
	std::cout << std::endl;
}

// ����������� ���� ������ ������������
void Triangle::Move(Point dp) {
	v1 += dp;
	v2 += dp;
	v3 += dp;
}

// ��������� ������������� �� �������
bool Triangle::operator >(const Triangle& tria) const {
	// ������ ������� �������� ������������
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	// ������ ������� ������������� ������������
	double p1 = (tria.a + tria.b + tria.c) / 2;
	double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));

	return s > s1;
}

// �������� ��������� ������ ������������ � ������
bool TriaInTria(Triangle trial, Triangle tr1a2) {
	// �������� ���� ������ ������������
	Point vl = trial.Get_v1();
	Point v2 = trial.Get_v2();
	Point v3 = trial.Get_v3();

	return (vl.InTriangle(tr1a2) &&
		v2.InTriangle(tr1a2) &&
		v3.InTriangle(tr1a2));
}