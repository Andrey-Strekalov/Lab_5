#ifndef FIGURE_H
#define FIGURE_H

#include <string>

// Абстрактный базовый класс для геометрических фигур
class Figure {
public:
    Figure(const std::string& id);  // Конструктор с идентификатором
    virtual ~Figure() = default;   // Виртуальный деструктор

    // Чисто виртуальные методы (должны быть реализованы в производных классах)
    virtual double area() const = 0;       // Вычисление площади
    virtual void move(double dx, double dy) = 0; // Перемещение фигуры
    virtual void show() const = 0;         // Отображение информации о фигуре
    virtual std::string type() const = 0;  // Получение типа фигуры

    // Методы для работы с идентификатором
    std::string getId() const;      // Получение идентификатора фигуры
    int compare(const Figure* other) const; // Сравнение фигур по площади

protected:
    std::string id;  // Уникальный идентификатор фигуры
};

#endif