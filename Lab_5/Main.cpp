///////////////////////////////////////////////////////////
// Main.cpp
#include <iostream>
#include <vector>
#include <limits>
#define NOMINMAX // Отключает макросы min/max
#include <Windows.h>
#include "Triangle.h"

int Menu();
int GetNumber(int min, int max);
void ExitBack();
void Show(const std::vector<Triangle*>& triangles);
void Move(std::vector<Triangle*>& triangles);
void FindMax(const std::vector<Triangle*>& triangles);
void IsIncluded(const std::vector<Triangle*>& triangles);

int main() {
    setlocale(LC_ALL, "ru");
    // меняем кодировку консоли для возможности рускоязычного ввода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Инициализация точек
    Point p1{ 0, 0 }, p2{ 0.5, 1 }, p3{ 1, 0 }, p4{ 0, 4.5 },
        p5{ 2, 1 }, p6{ 2, 0 }, p7{ 2, 2 }, p8{ 3, 0 };

    // Создание треугольников
    std::vector<Triangle*> triangles = {
        new Triangle{p1, p2, p3, "triaA"},
        new Triangle{p1, p4, p8, "triaB"},
        new Triangle{p1, p5, p6, "triaC"},
        new Triangle{p1, p7, p8, "triaD"}
    };

    bool done = false;
    while (!done) {
        switch (Menu()) {
        case 1: Show(triangles); break;
        case 2: Move(triangles); break;
        case 3: FindMax(triangles); break;
        case 4: IsIncluded(triangles); break;
        case 5:
            std::cout << "Конец работы.\n";
            done = true;
            break;
        default:
            std::cout << "Неверный выбор!\n";
        }
    }

    // Очистка памяти
    for (auto& t : triangles) delete t;
    return 0;
}

int Menu() {
    std::cout << "\n================= Главное меню =================\n"
        << "1 - Вывести все объекты\t3 - Найти максимальный\n"
        << "2 - Переместить\t\t4 - Определить отношение включения\n"
        << "\t\t5 - Выход\n"
        << "Выберите пункт: ";
    return GetNumber(1, 5);
}

int GetNumber(int min, int max) {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.good() && number >= min && number <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return number;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Повторите ввод (число от " << min << " до " << max << "): ";
    }
}

void ExitBack() {
    std::cout << "Нажмите Enter...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Show(const std::vector<Triangle*>& triangles) {
    std::cout << "\n======= Перечень треугольников ========\n";
    for (const auto& t : triangles) t->Show();
    for (const auto& t : triangles) t->ShowSideAndArea();
    ExitBack();
}

void Move(std::vector<Triangle*>& triangles) { ExitBack(); }
void FindMax(const std::vector<Triangle*>& triangles) { ExitBack(); }
void IsIncluded(const std::vector<Triangle*>& triangles) { ExitBack(); }