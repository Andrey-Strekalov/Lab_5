
///////////////////////////////////////////////////////////
// Triangle.h
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
#include <string>

class Triangle {
public:
	// Конструкторы
	Triangle(Point v1, Point v2, Point v3, const std::string& ident);
	Triangle(const std::string& ident);

	// Дружественная функция для проверки включения
	friend bool TriaInTria(Triangle t1, Triangle t2);

	~Triangle(); // Деструктор

	// Методы доступа
	Point Get_v1() const { return v1; }
	Point Get_v2() const { return v2; }
	Point Get_v3() const { return v3; }
	const char* GetName() const { return name.c_str(); }

	// Оператор сравнения по площади
	bool operator >(const Triangle& tria) const;

	void Show() const; // Отображение информации
	void Move(Point dp); // Перемещение треугольника

	static int count; // Счетчик созданных объектов

private:
	void CalculateSides(); // Вычисление длин сторон

	std::string objID; // Идентификатор объекта
	std::string name;  // Название треугольника
	Point v1, v2, v3; // Вершины треугольника
	double a, b, c;    // Длины сторон
};

#endif // TRIANGLE_H
