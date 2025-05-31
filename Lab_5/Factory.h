#ifndef FACTORY_H
#define FACTORY_H

#include "figure.h"
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

// �����-������� ��� ���������� ��������������� ���������
class Factory {
public:
    // ������ ��� ������ � ���������
    void createTriangle();  // �������� ������������
    void createRectangle(); // �������� ��������������
    void deleteObject(const std::string& id); // �������� ������� �� ID
    void showAll() const;   // ����������� ���� ��������
    void moveObject(const std::string& id); // ����������� �������
    void compareObjects();  // ��������� ���� �������� �� �������

private:
    std::vector<std::unique_ptr<Figure>> figures; // ��������� ��������

    // ���������� ����� ��� ������ ������� �� ID
    Figure* findObject(const std::string& id) const;
};

#endif