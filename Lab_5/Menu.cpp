///////////////////////////////////////////////////////////
// Menu.cpp
#include <iostream>
#include "Menu.h"

using namespace std;

// Конструктор
Menu::Menu(vector<Action*> _pAct) : pAct(_pAct) {}

// Выбор режима работы
JobMode Menu::SelectJob() const {
    cout << "======================================\n";
    cout << "Select job mode:\n";
    cout << "1. Add object\n2. Delete object\n3. Work with object\n4. Exit\n";
    return static_cast<JobMode>(SelectItem(4) - 1);
}

// Выбор строки
AString* Menu::SelectObject(const Factory& fctry) const {
    if (fctry.pObj.empty()) {
        cout << "No objects available." << endl;
        return nullptr;
    }

    cout << "\nSelect object:\n";
    for (size_t i = 0; i < fctry.pObj.size(); ++i)
        cout << i + 1 << ". " << fctry.pObj[i]->GetName() << endl;

    int item = SelectItem(fctry.pObj.size());
    return fctry.pObj[item - 1];
}

// Выбор операции
Action* Menu::SelectAction(const AString* pObj) const {
    if (!pObj) return nullptr;

    cout << "\nSelect action:\n";
    for (size_t i = 0; i < pAct.size(); ++i)
        cout << i + 1 << ". " << pAct[i]->GetName() << endl;

    int item = SelectItem(pAct.size());
    return pAct[item - 1];
}

// Утилита выбора пункта
int Menu::SelectItem(int nItem) {
    int item;
    while (true) {
        cin >> item;
        if (item > 0 && item <= nItem && cin.peek() == '\n') {
            cin.get();
            return item;
        }
        cout << "Error: enter 1-" << nItem << ": ";
        cin.clear();
        while (cin.get() != '\n');
    }
}
///////////////////////////////////////////////////////////