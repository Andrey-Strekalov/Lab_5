///////////////////////////////////////////////////////////
// Menu.h
#include <vector>
#include "Function.h"

// Класс для меню выбора функций
class Menu {
public:
    Menu(std::vector<Function*>); // Конструктор принимает вектор функций
    Function* SelectObject() const; // Выбор функции из меню
private:
    int SelectItem(int) const; // Ввод номера пункта
    std::vector<Function*> pObj; // Список функций + Exit
};
///////////////////////////////////////////////////////////