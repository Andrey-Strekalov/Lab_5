#include "factory.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>
#include <memory>
#include <algorithm>

// ���������� ������� �������

// �������� ������ ������������
void Factory::createTriangle() {
    std::string id;
    std::cout << "������� ID ������������: ";
    std::cin >> id;

    // �������� �� ������������ ID
    if (findObject(id)) {
        std::cout << "������: ������ � ����� ID ��� ����������!\n";
        return;
    }

    // ���� ��������� ������
    double x1, y1, x2, y2, x3, y3;
    std::cout << "������� ������� 1 (x y): ";
    std::cin >> x1 >> y1;
    std::cout << "������� ������� 2 (x y): ";
    std::cin >> x2 >> y2;
    std::cout << "������� ������� 3 (x y): ";
    std::cin >> x3 >> y3;

    // �������� � ���������� ������������
    figures.push_back(std::make_unique<Triangle>(id, x1, y1, x2, y2, x3, y3));
    std::cout << "����������� ������� ������!\n";
}

// �������� ������ ��������������
void Factory::createRectangle() {
    std::string id;
    std::cout << "������� ID ��������������: ";
    std::cin >> id;

    // �������� �� ������������ ID
    if (findObject(id)) {
        std::cout << "������: ������ � ����� ID ��� ����������!\n";
        return;
    }

    // ���� ��������� �����
    double x1, y1, x2, y2;
    std::cout << "������� �������-����� ���� (x y): ";
    std::cin >> x1 >> y1;
    std::cout << "������� ������-������ ���� (x y): ";
    std::cin >> x2 >> y2;

    // �������� � ���������� ��������������
    figures.push_back(std::make_unique<Rectangle>(id, x1, y1, x2, y2));
    std::cout << "������������� ������� ������!\n";
}

// �������� ������� �� ID
void Factory::deleteObject(const std::string& id) {
    // ����� � �������� �������
    auto it = std::remove_if(figures.begin(), figures.end(),
        [&](const auto& obj) { return obj->getId() == id; });

    if (it != figures.end()) {
        figures.erase(it, figures.end()); // �������� �� ���������
        std::cout << "������ ������� ������!\n";
    }
    else {
        std::cout << "������: ������ �� ������!\n";
    }
}

// ����������� ���� ��������
void Factory::showAll() const {
    if (figures.empty()) {
        std::cout << "� ���� ������ ��� ��������\n";
        return;
    }

    std::cout << "\n--- ��� ������� ---\n";
    for (const auto& fig : figures) {
        fig->show(); // ����� ������ show ��� ������� �������
    }
    std::cout << "------------------\n";
}

// ����������� �������
void Factory::moveObject(const std::string& id) {
    Figure* obj = findObject(id); // ����� �������
    if (!obj) {
        std::cout << "������: ������ �� ������!\n";
        return;
    }

    // ���� ������� �����������
    double dx, dy;
    std::cout << "������� ������ ����������� (dx dy): ";
    std::cin >> dx >> dy;

    obj->move(dx, dy); // ����� ������ move
    std::cout << "������ ������� ���������!\n";
}

// ��������� ���� �������� �� �������
void Factory::compareObjects() {
    std::string id1, id2;
    std::cout << "������� ID ������� �������: ";
    std::cin >> id1;
    std::cout << "������� ID ������� �������: ";
    std::cin >> id2;

    // ����� ��������
    Figure* obj1 = findObject(id1);
    Figure* obj2 = findObject(id2);

    if (!obj1 || !obj2) {
        std::cout << "������: ���� ��� ��� ������� �� �������!\n";
        return;
    }

    // ��������� ��������
    int result = obj1->compare(obj2);
    std::cout << "��������� ���������: ";
    if (result == 0) {
        std::cout << "������� ����� ������ �������";
    }
    else if (result < 0) {
        std::cout << obj1->getId() << " < " << obj2->getId();
    }
    else {
        std::cout << obj1->getId() << " > " << obj2->getId();
    }
    std::cout << " (" << obj1->type() << " vs " << obj2->type() << ")\n";
}

// ����� ������� �� ID
Figure* Factory::findObject(const std::string& id) const {
    for (const auto& fig : figures) {
        if (fig->getId() == id) {
            return fig.get(); // ������� ��������� �� ��������� ������
        }
    }
    return nullptr; // ������ �� ������
}