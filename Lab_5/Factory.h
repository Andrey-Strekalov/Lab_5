#ifndef FACTORY_H
#define FACTORY_H

#include "figure.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// Класс-фабрика для управления геометрическими объектами
class Factory {
public:
    // Методы для работы с объектами
    void createTriangle();  // Создание треугольника
    void createRectangle(); // Создание прямоугольника
    void deleteObject(const std::string& id); // Удаление объекта по ID
    void showAll() const;   // Отображение всех объектов
    void moveObject(const std::string& id); // Перемещение объекта
    void compareObjects();  // Сравнение двух объектов по площади

private:
    std::vector<std::unique_ptr<Figure>> figures; // Коллекция объектов

    // Внутренний метод для поиска объекта по ID
    Figure* findObject(const std::string& id) const;
};

#endif