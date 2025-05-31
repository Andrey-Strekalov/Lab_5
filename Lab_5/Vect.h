///////////////////////////////////////////////////////////
// Vect.h
#ifndef _VECT_
#define _VECT_

#include <iostream>
#include <string>
#include "VectError.h"

// Шаблонный класс вектора
template<class T>
class Vect {
public:
    // Конструкторы
    explicit Vect() : first(0), last(0) {}  // Пустой вектор
    explicit Vect(size_t _n, const T& _v = T()) {  // Вектор с _n элементами
        Allocate(_n);
        for (size_t i = 0; i < _n; ++i)
            *(first + i) = _v;
    }

    // Конструктор копирования
    Vect(const Vect& other) {
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        markName = "Copy of " + other.markName;
#ifdef DEBUG
        std::cout << "Copy constructor: " << markName << std::endl;
#endif
    }

    // Оператор присваивания
    Vect& operator=(const Vect& other) {
        if (this == &other) return *this;
        Destroy();
        size_t n = other.size();
        Allocate(n);
        for (size_t i = 0; i < n; ++i)
            *(first + i) = *(other.first + i);
        return *this;
    }

    // Деструктор
    ~Vect() {
#ifdef DEBUG
        std::cout << "Destructor of " << markName << std::endl;
#endif
        Destroy();
        first = 0; last = 0;
    }

    // Методы управления
    void mark(std::string name) { markName = name; }  // Установка имени
    std::string mark() const { return markName; }      // Получение имени

    size_t size() const {  // Получение размера
        if (first > last) throw VectError();
        return (0 == first ? 0 : last - first);
    }

    T* begin() const { return first; }  // Указатель на первый элемент
    T* end() const { return last; }    // Указатель за последний элемент

    // Операции с элементами
    T& operator[](size_t i) {  // Доступ по индексу
        if (i < 0 || i >(size() - 1))
            throw VectRangeErr(0, last - first - 1, i);
        return (*(first + i));
    }

    void insert(T* _p, const T& _x);  // Вставка элемента
    void push_back(const T& _x);      // Добавление в конец
    void pop_back();                  // Удаление последнего

    void show() const;  // Вывод содержимого

protected:
    void Allocate(size_t _n) {  // Выделение памяти
        first = new T[_n];
        last = first + _n;
    }

    void Destroy() {  // Освобождение памяти
        for (T* p = first; p != last; ++p) p->~T();
        delete[] first;
    }

private:
    T* first;           // Указатель на первый элемент
    T* last;            // Указатель за последний элемент
    std::string markName;  // Имя для отладки
};

// Реализация методов шаблона

// Вставка элемента в позицию _p
template<class T>
void Vect<T>::insert(T* _p, const T& _x) {
    size_t n = size() + 1;  // Новый размер
    T* new_first = new T[n];
    T* new_last = new_first + n;
    size_t offset = _p - first;

    // Копируем элементы до позиции вставки
    for (size_t i = 0; i < offset; ++i)
        *(new_first + i) = *(first + i);

    // Вставляем новый элемент
    *(new_first + offset) = _x;

    // Копируем оставшиеся элементы
    for (size_t i = offset; i < n - 1; ++i)
        *(new_first + i + 1) = *(first + i);

    Destroy();
    first = new_first;
    last = new_last;
}

// Добавление элемента в конец
template<class T>
void Vect<T>::push_back(const T& _x) {
    if (!size()) {
        Allocate(1);
        *first = _x;
    }
    else
        insert(end(), _x);
}

// Удаление последнего элемента
template<class T>
void Vect<T>::pop_back() {
    if (last == first)
        throw VectPopErr();
    T* p = end() - 1;
    p->~T();
    last--;
}

// Вывод содержимого вектора
template<class T>
void Vect<T>::show() const {
    std::cout << "\n===== Contents of " << markName << " =====" << std::endl;
    size_t n = size();
    for (size_t i = 0; i < n; ++i)
        std::cout << *(first + i) << " ";
    std::cout << std::endl;
}

#endif /* _VECT_ */
///////////////////////////////////////////////////////////