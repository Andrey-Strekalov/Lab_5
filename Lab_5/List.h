#ifndef LIST_H
#define LIST_H

#include "Node.h"
#include <stdexcept>  // ��� ������ � ������������
#include <string>     // ��� ��������� ��������� �� �������

// ����� ���������������� ������
template <typename T>
class List {
private:
    Node<T>* head;  // ��������� �� ������ ���� ������
    Node<T>* tail;  // ��������� �� ��������� ���� ������
    size_t size;    // ������� ���������� ��������� � ������

public:
    // ����������� �� ���������
    List();

    // ���������� (������������� ������� ������)
    ~List();

    // ���������� �������� � ����� ������
    void push_back(const T& value);

    // ���������� �������� � ������ ������
    void push_front(const T& value);

    // �������� ���������� �������� ������
    void pop_back();

    // �������� ������� �������� ������
    void pop_front();

    // ������ � ������� �������� ������
    T& front();

    // ������ � ���������� �������� ������
    T& back();

    // �������� �� ������� ������
    bool empty() const;

    // ��������� ���������� ��������� � ������
    size_t get_size() const;

    // ������� ������ (�������� ���� ���������)
    void clear();
};

// ���������� ������� ������

// �����������: ������������� ������� ������
template <typename T>
List<T>::List() : head(nullptr), tail(nullptr), size(0) {}

// ����������: �������������� ������� ������ ��� ����������� �������
template <typename T>
List<T>::~List() {
    clear();
}

// ���������� �������� � ����� ������
template <typename T>
void List<T>::push_back(const T& value) {
    // ������� ����� ����
    Node<T>* newNode = new Node<T>(value);

    if (empty()) {
        // ���� ������ ����, ����� ���� ���������� � �������, � �������
        head = tail = newNode;
    }
    else {
        // ������������ ����� ���� ����� �������� ������
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;  // ��������� ����� ������
    }
    size++;  // ����������� ������� ���������
}

// ���������� �������� � ������ ������
template <typename T>
void List<T>::push_front(const T& value) {
    // ������� ����� ����
    Node<T>* newNode = new Node<T>(value);

    if (empty()) {
        // ���� ������ ����, ����� ���� ���������� � �������, � �������
        head = tail = newNode;
    }
    else {
        // ������������ ����� ���� ����� ������� �������
        head->prev = newNode;
        newNode->next = head;
        head = newNode;  // ��������� ������ ������
    }
    size++;  // ����������� ������� ���������
}

// �������� ���������� �������� ������
template <typename T>
void List<T>::pop_back() {
    if (empty()) {
        // ��������� ���������� ��� ������� �������� �� ������� ������
        throw std::out_of_range("������ ����");
    }

    // ��������� ������ �� ��������� ����
    Node<T>* temp = tail;

    if (head == tail) {
        // ���� � ������ ������ ���� �������
        head = tail = nullptr;
    }
    else {
        // ���������� ����� �� ���������� �������
        tail = tail->prev;
        tail->next = nullptr;  // �������� ��������� �� ��������� �������
    }

    delete temp;  // ����������� ������
    size--;       // ��������� ������� ���������
}

// �������� ������� �������� ������
template <typename T>
void List<T>::pop_front() {
    if (empty()) {
        // ��������� ���������� ��� ������� �������� �� ������� ������
        throw std::out_of_range("������ ����");
    }

    // ��������� ������ �� ��������� ����
    Node<T>* temp = head;

    if (head == tail) {
        // ���� � ������ ������ ���� �������
        head = tail = nullptr;
    }
    else {
        // ���������� ������ �� ��������� �������
        head = head->next;
        head->prev = nullptr;  // �������� ��������� �� ���������� �������
    }

    delete temp;  // ����������� ������
    size--;       // ��������� ������� ���������
}

// ������ � ������� �������� ������
template <typename T>
T& List<T>::front() {
    if (empty()) {
        // ��������� ���������� ��� ��������� � ������� ������
        throw std::out_of_range("������ ����");
    }
    return head->data;
}

// ������ � ���������� �������� ������
template <typename T>
T& List<T>::back() {
    if (empty()) {
        // ��������� ���������� ��� ��������� � ������� ������
        throw std::out_of_range("������ ����");
    }
    return tail->data;
}

// �������� ������ �� �������
template <typename T>
bool List<T>::empty() const {
    return size == 0;
}

// ��������� �������� ������� ������
template <typename T>
size_t List<T>::get_size() const {
    return size;
}

// ������� ������ (�������� ���� ���������)
template <typename T>
void List<T>::clear() {
    // ��������������� ������� ��� �������� � ������ ������
    while (!empty()) {
        pop_front();
    }
}

#endif // LIST_H