///////////////////////////////////////////////////////////
// Factory.cpp
#include <iostream>
#include "Factory.h"
#include "Menu.h"
#include "SymbString.h"
#include "HexString.h"

using namespace std;
#define MAX_LEN_STR 100

// Добавление новой строки
void Factory::AddObject() {
    cout << "\nSelect object type:\n";
    cout << "1. Symbolic string\n2. Hexadecimal string\n";

    int item = Menu::SelectItem(2);
    string name, value;

    cout << "Enter object name: ";
    cin >> name;
    cin.get();

    cout << "Enter object value: ";
    char buf[MAX_LEN_STR];
    cin.getline(buf, MAX_LEN_STR);
    value = buf;

    try {
        AString* pNewObj = nullptr;
        switch (item) {
        case 1: pNewObj = new SymbString(name, value); break;
        case 2: pNewObj = new HexString(name, value); break;
        }
        pObj.push_back(pNewObj);
        cout << "Object added." << endl;
    }
    catch (...) {
        cout << "Error creating object!" << endl;
    }
}

// Удаление строки
void Factory::DeleteObject() {
    if (pObj.empty()) {
        cout << "No objects to delete." << endl;
        return;
    }

    cout << "\nDelete one of:\n";
    for (size_t i = 0; i < pObj.size(); ++i)
        cout << i + 1 << ". " << pObj[i]->GetName() << endl;

    int item = Menu::SelectItem(pObj.size());
    string name = pObj[item - 1]->GetName();
    delete pObj[item - 1];
    pObj.erase(pObj.begin() + item - 1);
    cout << "Object " << name << " deleted." << endl;
}
///////////////////////////////////////////////////////////