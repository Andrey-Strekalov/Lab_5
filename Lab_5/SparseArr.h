///////////////////////////////////////////////////////////
// SparseArr.h
#ifndef SPARSE_ARR_H
#define SPARSE_ARR_H

#include <list>
#include <iostream>

// Элемент разреженного массива
template <class DataT>
class SA_item {
public:
    SA_item() : index(-1), info(DataT()) {}              // Конструктор по умолчанию
    SA_item(long i, DataT d) : index(i), info(d) {}      // Конструктор с параметрами

    long index;  // Индекс элемента
    DataT info;  // Значение элемента
};

// Шаблонный класс разреженного массива
template <class T>
class SparseArr {
public:
    SparseArr(long len) : length(len) {}  // Конструктор с заданной длиной

    T& operator[](long ind);              // Оператор доступа по индексу
    void Show(const char* title);         // Вывод массива

private:
    std::list<SA_item<T>> arr;  // Список для хранения элементов
    long length;                // Общая длина массива
};

// Реализация метода Show
template <class T>
void SparseArr<T>::Show(const char* title) {
    std::cout << "===== " << title << " =====\n";
    typename std::list<SA_item<T>>::iterator i = arr.begin();
    typename std::list<SA_item<T>>::iterator n = arr.end();

    for (; i != n; ++i)
        std::cout << i->index << "\t" << i->info << std::endl;
}

// Реализация оператора []
template <class T>
T& SparseArr<T>::operator[](long ind) {
    // Проверка корректности индекса
    if ((ind < 0) || (ind > length - 1)) {
        std::cerr << "Error of index: " << ind << std::endl;
        static SA_item<T> temp;  // Возвращаем ссылку на временный объект
        return temp.info;
    }

    // Поиск элемента с заданным индексом
    typename std::list<SA_item<T>>::iterator i = arr.begin();
    typename std::list<SA_item<T>>::iterator n = arr.end();

    for (; i != n; ++i) {
        if (ind == i->index)
            return i->info;  // Элемент найден
    }

    // Элемент не найден - создаем новый
    arr.push_back(SA_item<T>(ind, T()));
    i = arr.end();
    return (--i)->info;
}

#endif // SPARSE_ARR_H
///////////////////////////////////////////////////////////