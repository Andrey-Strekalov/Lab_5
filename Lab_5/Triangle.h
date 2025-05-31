#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <vector>
#include <utility>

// ����� ������������ (��������� Figure)
class Triangle : public Figure {
public:
    // ����������� � ����������� ������
    Triangle(const std::string& id,
        double x1, double y1,
        double x2, double y2,
        double x3, double y3);

    // ���������� ����������� �������
    double area() const override;      // ���������� ������� ������������
    void move(double dx, double dy) override; // ����������� ������������
    void show() const override;        // ����������� ����������
    std::string type() const override; // ���������� ��� ������

private:
    std::vector<std::pair<double, double>> vertices; // ���������� ������
};

#endif