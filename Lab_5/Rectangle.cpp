#include "rectangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Реализация методов класса Rectangle

// Конструктор
Rectangle::Rectangle(const std::string& id, double x1, double y1, double x2, double y2)
    : Figure(id), topLeft({ x1, y1 }), bottomRight({ x2, y2 }) {}

// Вычисление площади прямоугольника
double Rectangle::area() const {
    auto [x1, y1] = topLeft;
    auto [x2, y2] = bottomRight;
    return std::fabs((x2 - x1) * (y2 - y1)); // |ширина * высота|
}

// Перемещение прямоугольника
void Rectangle::move(double dx, double dy) {
    topLeft.first += dx;        // Смещение левого верхнего угла по X
    topLeft.second += dy;       // Смещение левого верхнего угла по Y
    bottomRight.first += dx;    // Смещение правого нижнего угла по X
    bottomRight.second += dy;   // Смещение правого нижнего угла по Y
}

// Вывод информации о прямоугольнике
void Rectangle::show() const {
    auto [x1, y1] = topLeft;
    auto [x2, y2] = bottomRight;
    std::cout << "Прямоугольник ID: " << id
        << ", Площадь: " << std::fixed << std::setprecision(2) << area()
        << ", Верхний-левый: (" << x1 << ", " << y1 << ")"
        << ", Нижний-правый: (" << x2 << ", " << y2 << ")"
        << std::endl;
}

// Возвращает тип фигуры
std::string Rectangle::type() const {
    return "Прямоугольник";
}