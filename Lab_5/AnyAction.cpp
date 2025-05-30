///////////////////////////////////////////////////////////
// AnyAction.cpp
#include <iostream>
#include "AnyAction.h"

using namespace std;

// Реализация демонстрационной операции
void AnyAction::Operate(Function*) {
    cout << "Your advertising might be here!" << endl;
    cin.get();
}

// Создание глобального объекта
AnyAction any_action;
///////////////////////////////////////////////////////////