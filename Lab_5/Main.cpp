///////////////////////////////////////////////////////////
// main.cpp
#include <iostream>
#include "Function.h"
#include "Exp.h"
#include "Line.h"
#include "Menu.h"

using namespace std;

Function* pObjs[] = { &f_exp, &f_line };
vector<Function*> funcList(pObjs, pObjs + sizeof(pObjs) / sizeof(Function*));

int main() {
    system("chcp 1251 > nul");
    Menu menu(funcList);
    while (Function* pObj = menu.SelectObject())
        pObj->Calculate();
    cout << "Bye!\n";
    return 0;
}
///////////////////////////////////////////////////////////