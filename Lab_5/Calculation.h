///////////////////////////////////////////////////////////
// Calculation.h
#include "Action.h"

// Класс для операции вычисления значения функции
class Calculation : public Action {
public:
    Calculation() : name("Calculation") {} // Конструктор
    const std::string& GetName() const { return name; }
    void Operate(Function*); // Реализация операции
private:
    std::string name; // Название операции
};

extern Calculation calculation; // Глобальный объект
///////////////////////////////////////////////////////////