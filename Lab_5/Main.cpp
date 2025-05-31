#include "factory.h"
#include <iostream>
#include <limits>

using namespace std;

// Функция отображения главного меню
void displayMenu() {
    cout << "\n===== Менеджер геометрических объектов =====\n";
    cout << "1. Создать треугольник\n";
    cout << "2. Создать прямоугольник\n";
    cout << "3. Удалить объект\n";
    cout << "4. Показать все объекты\n";
    cout << "5. Переместить объект\n";
    cout << "6. Сравнить объекты по площади\n";
    cout << "0. Выход\n";
    cout << "===========================================\n";
    cout << "Выберите опцию: ";
}

// Очистка буфера ввода
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    system("chcp 1251 > nul"); // Установка русской кодировки для Windows
    Factory factory; // Создание фабрики объектов
    int choice;     // Переменная для выбора пользователя

    // Главный цикл программы
    while (true) {
        displayMenu(); // Показ меню
        cin >> choice; // Чтение выбора пользователя

        // Обработка некорректного ввода
        if (cin.fail()) {
            clearInput();
            cout << "Неверный ввод! Пожалуйста, введите число.\n";
            continue;
        }

        string id; // Переменная для хранения ID
        switch (choice) {
        case 1: // Создание треугольника
            factory.createTriangle();
            break;
        case 2: // Создание прямоугольника
            factory.createRectangle();
            break;
        case 3: // Удаление объекта
            cout << "Введите ID объекта для удаления: ";
            cin >> id;
            factory.deleteObject(id);
            break;
        case 4: // Показать все объекты
            factory.showAll();
            break;
        case 5: // Переместить объект
            cout << "Введите ID объекта для перемещения: ";
            cin >> id;
            factory.moveObject(id);
            break;
        case 6: // Сравнить объекты
            factory.compareObjects();
            break;
        case 0: // Выход из программы
            cout << "Выход из программы...\n";
            return 0;
        default: // Некорректный выбор
            cout << "Неверная опция! Попробуйте еще раз.\n";
        }
        clearInput(); // Очистка буфера после каждого выбора
    }
}