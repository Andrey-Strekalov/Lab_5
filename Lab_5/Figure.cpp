#include "figure.h"
#include <cmath>

// Реализация методов базового класса Figure

// Конструктор
Figure::Figure(const std::string& id) : id(id) {}

// Получение идентификатора фигуры
std::string Figure::getId() const {
    return id;
}

// Сравнение двух фигур по площади
int Figure::compare(const Figure* other) const {
    double a1 = area();      // Площадь текущей фигуры
    double a2 = other->area(); // Площадь сравниваемой фигуры

    // Сравнение с учетом погрешности вычислений
    if (std::fabs(a1 - a2) < 1e-9) return 0; // Площади равны
    return (a1 < a2) ? -1 : 1; // -1 если текущая меньше, 1 если больше
}