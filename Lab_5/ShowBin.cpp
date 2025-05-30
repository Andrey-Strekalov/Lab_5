///////////////////////////////////////////////////////////
// ShowBin.cpp
#include <iostream>
#include "ShowBin.h"
#include <bitset>

using namespace std;

// Реализация операции отображения binary
void ShowBin::Operate(AString* pObj) {
    cout << pObj->GetName() << ": ";
    cout << GetBinary(pObj) << endl;
    cin.get();
}

// Конвертация в бинарную строку
string ShowBin::GetBinary(AString* pObj) const {
    long decVal = GetDecimal(pObj);
    if (decVal == -1) return "";

    // Используем bitset для конвертации
    return bitset<64>(decVal).to_string().substr(64 - 4 * pObj->GetSize());
}

ShowBin show_bin; // Создание глобального объекта
///////////////////////////////////////////////////////////