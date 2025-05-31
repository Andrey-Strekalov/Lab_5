#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <utility>

// Класс прямоугольника (наследник Figure)
class Rectangle : public Figure {
public:
    // Конструктор с параметрами углов
    Rectangle(const std::string& id,
        double x1, double y1,
        double x2, double y2);

    // Реализация виртуальных методов
    double area() const override;      // Вычисление площади
    void move(double dx, double dy) override; // Перемещение
    void show() const override;        // Отображение информации
    std::string type() const override; // Возвращает тип фигуры

private:
    std::pair<double, double> topLeft;     // Левый верхний угол
    std::pair<double, double> bottomRight; // Правый нижний угол
};

#endif