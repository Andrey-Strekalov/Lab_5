///////////////////////////////////////////////////////////
// Menu.cpp
#include <iostream>
#include "Menu.h"

using namespace std;

// Конструктор: копирует переданные функции и добавляет Exit
Menu::Menu(vector<Function*> _pObj) : pObj(_pObj) {
    pObj.push_back(0); // nullptr для пункта Exit
}

// Отображение меню и выбор функции
Function* Menu::SelectObject() const {
    int nItem = pObj.size(); // Количество пунктов
    cout << "==============================================\n";
    cout << "Select one of the following function:\n";

    // Вывод всех пунктов
    for (int i = 0; i < nItem; ++i) {
        cout << i + 1 << ". ";
        if (pObj[i]) cout << pObj[i]->GetName() << endl;
        else cout << "Exit" << endl;
    }

    int item = SelectItem(nItem); // Получение выбора
    return pObj[item - 1]; // Возврат выбранной функции
}

// Ввод и проверка номера пункта
int Menu::SelectItem(int nItem) const {
    cout << "\n";
    int item;
    while (true) {
        cin >> item;
        // Проверка: число в диапазоне и следующий символ - '\n'
        if ((item > 0) && (item <= nItem) && (cin.peek() == '\n')) {
            cin.get(); // Убираем '\n' из буфера
            break;
        }
        else {
            cout << "Error (must be number from 1 to " << nItem << "): " << endl;
            cin.clear(); // Сброс флагов ошибок
            while (cin.get() != '\n') {}; // Очистка буфера
        }
    }
    return item;
}
///////////////////////////////////////////////////////////