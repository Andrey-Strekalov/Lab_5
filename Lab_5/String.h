//////////////////////////////////
//////  String.h

#pragma once

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <cstdio>

class String {
private:
    char* data;     // Указатель на массив символов
    size_t length;  // Длина строки

    // Вспомогательные методы для работы с памятью
    void allocate_memory(size_t size);  // Выделение памяти
    void safe_delete();                 // Безопасное освобождение памяти

public:
    // Конструкторы и деструктор
    String();                           // Конструктор по умолчанию
    String(const char* str);            // Конструктор из C-строки
    String(const String& other);        // Конструктор копирования
    ~String();                          // Деструктор

    // Базовые операции
    size_t size() const;                // Получить длину строки
    const char* c_str() const;          // Получить C-строку

    // Перегруженные операторы
    String& operator=(const String& other);  // Оператор присваивания
    String operator+(const String& other) const; // Конкатенация строк

    // Операторы сравнения
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;

    // Приведение к числовым типам
    template<typename T>
    explicit operator T() const {
        std::istringstream iss(data);
        T value;
        iss >> value;
        if (iss.fail()) {
            throw std::runtime_error("Невозможно преобразовать строку в число");
        }
        return value;
    }

    // Форматированный вывод (аналог printf)
    template<typename... Args>
    static String format(const char* fmt, Args... args) {
        // Определение необходимого размера буфера
        size_t size = snprintf(nullptr, 0, fmt, args...) + 1;
        char* buffer = new char[size];

        // Форматирование строки
        snprintf(buffer, size, fmt, args...);
        String result(buffer);

        // Очистка временного буфера
        delete[] buffer;
        return result;
    }
};

#endif
