#ifndef NODE_H
#define NODE_H

// Класс узла для двунаправленного списка
template <typename T>
struct Node {
    T data;         // Данные, хранящиеся в узле
    Node* prev;     // Указатель на предыдущий узел
    Node* next;     // Указатель на следующий узел

    // Конструктор узла
    // Принимает значение для хранения
    Node(const T& value);
};

// Реализация конструктора узла
template <typename T>
Node<T>::Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}

#endif // NODE_H