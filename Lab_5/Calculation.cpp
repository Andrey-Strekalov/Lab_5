///////////////////////////////////////////////////////////
// Calculation.cpp
#include <iostream>
#include "Calculation.h"

using namespace std;

// Реализация операции вычисления
void Calculation::Operate(Function* pFunc) {
    cout << "Calculation for function y = ";
    cout << pFunc->GetName() << endl;
    pFunc->SetCoeff(); // Установка коэффициентов

    double x;
    cout << "Enter X = "; cin >> x;
    cin.get();

    pFunc->SetArg(x); // Установка аргумента
    cout << "y = " << pFunc->GetVal() << endl;
    cin.get();
}

// Создание глобального объекта
Calculation calculation;
///////////////////////////////////////////////////////////