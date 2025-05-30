///////////////////////////////////////////////////////////
// Menu.h
#include <vector>
#include "AString.h"
#include "Action.h"
#include "Factory.h"

// Режимы работы программы
enum JobMode { AddObj, DelObj, WorkWithObj, Exit };

// Класс для управления меню
class Menu {
public:
    Menu(std::vector<Action*>);
    JobMode SelectJob() const;            // Выбор режима
    AString* SelectObject(const Factory&) const; // Выбор строки
    Action* SelectAction(const AString*) const;  // Выбор операции
    static int SelectItem(int);           // Утилита выбора пункта

private:
    std::vector<Action*> pAct; // Доступные операции
};
///////////////////////////////////////////////////////////