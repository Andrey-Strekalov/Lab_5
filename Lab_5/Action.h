///////////////////////////////////////////////////////////
// Action.h
#ifndef ACTION_H
#define ACTION_H

#include "Function.h"

// Базовый класс для операций над функциями
class Action {
public:
    virtual ~Action() {} // Виртуальный деструктор
    virtual void Operate(Function*) = 0; // Выполнение операции
    virtual const std::string& GetName() const = 0; // Имя операции
};

#endif /* ACTION_H */
///////////////////////////////////////////////////////////