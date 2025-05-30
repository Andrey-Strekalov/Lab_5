///////////////////////////////////////////////////////////
// Menu.h
#include <vector>
#include "Function.h"
#include "Action.h"

// Класс для управления меню
class Menu {
public:
    Menu(std::vector<Function*>, std::vector<Action*>); // Конструктор
    Function* SelectObject() const; // Выбор функции
    Action* SelectAction(Function*) const; // Выбор операции
private:
    int SelectItem(int) const; // Ввод пункта меню
    std::vector<Function*> pObj; // Список функций
    std::vector<Action*> pAct; // Список операций
};
///////////////////////////////////////////////////////////