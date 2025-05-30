///////////////////////////////////////////////////////////
// Line.h
#include "Function.h"

// Класс для представления функции у = а*х + b
class Line : public Function {
public:
    Line() : name("a*x + b") {}
    const std::string& GetName() const { return name; }
    void Calculate();
protected:
    std::string name; // мат. обозначение функции
    double a;
    double b;
};

extern Line f_line;
///////////////////////////////////////////////////////////
