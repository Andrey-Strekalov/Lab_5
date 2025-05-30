///////////////////////////////////////////////////////////
// ShowStr.cpp
#include <iostream>
#include "ShowStr.h"

using namespace std;

// Реализация операции отображения
void ShowStr::Operate(AString* pObj) {
    cout << pObj->GetName() << ": ";
    cout << pObj->GetVal() << endl;
    cin.get();
}

ShowStr show_str; // Создание глобального объекта
///////////////////////////////////////////////////////////