///////////////////////////////////////////////////////////
// Header.h (������������ ���� ������ Man)
///////////////////////////////////////////////////////////

#pragma once
#include <cstring>

class Man {
public:
    // ��������� ��� �������� �����
    static const int l_name = 30; // ����� ���� ���
    static const int l_year = 5;  // ����� ���� ���� ��������
    static const int l_pay = 10;  // ����� ���� ��������
    static const int l_buf = l_name + l_year + l_pay; // ����� ����� ������

    // ����������� � ����������
    Man(int lName = l_name);
    ~Man();

    // ������ ������ � �������
    bool CompareName(const char* name) const; // ��������� �������
    int GetBirthYear() const { return birth_year; } // ������ ���� ��������
    float GetPay() const { return pay; }       // ������ ��������
    const char* GetName() const { return pName; } // ������ �����

    void Print() const;               // ����� ����������
    void SetBirthYear(const char* fromBuf); // ��������� ���� ��������
    void SetName(const char* fromBuf);      // ��������� �����
    void SetPay(const char* fromBuf);       // ��������� ��������

private:
    char* pName;        // ������������ ������ ��� �������� ���
    int birth_year;     // ��� ��������
    float pay;          // ��������
};