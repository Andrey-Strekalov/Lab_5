///////////////////////////////////////////////////////////
// main.cpp
#include <iostream>
#include "Function.h"
#include "Parabola.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"

using namespace std;

// Массив доступных функций (глобальные объекты)
Function* pObjs[] = { &f_exp, &f_line, &f_parabola };

// Преобразование массива в вектор
vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs) / sizeof(Function*));

int main() {
    system("chcp 1251 > nul"); // Для русской кодировки в Windows
    Menu menu(funcList); // Создаем меню с функциями

    // Главный цикл: пока пользователь не выберет Exit
    while (Function* pObj = menu.SelectObject())
        pObj->Calculate(); // Вычисляем выбранную функцию

    cout << "Bye!\n";
    return 0;
}
///////////////////////////////////////////////////////////