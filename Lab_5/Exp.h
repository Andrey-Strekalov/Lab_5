///////////////////////////////////////////////////////////
// Exp.h
#include <math.h>
#include "Function.h"

// Класс экспоненциальной функции y = e^x
class Exp : public Function {
public:
    Exp() : name("e^x") {} // Конструктор
    const std::string& GetName() const { return name; }
    void SetCoeff() {} // Для экспоненты не нужны коэффициенты
    double GetVal() const { return exp(x); } // Вычисление e^x
private:
    std::string name; // Название функции
};

extern Exp f_exp; // Глобальный объект
///////////////////////////////////////////////////////////