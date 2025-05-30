///////////////////////////////////////////////////////////
// Function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

// Базовый абстрактный класс для всех математических функций
class Function {
public:
    virtual ~Function() {} // Виртуальный деструктор для корректного удаления наследников
    virtual const std::string& GetName() const = 0; // Получить название функции
    virtual void Calculate() = 0; // Вычислить значение функции
protected:
    double x; // Аргумент функции (доступен наследникам)
};

#endif /* FUNCTION_H */
///////////////////////////////////////////////////////////