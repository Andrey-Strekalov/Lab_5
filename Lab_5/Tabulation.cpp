///////////////////////////////////////////////////////////
// Tabulation.cpp
#include <iostream>
#include <iomanip>
#include "Tabulation.h"

using namespace std;

// Реализация операции табулирования
void Tabulation::Operate(Function* pFunc) {
    cout << "Tabulation for function y = ";
    cout << pFunc->GetName() << endl;
    pFunc->SetCoeff(); // Установка коэффициентов

    double x_beg, x_end, x_step;
    cout << "Enter x_beg = "; cin >> x_beg;
    cout << "Enter x_end = "; cin >> x_end;
    cout << "Enter x_step = "; cin >> x_step;
    cin.get();

    cout << " " << endl;
    cout << " X y" << endl;
    cout << " " << endl;

    // Табулирование функции
    double x = x_beg;
    while (x <= x_end) {
        pFunc->SetArg(x);
        cout << setw(6) << x << setw(14) << pFunc->GetVal() << endl;
        x += x_step;
    }
    cin.get();
}

// Создание глобального объекта
Tabulation tabulation;
///////////////////////////////////////////////////////////