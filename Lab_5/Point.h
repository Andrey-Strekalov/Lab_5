///////////////////////////////////////////////////////////
// Point.h
#ifndef POINT_H
#define POINT_H

// Перечисление для позиционирования точки
enum ORIENT { LEFT, RIGHT, AHEAD, BEHIND, BETWEEN };
class Triangle;

class Point {
public:
	Point(double x = 0.0, double y = 0.0);
	void Show() const; // Вывод координат

	// Операторы для работы с точками
	void operator +=(const Point& p);
	Point operator +(const Point& p) const;
	Point operator -(const Point& p) const;

	double Length() const; // Длина вектора от начала координат
	ORIENT Classify(const Point& beg_p, const Point& end_p) const; // Классификация положения
	bool InTriangle(const Triangle& tria) const; // Проверка нахождения в треугольнике

	double x, y; // Координаты точки
};

#endif // POINT_H
