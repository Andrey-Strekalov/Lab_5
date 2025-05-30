///////////////////////////////////////////////////////////
// Action.cpp
#include <iostream>
#include "Action.h"
#include "HexString.h"

using namespace std;

// Конвертация HEX-строки в decimal
long Action::GetDecimal(AString* pObj) const {
    HexString* hexPtr = dynamic_cast<HexString*>(pObj);
    if (hexPtr) {
        long dest;
        string source = hexPtr->GetVal();
        sscanf(source.c_str(), "%lX", &dest); // Конвертация
        return dest;
    }
    cout << "Action not supported for this string type." << endl;
    return -1;
}
///////////////////////////////////////////////////////////