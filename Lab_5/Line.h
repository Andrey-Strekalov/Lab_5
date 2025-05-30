///////////////////////////////////////////////////////////
// Line.h
#include "Function.h"

// Класс линейной функции y = a*x + b
class Line : public Function {
public:
    Line() : name("a*x + b") {} // Конструктор
    const std::string& GetName() const { return name; }
    void SetCoeff(); // Установка коэффициентов
    double GetVal() const { return (a * x + b); } // Вычисление
private:
    std::string name; // Название функции
    double a, b; // Коэффициенты
};

extern Line f_line; // Глобальный объект
///////////////////////////////////////////////////////////