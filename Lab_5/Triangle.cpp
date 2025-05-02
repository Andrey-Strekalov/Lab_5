
///////////////////////////////////////////////////////////
// Triangle.cpp
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include "Triangle.h"

int Triangle::count = 0; // Инициализация статического счетчика

// Конструктор с вершинами
Triangle::Triangle(Point _v1, Point _v2, Point _v3, const std::string& ident)
	: v1(_v1), v2(_v2), v3(_v3), objID(ident)
{
	// Генерация уникального имени
	std::ostringstream oss;
	oss << "Треугольник " << ++count;
	name = oss.str();

	CalculateSides(); // Рассчет длин сторон
	std::cout << "Constructor_1 for: " << objID << " (" << name << ")\n";
}

// Конструктор пустого треугольника
Triangle::Triangle(const std::string& ident) : objID(ident)
{
	std::ostringstream oss;
	oss << "Треугольник " << ++count;
	name = oss.str();
	a = b = c = 0.0;
	std::cout << "Constructor_2 for: " << objID << " (" << name << ")\n";
}

// Деструктор
Triangle::~Triangle() {
	std::cout << "Destructor for: " << objID << std::endl;
}

// Расчет длин сторон треугольника
void Triangle::CalculateSides() {
	a = hypot(v1.x - v2.x, v1.y - v2.y);
	b = hypot(v2.x - v3.x, v2.y - v3.y);
	c = hypot(v1.x - v3.x, v1.y - v3.y);
}

// Отображение информации о треугольнике
void Triangle::Show() const {
	std::cout << name << ":";
	v1.Show();
	v2.Show();
	v3.Show();
	std::cout << std::endl;
}

// Перемещение всех вершин треугольника
void Triangle::Move(Point dp) {
	v1 += dp;
	v2 += dp;
	v3 += dp;
}

// Сравнение треугольников по площади
bool Triangle::operator >(const Triangle& tria) const {
	// Расчет площади текущего треугольника
	double p = (a + b + c) / 2;
	double s = sqrt(p * (p - a) * (p - b) * (p - c));

	// Расчет площади сравниваемого треугольника
	double p1 = (tria.a + tria.b + tria.c) / 2;
	double s1 = sqrt(p1 * (p1 - tria.a) * (p1 - tria.b) * (p1 - tria.c));

	return s > s1;
}

// Проверка включения одного треугольника в другой
bool TriaInTria(Triangle trial, Triangle tr1a2) {
	// Проверка всех вершин треугольника
	Point vl = trial.Get_v1();
	Point v2 = trial.Get_v2();
	Point v3 = trial.Get_v3();

	return (vl.InTriangle(tr1a2) &&
		v2.InTriangle(tr1a2) &&
		v3.InTriangle(tr1a2));
}