///////////////////////////////////////////////////////////
// Tabulation.h
#include "Action.h"

// Класс для операции табулирования функции
class Tabulation : public Action {
public:
    Tabulation() : name("Tabulation") {} // Конструктор
    const std::string& GetName() const { return name; }
    void Operate(Function*); // Реализация операции
private:
    std::string name; // Название операции
};

extern Tabulation tabulation; // Глобальный объект
///////////////////////////////////////////////////////////