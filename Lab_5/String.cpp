//////////////////////////////////
//////  String.cpp

#include "String.h"

// ��������� ������ � ������� ����������
void String::allocate_memory(size_t size) {
    data = new char[size + 1];
    data[size] = '\0';
}

// ���������� �������� ������
void String::safe_delete() {
    delete[] data;
    data = nullptr;
}

// ����������� �� ��������� (������ ������)
String::String() : data(nullptr), length(0) {
    allocate_memory(0);
}

// ����������� �� C-������
String::String(const char* str) : data(nullptr), length(strlen(str)) {
    allocate_memory(length);
    strcpy(data, str);
}

// ����������� �����������
String::String(const String& other) : data(nullptr), length(other.length) {
    allocate_memory(length);
    strcpy(data, other.data);
}

// ����������
String::~String() {
    safe_delete();
}

// ��������� ����� ������
size_t String::size() const {
    return length;
}

// ��������� C-������
const char* String::c_str() const {
    return data;
}

// �������� ������������
String& String::operator=(const String& other) {
    if (this != &other) {
        safe_delete();
        length = other.length;
        allocate_memory(length);
        strcpy(data, other.data);
    }
    return *this;
}

// ������������ �����
String String::operator+(const String& other) const {
    String result;
    result.length = length + other.length;
    result.allocate_memory(result.length);
    strcpy(result.data, data);
    strcat(result.data, other.data);
    return result;
}

// ��������� ���������
bool String::operator==(const String& other) const {
    return strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

bool String::operator<(const String& other) const {
    return strcmp(data, other.data) < 0;
}

bool String::operator>(const String& other) const {
    return strcmp(data, other.data) > 0;
}
