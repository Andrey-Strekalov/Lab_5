#ifndef FIGURE_H
#define FIGURE_H

#include <string>

// ����������� ������� ����� ��� �������������� �����
class Figure {
public:
    Figure(const std::string& id);  // ����������� � ���������������
    virtual ~Figure() = default;   // ����������� ����������

    // ����� ����������� ������ (������ ���� ����������� � ����������� �������)
    virtual double area() const = 0;       // ���������� �������
    virtual void move(double dx, double dy) = 0; // ����������� ������
    virtual void show() const = 0;         // ����������� ���������� � ������
    virtual std::string type() const = 0;  // ��������� ���� ������

    // ������ ��� ������ � ���������������
    std::string getId() const;      // ��������� �������������� ������
    int compare(const Figure* other) const; // ��������� ����� �� �������

protected:
    std::string id;  // ���������� ������������� ������
};

#endif