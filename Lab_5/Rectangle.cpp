#include "rectangle.h"
#include <iostream>
#include <iomanip>
#include <cmath>

// ���������� ������� ������ Rectangle

// �����������
Rectangle::Rectangle(const std::string& id, double x1, double y1, double x2, double y2)
    : Figure(id), topLeft({ x1, y1 }), bottomRight({ x2, y2 }) {}

// ���������� ������� ��������������
double Rectangle::area() const {
    auto [x1, y1] = topLeft;
    auto [x2, y2] = bottomRight;
    return std::fabs((x2 - x1) * (y2 - y1)); // |������ * ������|
}

// ����������� ��������������
void Rectangle::move(double dx, double dy) {
    topLeft.first += dx;        // �������� ������ �������� ���� �� X
    topLeft.second += dy;       // �������� ������ �������� ���� �� Y
    bottomRight.first += dx;    // �������� ������� ������� ���� �� X
    bottomRight.second += dy;   // �������� ������� ������� ���� �� Y
}

// ����� ���������� � ��������������
void Rectangle::show() const {
    auto [x1, y1] = topLeft;
    auto [x2, y2] = bottomRight;
    std::cout << "������������� ID: " << id
        << ", �������: " << std::fixed << std::setprecision(2) << area()
        << ", �������-�����: (" << x1 << ", " << y1 << ")"
        << ", ������-������: (" << x2 << ", " << y2 << ")"
        << std::endl;
}

// ���������� ��� ������
std::string Rectangle::type() const {
    return "�������������";
}