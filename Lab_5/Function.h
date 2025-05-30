///////////////////////////////////////////////////////////
// Function.h
#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

// Базовый абстрактный класс для математических функций
class Function {
public:
    virtual ~Function() {} // Виртуальный деструктор
    void SetArg(double arg) { x = arg; } // Установка аргумента
    virtual void SetCoeff() = 0; // Установка коэффициентов
    virtual double GetVal() const = 0; // Вычисление значения
    virtual const std::string& GetName() const = 0; // Получение имени
protected:
    double x; // Аргумент функции
};

#endif /* FUNCTION_H */
///////////////////////////////////////////////////////////