#ifndef DEQUE_H
#define DEQUE_H

#include "List.h"

// Класс двусторонней очереди (дека), реализованный на основе списка
template <typename T>
class Deque {
private:
    List<T> list;  // Внутренний список для хранения элементов

public:
    // Добавление элемента в начало дека
    void push_front(const T& value);

    // Добавление элемента в конец дека
    void push_back(const T& value);

    // Удаление элемента из начала дека
    void pop_front();

    // Удаление элемента из конца дека
    void pop_back();

    // Доступ к первому элементу дека
    T& front();

    // Доступ к последнему элементу дека
    T& back();

    // Проверка дека на пустоту
    bool empty() const;

    // Получение количества элементов в деке
    size_t size() const;
};

// Реализация методов дека

// Добавление элемента в начало дека
template <typename T>
void Deque<T>::push_front(const T& value) {
    list.push_front(value);  // Делегируем операцию списку
}

// Добавление элемента в конец дека
template <typename T>
void Deque<T>::push_back(const T& value) {
    list.push_back(value);  // Делегируем операцию списку
}

// Удаление элемента из начала дека
template <typename T>
void Deque<T>::pop_front() {
    list.pop_front();  // Делегируем операцию списку
}

// Удаление элемента из конца дека
template <typename T>
void Deque<T>::pop_back() {
    list.pop_back();  // Делегируем операцию списку
}

// Доступ к первому элементу дека
template <typename T>
T& Deque<T>::front() {
    return list.front();  // Делегируем операцию списку
}

// Доступ к последнему элементу дека
template <typename T>
T& Deque<T>::back() {
    return list.back();  // Делегируем операцию списку
}

// Проверка дека на пустоту
template <typename T>
bool Deque<T>::empty() const {
    return list.empty();  // Делегируем операцию списку
}

// Получение количества элементов в деке
template <typename T>
size_t Deque<T>::size() const {
    return list.get_size();  // Делегируем операцию списку
}

#endif // DEQUE_H