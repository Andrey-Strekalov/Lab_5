///////////////////////////////////////////////////////////
// CODESRUN.cpp (основной файл программы)
///////////////////////////////////////////////////////////

#include "../Lab_5/Man.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <Windows.h> 

const char filename[] = "dbase.txt";

int main() {
	// Настройка локали и кодировки консоли
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);       
	SetConsoleOutputCP(1251);

	// Создание массива объектов Man (максимум 10 записей)
	const int maxn_record = 10;
	Man man[maxn_record];

	// Буферы для чтения данных
	char buf[Man::l_buf + 1];  // Буфер для чтения строк из файла
	char name[Man::l_name + 1]; // Буфер для ввода фамилии

	// Открытие файла с данными
	std::ifstream fin(filename);
	if (!fin) {
		std::cout << "Нет файла " << filename << std::endl;
		return 1;
	}

	// Чтение данных из файла
	int i = 0;
	while (fin.getline(buf, Man::l_buf)) {
		// Проверка на превышение максимального количества записей
		if (i >= maxn_record) {
			std::cout << "Слишком длинный файл" << std::endl;
			return 1;
		}

		// Заполнение данных сотрудника
		man[i].SetName(buf);        // Установка имени
		man[i].SetBirthYear(buf);   // Установка года рождения
		man[i].SetPay(buf);         // Установка зарплаты
		i++;
	}

	int n_record = i;    // Реальное количество считанных записей
	int n_man = 0;       // Счетчик найденных сотрудников
	float mean_pay = 0.0f; // Сумма зарплат для расчета среднего

	// Основной цикл поиска сотрудников
	while (true) {
		std::cout << "Введите фамилию или слово end: ";
		std::cin.getline(name, Man::l_name + 1);

		// Выход из цикла при вводе "end"
		if (std::strcmp(name, "end") == 0) break;

		bool not_found = true;
		// Поиск по всем записям
		for (i = 0; i < n_record; ++i) {
			if (man[i].CompareName(name)) {
				man[i].Print();          // Вывод информации
				n_man++;                // Увеличение счетчика
				mean_pay += man[i].GetPay(); // Суммирование зарплат
				not_found = false;
				break; // Прерываем цикл после первого найденного совпадения
			}
		}
		if (not_found) {
			std::cout << "Такого сотрудника нет" << std::endl;
		}
	}

	// Вывод среднего оклада, если были найдены сотрудники
	if (n_man) {
		std::cout << "Средний оклад: " << mean_pay / n_man << std::endl;
	}

	return 0;
}



