///////////////////////////////////////////////////////////
// AString.h
#ifndef ASTRING_H
#define ASTRING_H

#include <string>

// Абстрактный базовый класс для строковых объектов
class AString {
public:
    virtual ~AString() {} // Виртуальный деструктор
    virtual const std::string& GetName() const = 0; // Получить имя
    virtual const std::string& GetVal() const = 0;  // Получить значение
    virtual int GetSize() const = 0;               // Получить размер
};

#endif // ASTRING_H
///////////////////////////////////////////////////////////