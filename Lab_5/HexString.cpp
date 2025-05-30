///////////////////////////////////////////////////////////
// HexString.cpp
#include <iostream>
#include "HexString.h"

using namespace std;

// Проверка, что строка содержит только HEX-символы
bool IsHexStrVal(string _str) {
    for (int i = 0; i < _str.size(); ++i) {
        if (string::npos == alph.find_first_of(toupper(_str[i])))
            return false;
    }
    return true;
}

// Конструктор с проверкой валидности
HexString::HexString(string _name, string _val) : name(_name) {
    if (IsHexStrVal(_val))
        val = _val;
    else
        throw invalid_argument("Invalid HEX string");
}
///////////////////////////////////////////////////////////