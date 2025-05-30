///////////////////////////////////////////////////////////
// Factory.h
#ifndef FACTORY_H
#define FACTORY_H

#include <vector>
#include "AString.h"

// Фабрика для создания и управления строковыми объектами
class Factory {
    friend class Menu;
public:
    Factory() {}
    void AddObject();    // Добавить строку
    void DeleteObject(); // Удалить строку

private:
    std::vector<AString*> pObj; // Коллекция строк
};

#endif // FACTORY_H
///////////////////////////////////////////////////////////