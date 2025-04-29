///////////////////////////////////////////////////////////
// Header.h (заголовочный файл класса Man)
///////////////////////////////////////////////////////////

#pragma once
#include <cstring>

class Man {
public:
    // Константы для размеров полей
    static const int l_name = 30; // Длина поля ФИО
    static const int l_year = 5;  // Длина поля года рождения
    static const int l_pay = 10;  // Длина поля зарплаты
    static const int l_buf = l_name + l_year + l_pay; // Общая длина записи

    // Конструктор и деструктор
    Man(int lName = l_name);
    ~Man();

    // Методы работы с данными
    bool CompareName(const char* name) const; // Сравнение фамилии
    int GetBirthYear() const { return birth_year; } // Геттер года рождения
    float GetPay() const { return pay; }       // Геттер зарплаты
    const char* GetName() const { return pName; } // Геттер имени

    void Print() const;               // Вывод информации
    void SetBirthYear(const char* fromBuf); // Установка года рождения
    void SetName(const char* fromBuf);      // Установка имени
    void SetPay(const char* fromBuf);       // Установка зарплаты

private:
    char* pName;        // Динамический массив для хранения ФИО
    int birth_year;     // Год рождения
    float pay;          // Зарплата
};