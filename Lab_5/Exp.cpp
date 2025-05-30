
///////////////////////////////////////////////////////////
// Exp.cpp
#include <iostream>
#include <cmath>
#include "Exp.h"

using namespace std;

void Exp::Calculate() {
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter X = "; cin >> x;
    cin.get();
    cout << "y = " << exp(x) << endl;
    cin.get();
}

// Глобальный объект
Exp f_exp;
///////////////////////////////////////////////////////////
