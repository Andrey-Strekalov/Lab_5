#ifndef NODE_H
#define NODE_H

// ����� ���� ��� ���������������� ������
template <typename T>
struct Node {
    T data;         // ������, ���������� � ����
    Node* prev;     // ��������� �� ���������� ����
    Node* next;     // ��������� �� ��������� ����

    // ����������� ����
    // ��������� �������� ��� ��������
    Node(const T& value);
};

// ���������� ������������ ����
template <typename T>
Node<T>::Node(const T& value) : data(value), prev(nullptr), next(nullptr) {}

#endif // NODE_H