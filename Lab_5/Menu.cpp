///////////////////////////////////////////////////////////
// Menu.cpp
#include <iostream>
#include "Menu.h"

using namespace std;

// Конструктор меню
Menu::Menu(vector<Function*> _pObj, vector<Action*> _pAct)
    : pObj(_pObj), pAct(_pAct) {
    pObj.push_back(0); // Добавление пункта "Exit"
}

// Выбор функции из меню
Function* Menu::SelectObject() const {
    int nItem = pObj.size();
    cout << "======================================\n";
    cout << "Select one of the following functions:\n";

    for (int i = 0; i < nItem; ++i) {
        cout << i + 1 << ". ";
        if (pObj[i]) cout << pObj[i]->GetName() << endl;
        else cout << "Exit" << endl;
    }

    int item = SelectItem(nItem);
    return pObj[item - 1];
}

// Выбор операции для функции
Action* Menu::SelectAction(Function* pObj) const {
    int nItem = pAct.size();
    cout << "======================================\n";
    cout << "Select one of the following Actions:\n";

    for (int i = 0; i < nItem; ++i) {
        cout << i + 1 << ". " << pAct[i]->GetName() << endl;
    }

    int item = SelectItem(nItem);
    return pAct[item - 1];
}

// Ввод и проверка пункта меню
int Menu::SelectItem(int nItem) const {
    cout << "\n";
    int item;
    while (true) {
        cin >> item;
        if ((item > 0) && (item <= nItem) && (cin.peek() == '\n')) {
            cin.get();
            break;
        }
        else {
            cout << "Error (must be number from 1 to " << nItem << "): ";
            cin.clear();
            while (cin.get() != '\n') {};
        }
    }
    return item;
}
///////////////////////////////////////////////////////////