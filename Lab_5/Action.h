///////////////////////////////////////////////////////////
// Action.h
#ifndef ACTION_H
#define ACTION_H

#include "AString.h"

// Базовый класс для операций над строками
class Action {
public:
    virtual ~Action() {}
    virtual void Operate(AString*) = 0; // Выполнить операцию
    virtual const std::string& GetName() const = 0; // Имя операции

protected:
    long GetDecimal(AString* pObj) const; // Конвертация HEX в decimal
};

#endif /* ACTION_H */
///////////////////////////////////////////////////////////