#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <stdexcept>  // Для работы с исключениями
#include <string>     // Для строковых сообщений об ошибках

// Класс двунаправленного списка
template <typename T>
class List {
private:
    Node<T>* head;  // Указатель на первый узел списка
    Node<T>* tail;  // Указатель на последний узел списка
    size_t size;    // Текущее количество элементов в списке

public:
    // Конструктор по умолчанию
    List();

    // Деструктор (автоматически очищает память)
    ~List();

    // Добавление элемента в конец списка
    void push_back(const T& value);

    // Добавление элемента в начало списка
    void push_front(const T& value);

    // Удаление последнего элемента списка
    void pop_back();

    // Удаление первого элемента списка
    void pop_front();

    // Доступ к первому элементу списка
    T& front();

    // Доступ к последнему элементу списка
    T& back();

    // Проверка на пустоту списка
    bool empty() const;

    // Получение количества элементов в списке
    size_t get_size() const;

    // Очистка списка (удаление всех элементов)
    void clear();
};

// Реализация методов списка

// Конструктор: инициализация пустого списка
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

// Деструктор: автоматическая очистка списка при уничтожении объекта
template <typename T>
List<T>::~List() {
    clear();
}

// Добавление элемента в конец списка
template <typename T>
void List<T>::push_back(const T& value) {
    // Создаем новый узел
    Node<T>* newNode = new Node<T>(value);

    if (empty()) {
        // Если список пуст, новый узел становится и головой, и хвостом
        head = tail = newNode;
    }
    else {
        // Присоединяем новый узел после текущего хвоста
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;  // Обновляем хвост списка
    }
    size++;  // Увеличиваем счетчик элементов
}

// Добавление элемента в начало списка
template <typename T>
void List<T>::push_front(const T& value) {
    // Создаем новый узел
    Node<T>* newNode = new Node<T>(value);

    if (empty()) {
        // Если список пуст, новый узел становится и головой, и хвостом
        head = tail = newNode;
    }
    else {
        // Присоединяем новый узел перед текущей головой
        head->prev = newNode;
        newNode->next = head;
        head = newNode;  // Обновляем голову списка
    }
    size++;  // Увеличиваем счетчик элементов
}

// Удаление последнего элемента списка
template <typename T>
void List<T>::pop_back() {
    if (empty()) {
        // Генерация исключения при попытке удаления из пустого списка
        throw std::out_of_range("Список пуст");
    }

    // Сохраняем ссылку на удаляемый узел
    Node<T>* temp = tail;

    if (head == tail) {
        // Если в списке только один элемент
        head = tail = nullptr;
    }
    else {
        // Перемещаем хвост на предыдущий элемент
        tail = tail->prev;
        tail->next = nullptr;  // Обнуляем указатель на следующий элемент
    }

    delete temp;  // Освобождаем память
    size--;       // Уменьшаем счетчик элементов
}

// Удаление первого элемента списка
template <typename T>
void List<T>::pop_front() {
    if (empty()) {
        // Генерация исключения при попытке удаления из пустого списка
        throw std::out_of_range("Список пуст");
    }

    // Сохраняем ссылку на удаляемый узел
    Node<T>* temp = head;

    if (head == tail) {
        // Если в списке только один элемент
        head = tail = nullptr;
    }
    else {
        // Перемещаем голову на следующий элемент
        head = head->next;
        head->prev = nullptr;  // Обнуляем указатель на предыдущий элемент
    }

    delete temp;  // Освобождаем память
    size--;       // Уменьшаем счетчик элементов
}

// Доступ к первому элементу списка
template <typename T>
T& List<T>::front() {
    if (empty()) {
        // Генерация исключения при обращении к пустому списку
        throw std::out_of_range("Список пуст");
    }
    return head->data;
}

// Доступ к последнему элементу списка
template <typename T>
T& List<T>::back() {
    if (empty()) {
        // Генерация исключения при обращении к пустому списку
        throw std::out_of_range("Список пуст");
    }
    return tail->data;
}

// Проверка списка на пустоту
template <typename T>
bool List<T>::empty() const {
    return size == 0;
}

// Получение текущего размера списка
template <typename T>
size_t List<T>::get_size() const {
    return size;
}

// Очистка списка (удаление всех элементов)
template <typename T>
void List<T>::clear() {
    // Последовательно удаляем все элементы с начала списка
    while (!empty()) {
        pop_front();
    }
}

#endif // LIST_H