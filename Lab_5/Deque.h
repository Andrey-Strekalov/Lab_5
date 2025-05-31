#ifndef DEQUE_H
#define DEQUE_H

#include "List.h"

// ����� ������������ ������� (����), ������������� �� ������ ������
template <typename T>
class Deque {
private:
    List<T> list;  // ���������� ������ ��� �������� ���������

public:
    // ���������� �������� � ������ ����
    void push_front(const T& value);

    // ���������� �������� � ����� ����
    void push_back(const T& value);

    // �������� �������� �� ������ ����
    void pop_front();

    // �������� �������� �� ����� ����
    void pop_back();

    // ������ � ������� �������� ����
    T& front();

    // ������ � ���������� �������� ����
    T& back();

    // �������� ���� �� �������
    bool empty() const;

    // ��������� ���������� ��������� � ����
    size_t size() const;
};

// ���������� ������� ����

// ���������� �������� � ������ ����
template <typename T>
void Deque<T>::push_front(const T& value) {
    list.push_front(value);  // ���������� �������� ������
}

// ���������� �������� � ����� ����
template <typename T>
void Deque<T>::push_back(const T& value) {
    list.push_back(value);  // ���������� �������� ������
}

// �������� �������� �� ������ ����
template <typename T>
void Deque<T>::pop_front() {
    list.pop_front();  // ���������� �������� ������
}

// �������� �������� �� ����� ����
template <typename T>
void Deque<T>::pop_back() {
    list.pop_back();  // ���������� �������� ������
}

// ������ � ������� �������� ����
template <typename T>
T& Deque<T>::front() {
    return list.front();  // ���������� �������� ������
}

// ������ � ���������� �������� ����
template <typename T>
T& Deque<T>::back() {
    return list.back();  // ���������� �������� ������
}

// �������� ���� �� �������
template <typename T>
bool Deque<T>::empty() const {
    return list.empty();  // ���������� �������� ������
}

// ��������� ���������� ��������� � ����
template <typename T>
size_t Deque<T>::size() const {
    return list.get_size();  // ���������� �������� ������
}

#endif // DEQUE_H