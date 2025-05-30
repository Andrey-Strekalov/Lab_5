///////////////////////////////////////////////////////////
// Exp.h
#include "Function.h"

// Класс для функции y = e^x (экспонента)
class Exp : public Function {
public:
    Exp() : name("e^x") {} // Конструктор, инициализирует название
    const std::string& GetName() const { return name; } // Возвращает название
    void Calculate(); // Реализация вычисления
protected:
    std::string name; // Название функции
};

extern Exp f_exp; // Глобальный объект экспоненты
///////////////////////////////////////////////////////////