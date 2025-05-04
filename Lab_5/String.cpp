//////////////////////////////////
//////  String.cpp

#include "String.h"

// Выделение памяти с нулевым окончанием
void String::allocate_memory(size_t size) {
    data = new char[size + 1];
    data[size] = '\0';
}

// Безопасное удаление данных
void String::safe_delete() {
    delete[] data;
    data = nullptr;
}

// Конструктор по умолчанию (пустая строка)
String::String() : data(nullptr), length(0) {
    allocate_memory(0);
}

// Конструктор из C-строки
String::String(const char* str) : data(nullptr), length(strlen(str)) {
    allocate_memory(length);
    strcpy(data, str);
}

// Конструктор копирования
String::String(const String& other) : data(nullptr), length(other.length) {
    allocate_memory(length);
    strcpy(data, other.data);
}

// Деструктор
String::~String() {
    safe_delete();
}

// Получение длины строки
size_t String::size() const {
    return length;
}

// Получение C-строки
const char* String::c_str() const {
    return data;
}

// Оператор присваивания
String& String::operator=(const String& other) {
    if (this != &other) {
        safe_delete();
        length = other.length;
        allocate_memory(length);
        strcpy(data, other.data);
    }
    return *this;
}

// Конкатенация строк
String String::operator+(const String& other) const {
    String result;
    result.length = length + other.length;
    result.allocate_memory(result.length);
    strcpy(result.data, data);
    strcat(result.data, other.data);
    return result;
}

// Операторы сравнения
bool String::operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator<(const String& other) const {
    return strcmp(data, other.data) < 0;
}

bool String::operator>(const String& other) const {
    return strcmp(data, other.data) > 0;
}
