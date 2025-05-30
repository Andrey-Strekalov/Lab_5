///////////////////////////////////////////////////////////
// Main.cpp
#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Action.h"
#include "Calculation.h"
#include "Tabulation.h"
#include "AnyAction.h"
#include "Menu.h"

using namespace std;

// Массив доступных функций
Function* pObjs[] = { &f_exp, &f_line };

// Массив доступных операций
Action* pActs[] = { &calculation, &tabulation, &any_action };

// Преобразование массивов в векторы
vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs) / sizeof(Function*));
vector<Action*> operList(pActs, pActs + sizeof(pActs) / sizeof(Action*));

int main() {
    Menu menu(funcList, operList); // Создание меню

    // Главный цикл программы
    while (Function* pObj = menu.SelectObject()) {
        Action* pAct = menu.SelectAction(pObj); // Выбор операции
        pAct->Operate(pObj); // Выполнение операции
    }

    cout << "Bye!\n";
    return 0;
}
///////////////////////////////////////////////////////////