#include "figure.h"
#include <cmath>

// ���������� ������� �������� ������ Figure

// �����������
Figure::Figure(const std::string& id) : id(id) {}

// ��������� �������������� ������
std::string Figure::getId() const {
    return id;
}

// ��������� ���� ����� �� �������
int Figure::compare(const Figure* other) const {
    double a1 = area();      // ������� ������� ������
    double a2 = other->area(); // ������� ������������ ������

    // ��������� � ������ ����������� ����������
    if (std::fabs(a1 - a2) < 1e-9) return 0; // ������� �����
    return (a1 < a2) ? -1 : 1; // -1 ���� ������� ������, 1 ���� ������
}