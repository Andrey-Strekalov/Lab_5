///////////////////////////////////////////////////////////
// AnyAction.h
#include "Action.h"

// Класс для демонстрации расширяемости системы
class AnyAction : public Action {
public:
    AnyAction() : name("Any action") {} // Конструктор
    const std::string& GetName() const { return name; }
    void Operate(Function*); // Реализация операции
private:
    std::string name; // Название операции
};

extern AnyAction any_action; // Глобальный объект
///////////////////////////////////////////////////////////