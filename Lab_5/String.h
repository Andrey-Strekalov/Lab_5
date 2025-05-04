//////////////////////////////////
//////  String.h

#pragma once

#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>
#include <sstream>
#include <stdexcept>
#include <cstdio>

class String {
private:
    char* data;     // ��������� �� ������ ��������
    size_t length;  // ����� ������

    // ��������������� ������ ��� ������ � �������
    void allocate_memory(size_t size);  // ��������� ������
    void safe_delete();                 // ���������� ������������ ������

public:
    // ������������ � ����������
    String();                           // ����������� �� ���������
    String(const char* str);            // ����������� �� C-������
    String(const String& other);        // ����������� �����������
    ~String();                          // ����������

    // ������� ��������
    size_t size() const;                // �������� ����� ������
    const char* c_str() const;          // �������� C-������

    // ������������� ���������
    String& operator=(const String& other);  // �������� ������������
    String operator+(const String& other) const; // ������������ �����

    // ��������� ���������
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    bool operator<(const String& other) const;
    bool operator>(const String& other) const;

    // ���������� � �������� �����
    template<typename T>
    explicit operator T() const {
        std::istringstream iss(data);
        T value;
        iss >> value;
        if (iss.fail()) {
            throw std::runtime_error("���������� ������������� ������ � �����");
        }
        return value;
    }

    // ��������������� ����� (������ printf)
    template<typename... Args>
    static String format(const char* fmt, Args... args) {
        // ����������� ������������ ������� ������
        size_t size = snprintf(nullptr, 0, fmt, args...) + 1;
        char* buffer = new char[size];

        // �������������� ������
        snprintf(buffer, size, fmt, args...);
        String result(buffer);

        // ������� ���������� ������
        delete[] buffer;
        return result;
    }
};

#endif
