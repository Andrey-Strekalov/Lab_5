///////////////////////////////////////////////////////////
// ShowDec.cpp
#include <iostream>
#include "ShowDec.h"

using namespace std;

// Реализация операции отображения decimal
void ShowDec::Operate(AString* pObj) {
    cout << pObj->GetName() << ": ";
    long decVal = GetDecimal(pObj);
    if (decVal != -1)
        cout << decVal;
    cout << endl;
    cin.get();
}

ShowDec show_dec; // Создание глобального объекта
///////////////////////////////////////////////////////////