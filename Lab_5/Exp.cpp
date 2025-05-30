///////////////////////////////////////////////////////////
// Exp.cpp
#include <iostream>
#include <cmath>
#include "Exp.h"

using namespace std;

// Реализация вычисления экспоненты
void Exp::Calculate() {
    cout << "Calculation for function y = " << name << endl;
    cout << "Enter X = "; cin >> x; // Ввод аргумента
    cin.get(); // Очистка буфера от '\n'
    cout << "y = " << exp(x) << endl; // Вычисление e^x
    cin.get(); // Пауза перед выходом
}

// Создание глобального объекта
Exp f_exp;
///////////////////////////////////////////////////////////