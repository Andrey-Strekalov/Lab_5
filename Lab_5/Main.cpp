//////////////////////////////////
//////  Main.cpp

#include "String.h"
#include <iostream>
#include <Windows.h> // для использования SetConsoleCP и SetConsoleOutputCP


// Функция отображения меню
void show_menu() {
    std::cout << "\n=== Меню ==="
        << "\n1. Конкатенация строк"
        << "\n2. Сравнение строк"
        << "\n3. Преобразование в число"
        << "\n4. Форматный вывод"
        << "\n5. Выход"
        << "\nВыберите действие: ";
}

int main() {
    int choice;
    String s1, s2, result;
    setlocale(LC_ALL, "ru");
    // меняем кодировку консоли для возможности рускоязычного ввода
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    // Основной цикл программы
    while (true) {
        show_menu();
        std::cin >> choice;
        std::cin.ignore(); // Очистка буфера ввода

        switch (choice) {
        case 1: { // Конкатенация строк
            std::cout << "Введите первую строку: ";
            char buffer1[256];
            std::cin.getline(buffer1, 256);
            s1 = buffer1;

            std::cout << "Введите вторую строку: ";
            char buffer2[256];
            std::cin.getline(buffer2, 256);
            s2 = buffer2;

            result = s1 + " " + s2;
            std::cout << "Результат: " << result.c_str() << std::endl;
            break;
        }

        case 2: { // Сравнение строк
            std::cout << "Введите первую строку: ";
            char buffer1[256];
            std::cin.getline(buffer1, 256);
            s1 = buffer1;

            std::cout << "Введите вторую строку: ";
            char buffer2[256];
            std::cin.getline(buffer2, 256);
            s2 = buffer2;

            std::cout << "Сравнение: "
                << (s1 == s2 ? "Равны" : "Не равны")
                << std::endl;
            break;
        }

        case 3: { // Преобразование в число
            std::cout << "Введите числовую строку: ";
            char buffer[256];
            std::cin.getline(buffer, 256);
            s1 = buffer;

            try {
                double num = static_cast<double>(s1);
                std::cout << "Числовое значение: " << num << std::endl;
            }
            catch (const std::exception& e) {
                std::cerr << "Ошибка: " << e.what() << std::endl;
            }
            break;
        }

        case 4: { // Форматный вывод
            String formatted = String::format(
                "Форматирование: Число %.2f, Строка '%s'",
                3.1415,
                "Тест"
            );
            std::cout << formatted.c_str() << std::endl;
            break;
        }

        case 5: // Выход
            return 0;

        default:
            std::cout << "Неверный выбор!" << std::endl;
        }
    }
}
