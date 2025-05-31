#include "factory.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>
#include <memory>
#include <algorithm>

// Реализация методов фабрики

// Создание нового треугольника
void Factory::createTriangle() {
    std::string id;
    std::cout << "Введите ID треугольника: ";
    std::cin >> id;

    // Проверка на уникальность ID
    if (findObject(id)) {
        std::cout << "Ошибка: Объект с таким ID уже существует!\n";
        return;
    }

    // Ввод координат вершин
    double x1, y1, x2, y2, x3, y3;
    std::cout << "Введите вершину 1 (x y): ";
    std::cin >> x1 >> y1;
    std::cout << "Введите вершину 2 (x y): ";
    std::cin >> x2 >> y2;
    std::cout << "Введите вершину 3 (x y): ";
    std::cin >> x3 >> y3;

    // Создание и добавление треугольника
    figures.push_back(std::make_unique<Triangle>(id, x1, y1, x2, y2, x3, y3));
    std::cout << "Треугольник успешно создан!\n";
}

// Создание нового прямоугольника
void Factory::createRectangle() {
    std::string id;
    std::cout << "Введите ID прямоугольника: ";
    std::cin >> id;

    // Проверка на уникальность ID
    if (findObject(id)) {
        std::cout << "Ошибка: Объект с таким ID уже существует!\n";
        return;
    }

    // Ввод координат углов
    double x1, y1, x2, y2;
    std::cout << "Введите верхний-левый угол (x y): ";
    std::cin >> x1 >> y1;
    std::cout << "Введите нижний-правый угол (x y): ";
    std::cin >> x2 >> y2;

    // Создание и добавление прямоугольника
    figures.push_back(std::make_unique<Rectangle>(id, x1, y1, x2, y2));
    std::cout << "Прямоугольник успешно создан!\n";
}

// Удаление объекта по ID
void Factory::deleteObject(const std::string& id) {
    // Поиск и удаление объекта
    auto it = std::remove_if(figures.begin(), figures.end(),
        [&](const auto& obj) { return obj->getId() == id; });

    if (it != figures.end()) {
        figures.erase(it, figures.end()); // Удаление из коллекции
        std::cout << "Объект успешно удален!\n";
    }
    else {
        std::cout << "Ошибка: Объект не найден!\n";
    }
}

// Отображение всех объектов
void Factory::showAll() const {
    if (figures.empty()) {
        std::cout << "В базе данных нет объектов\n";
        return;
    }

    std::cout << "\n--- Все объекты ---\n";
    for (const auto& fig : figures) {
        fig->show(); // Вызов метода show для каждого объекта
    }
    std::cout << "------------------\n";
}

// Перемещение объекта
void Factory::moveObject(const std::string& id) {
    Figure* obj = findObject(id); // Поиск объекта
    if (!obj) {
        std::cout << "Ошибка: Объект не найден!\n";
        return;
    }

    // Ввод вектора перемещения
    double dx, dy;
    std::cout << "Введите вектор перемещения (dx dy): ";
    std::cin >> dx >> dy;

    obj->move(dx, dy); // Вызов метода move
    std::cout << "Объект успешно перемещен!\n";
}

// Сравнение двух объектов по площади
void Factory::compareObjects() {
    std::string id1, id2;
    std::cout << "Введите ID первого объекта: ";
    std::cin >> id1;
    std::cout << "Введите ID второго объекта: ";
    std::cin >> id2;

    // Поиск объектов
    Figure* obj1 = findObject(id1);
    Figure* obj2 = findObject(id2);

    if (!obj1 || !obj2) {
        std::cout << "Ошибка: Один или оба объекта не найдены!\n";
        return;
    }

    // Сравнение объектов
    int result = obj1->compare(obj2);
    std::cout << "Результат сравнения: ";
    if (result == 0) {
        std::cout << "Объекты имеют равную площадь";
    }
    else if (result < 0) {
        std::cout << obj1->getId() << " < " << obj2->getId();
    }
    else {
        std::cout << obj1->getId() << " > " << obj2->getId();
    }
    std::cout << " (" << obj1->type() << " vs " << obj2->type() << ")\n";
}

// Поиск объекта по ID
Figure* Factory::findObject(const std::string& id) const {
    for (const auto& fig : figures) {
        if (fig->getId() == id) {
            return fig.get(); // Возврат указателя на найденный объект
        }
    }
    return nullptr; // Объект не найден
}