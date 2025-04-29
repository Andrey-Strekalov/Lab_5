///////////////////////////////////////////////////////////
// codesrun_source.cpp (���������� ������� ������ Man)
///////////////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS // ���������� �������������� ������������

#include "../Lab_5/Man.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

// �����������
Man::Man(int lName) : birth_year(0), pay(0.0f) {
    std::cout << "Constructor is working" << std::endl;
    pName = new char[lName + 1](); // ��������� ������ � �������������� ������
}

// ����������
Man::~Man() {
    std::cout << "Destructor is working" << std::endl;
    delete[] pName; // ������������ ������
}

// ��������� ����� �� ������
void Man::SetName(const char* fromBuf) {
    std::strncpy(pName, fromBuf, l_name); // ����������� ������ 30 ��������
    pName[l_name] = '\0'; // ��������������� ���������� ������
}

// ��������� ���� ��������
void Man::SetBirthYear(const char* fromBuf) {
    // ����������� ��������� (������� 30-34) � �����
    birth_year = std::atoi(fromBuf + l_name);
}

// ��������� ��������
void Man::SetPay(const char* fromBuf) {
    // ����������� ��������� (������� 35-44) � ����� � ��������� ������
    pay = std::atof(fromBuf + l_name + l_year);
}

// ��������� �������
bool Man::CompareName(const char* name) const {
    size_t name_len = std::strlen(name);
    // ���������:
    // 1. ���������� ������ N �������� (����� ��������� �������)
    // 2. ������� ������� ����� �������
    return (std::strncmp(pName, name, name_len) == 0) &&
        (pName[name_len] == ' ');
}

// ����� ���������� � ����������
void Man::Print() const {
    std::cout << pName << " " << birth_year << " " << pay << std::endl;
}