///////////////////////////////////////////////////////////
// Line.h
#include "Function.h"

// Класс для линейной функции y = a*x + b
class Line : public Function {
public:
    Line() : name("a*x + b") {} // Конструктор
    const std::string& GetName() const { return name; }
    void Calculate();
protected:
    std::string name;
    double a, b; // Коэффициенты a и b
};

extern Line f_line; // Глобальный объект
///////////////////////////////////////////////////////////