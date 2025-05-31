#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <vector>
#include <utility>

// Класс треугольника (наследник Figure)
class Triangle : public Figure {
public:
    // Конструктор с параметрами вершин
    Triangle(const std::string& id,
        double x1, double y1,
        double x2, double y2,
        double x3, double y3);

    // Реализация виртуальных методов
    double area() const override;      // Вычисление площади треугольника
    void move(double dx, double dy) override; // Перемещение треугольника
    void show() const override;        // Отображение информации
    std::string type() const override; // Возвращает тип фигуры

private:
    std::vector<std::pair<double, double>> vertices; // Координаты вершин
};

#endif