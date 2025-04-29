///////////////////////////////////////////////////////////
// codesrun_source.cpp (реализация методов класса Man)
///////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS // Отключение предупреждений безопасности

#include "../Lab_5/Man.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

// Конструктор
Man::Man(int lName) : birth_year(0), pay(0.0f) {
    std::cout << "Constructor is working" << std::endl;
    pName = new char[lName + 1](); // Выделение памяти с инициализацией нулями
}

// Деструктор
Man::~Man() {
    std::cout << "Destructor is working" << std::endl;
    delete[] pName; // Освобождение памяти
}

// Установка имени из буфера
void Man::SetName(const char* fromBuf) {
    std::strncpy(pName, fromBuf, l_name); // Копирование первых 30 символов
    pName[l_name] = '\0'; // Гарантированное завершение строки
}

// Установка года рождения
void Man::SetBirthYear(const char* fromBuf) {
    // Преобразуем подстроку (символы 30-34) в число
    birth_year = std::atoi(fromBuf + l_name);
}

// Установка зарплаты
void Man::SetPay(const char* fromBuf) {
    // Преобразуем подстроку (символы 35-44) в число с плавающей точкой
    pay = std::atof(fromBuf + l_name + l_year);
}

// Сравнение фамилии
bool Man::CompareName(const char* name) const {
    size_t name_len = std::strlen(name);
    // Проверяем:
    // 1. Совпадение первых N символов (длина введенной фамилии)
    // 2. Наличие пробела после фамилии
    return (std::strncmp(pName, name, name_len) == 0) &&
        (pName[name_len] == ' ');
}

// Вывод информации о сотруднике
void Man::Print() const {
    std::cout << pName << " " << birth_year << " " << pay << std::endl;
}