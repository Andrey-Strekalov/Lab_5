#include "triangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// Реализация методов класса Triangle

// Конструктор
Triangle::Triangle(const std::string& id, double x1, double y1, double x2, double y2, double x3, double y3)
    : Figure(id) {
    // Инициализация вершин треугольника
    vertices.push_back({ x1, y1 });
    vertices.push_back({ x2, y2 });
    vertices.push_back({ x3, y3 });
}

// Вычисление площади по формуле Гаусса
double Triangle::area() const {
    const auto& [x1, y1] = vertices[0];
    const auto& [x2, y2] = vertices[1];
    const auto& [x3, y3] = vertices[2];

    return 0.5 * std::fabs(
        x1 * (y2 - y3) +
        x2 * (y3 - y1) +
        x3 * (y1 - y2)
    );
}

// Перемещение всех вершин треугольника
void Triangle::move(double dx, double dy) {
    for (auto& vertex : vertices) {
        vertex.first += dx;  // Смещение по X
        vertex.second += dy; // Смещение по Y
    }
}

// Вывод информации о треугольнике
void Triangle::show() const {
    std::cout << "Треугольник ID: " << id
        << ", Площадь: " << std::fixed << std::setprecision(2) << area()
        << ", Вершины: ";
    for (const auto& [x, y] : vertices) {
        std::cout << "(" << x << ", " << y << ") ";
    }
    std::cout << std::endl;
}

// Возвращает тип фигуры
std::string Triangle::type() const {
    return "Треугольник";
}