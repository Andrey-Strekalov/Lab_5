///////////////////////////////////////////////////////////
// Main.cpp
#include <iostream>
#include <vector>
#include <limits>
#define NOMINMAX // Отключает макросы min/max из Windows.h
#include <Windows.h>
#include "Triangle.h"

// Прототипы функций управления меню
int Menu();
int GetNumber(int min, int max);
void ExitBack();
void Show(const std::vector<Triangle*>& triangles);
void Move(std::vector<Triangle*>& triangles);
void FindMax(const std::vector<Triangle*>& triangles);
void IsIncluded(const std::vector<Triangle*>& triangles);
double GetDouble();

int main() {
	// Настройка локали и кодировки консоли
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);       
	SetConsoleOutputCP(1251); 

	// Инициализация тестовых точек
	Point p1{ 0, 0 }, p2{ 0.5, 1 }, p3{ 1, 0 }, p4{ 0, 4.5 },
		p5{ 2, 1 }, p6{ 2, 0 }, p7{ 2, 2 }, p8{ 3, 0 };

	// Создание коллекции треугольников
	std::vector<Triangle*> triangles = {
		new Triangle{p1, p2, p3, "triaA"},
		new Triangle{p1, p4, p8, "triaB"},
		new Triangle{p1, p5, p6, "triaC"},
		new Triangle{p1, p7, p8, "triaD"}
	};

	// Главный цикл обработки команд
	bool done = false;
	while (!done) {
		switch (Menu()) {
		case 1: Show(triangles); break;     // Показать все объекты
		case 2: Move(triangles); break;     // Переместить треугольник
		case 3: FindMax(triangles); break;  // Найти максимальный
		case 4: IsIncluded(triangles); break;// Проверить включение
		case 5: done = true; break;         // Выход
		default: std::cout << "Неверный выбор!\n";
		}
	}

	// Освобождение памяти
	for (auto& t : triangles) delete t;
	return 0;
}

// Функция отображения главного меню
int Menu() {
	std::cout << "\n================= Главное меню =================\n"
		<< "1 - Вывести все объекты\t3 - Найти максимальный\n"
		<< "2 - Переместить\t\t4 - Определить отношение включения\n"
		<< "\t\t5 - Выход\n"
		<< "Выберите пункт: ";
	return GetNumber(1, 5);
}

// Функция безопасного ввода целого числа в диапазоне
int GetNumber(int min, int max) {
	int number;
	while (true) {
		std::cin >> number;
		// Проверка корректности ввода
		if (std::cin.good() && number >= min && number <= max) {
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return number;
		}
		// Очистка ошибочного ввода
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Повторите ввод (число от " << min << " до " << max << "): ";
	}
}

// Пауза перед возвратом в меню
void ExitBack() {
	std::cout << "Нажмите Enter...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Вывод информации о треугольниках
void Show(const std::vector<Triangle*>& triangles) {
	std::cout << "\n======= Перечень треугольников ========\n";
	for (const auto& t : triangles) t->Show();
	ExitBack();
}

// Функция ввода вещественного числа
double GetDouble() {
	double value;
	while (true) {
		std::cin >> value;
		if (std::cin.peek() == '\n') break;
		else {
			std::cout << "Повторите ввод (ожидается вещественное число):\n";
			std::cin.clear();
			while (std::cin.get() != '\n') {};
		}
	}
	return value;
}

// Перемещение треугольника
void Move(std::vector<Triangle*>& triangles) {
	std::cout << "============= Перемещение =============\n";
	std::cout << "Введите номер треугольника (от 1 до "
		<< triangles.size() << "): ";
	int i = GetNumber(1, triangles.size()) - 1;
	triangles[i]->Show();

	// Ввод смещения
	Point dp;
	std::cout << "Введите смещение по х: ";
	dp.x = GetDouble();
	std::cout << "Введите смещение по у: ";
	dp.y = GetDouble();

	// Применение смещения
	triangles[i]->Move(dp);
	std::cout << "Новое положение треугольника:\n";
	triangles[i]->Show();
	ExitBack();
}

// Поиск треугольника с максимальной площадью
void FindMax(const std::vector<Triangle*>& triangles) {
	std::cout << "=== Поиск максимального треугольника ===" << std::endl;
	Triangle triaMax("triaMax");
	triaMax = *triangles[0];

	// Поиск через сравнение площадей
	for (int i = 1; i < 4; ++i) {
		if (*triangles[i] > triaMax) {
			triaMax = *triangles[i];
		}
	}
	std::cout << "Максимальный треугольник: " << triaMax.GetName() << std::endl;
	ExitBack();
}

// Проверка включения одного треугольника в другой
void IsIncluded(const std::vector<Triangle*>& triangles) {
	std::cout << "======== Отношение включения ==========" << std::endl;
	int k = triangles.size();

	// Выбор треугольников для сравнения
	std::cout << "Введите номер 1-го треугольника (от 1 до " << k << "): ";
	int i1 = GetNumber(1, k) - 1;
	std::cout << "Введите номер 2-го треугольника (от 1 до " << k << "): ";
	int i2 = GetNumber(1, k) - 1;

	// Проверка включения и вывод результата
	if (TriaInTria(*triangles[i1], *triangles[i2])) {
		std::cout << triangles[i1]->GetName() << " - входит в - "
			<< triangles[i2]->GetName() << std::endl;
	}
	else {
		std::cout << triangles[i1]->GetName() << " - не входит в - "
			<< triangles[i2]->GetName() << std::endl;
	}
	ExitBack();
}

