///////////////////////////////////////////////////////////
// Parabola.cpp
#include <iostream>
#include "Parabola.h"

using namespace std;

void Parabola::Calculate() {
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter a = "; cin >> a;
    cout << "Enter b = "; cin >> b;
    cout << "Enter c = "; cin >> c;
    cout << "Enter x = "; cin >> x;
    cin.get();
    cout << "y = " << (a * x * x + b * x + c) << endl;
    cin.get();
}

Parabola f_parabola;
///////////////////////////////////////////////////////////