#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <utility>

// ����� �������������� (��������� Figure)
class Rectangle : public Figure {
public:
    // ����������� � ����������� �����
    Rectangle(const std::string& id,
        double x1, double y1,
        double x2, double y2);

    // ���������� ����������� �������
    double area() const override;      // ���������� �������
    void move(double dx, double dy) override; // �����������
    void show() const override;        // ����������� ����������
    std::string type() const override; // ���������� ��� ������

private:
    std::pair<double, double> topLeft;     // ����� ������� ����
    std::pair<double, double> bottomRight; // ������ ������ ����
};

#endif