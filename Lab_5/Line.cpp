///////////////////////////////////////////////////////////
// Line.cpp
#include <iostream>
#include "Line.h"

using namespace std;

// Установка коэффициентов линейной функции
void Line::SetCoeff() {
    cout << "Enter a = "; cin >> a;
    cout << "Enter b = "; cin >> b;
}

// Создание глобального объекта
Line f_line;
///////////////////////////////////////////////////////////