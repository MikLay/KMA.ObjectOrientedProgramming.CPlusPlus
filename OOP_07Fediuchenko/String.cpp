#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <utility>
#include <string>
#include <iostream>


// ����������� ���������� �����
String::String() : _len(0), _allocator(new char[1])
{
	_allocator[0] = '\0';
	return;
}

// ����������� ����� �� ���������� ���������
String::String(const char* p_str)
{
	if (p_str == nullptr)
	{
		throw BadString("Attempt to use not defined constructor");
	}
	_len = strlen(p_str);
	_allocator = new char[_len + 1];
	strcpy(_allocator, p_str);
	return;
}

// ����������� ����� � ������ �������
String::String(const char c) : _len(1), _allocator(new char[2])
{
	_allocator[0] = c;
	_allocator[1] = '\0';
	return;
}


// ����������� ���������������
String::String(const String& s, int multiplayer) :
	// ���������� ������� �����������
	_len(s._len * multiplayer),
	// �������� ����� �� multiplayer �����
	_allocator(new char[_len + 1])
{
	// ����������� �������� ��� ������� ���������
	char* target = _allocator;
	for (int i = 0; i < multiplayer; i++)
	{
		strcpy(target, s._allocator); // ��������� ���� ��ﳿ
		target += s._len; // ���������� �������� ��� ����������� ���������
	}
	return;
}

String::~String()
{
	delete[] _allocator;
	_allocator = nullptr;
};

// ���������� ��������� �����
String& String::operator=(const String& s)
{
	if (this == &s) // �������� ����������� ��� �� ����� ������
		return *this;
	// ���� ��������� ���� ���� ��� �� ����� ������� ���
	delete[] _allocator; // ��������� ������� �����
	_len = s._len; // ���� �������� �������
	_allocator = new char[_len + 1]; // �������� ���� �� ���� ��������
	strcpy(_allocator, s._allocator); // ��������� ����� �� ���� ����
	return *this;
}

String& String::operator=(const string& s)
{
	const String temp_string(s);
	return (*this = temp_string);
}

String& String::operator=(const char* ps)
{
	if (ps == nullptr) // ���� �-����� ������������,
		return *this; // �� ��������, �� ������� this
	delete[] _allocator; // ��������� ������ �����
	for (_len = 0; ps[_len]; _len++); // ��������� ���� �������� �������
	_allocator = new char[_len + 1]; // �������� ���� ��� ������ ��������
	strcpy(_allocator, ps); // ������� ����� �� ���� ����
	return *this;
}

// �������� ��������� ������� �����
String& String::operator=(const char& c)
{
	delete[] _allocator; // ��������� ������ �����
	_len = 1; // ���������� ���� �������� ������
	_allocator = new char[2]; // �������� ���� ��� ������ ��������
	_allocator[0] = c; // ������� ����� �� ���� ����
	_allocator[1] = '\0';
	return *this;
}

// �������� ������������ ��� ����������� �������
char& String::operator[](const size_t i)
{
	if (_len <= i) throw BadString("Bad index: ", i);
	return _allocator[i];
};

// ������ ���������
ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++) os << s[i];
	return os;
}

// �������� ������������ ��� ������� �������
const char& String::operator[](const size_t i) const
{
	if (_len <= i) throw BadString("Bad index: ", i);
	return _allocator[i];
}

// �������� �������� �� ������
bool String::operator==(const String& s) const
{
	// ���� ������� �� �������, �� ����� �� ���
	bool equal = _len == s._len;
	for (size_t i = 0; (i < _len) && equal; i++)
		equal = *(_allocator + i) == *(s._allocator + i);
	return equal;
}

// �������� �������� �� ��������
bool String::operator!=(const String& s) const
{
	return !(*this == s);
}

// ��������, �� *this < s
bool String::operator<(const String& s) const
{
	// ���������� ���������
	bool res = true;
	size_t i = 0;
	// ���� �� ���������� ��������� � �� ������� �� ��� ������ � �����
	while (res && (i < _len) && (i < s._len))
	{
		res = res && (*(_allocator + i) == *(s._allocator + i));
		i++;
	}
	// ���� �� �������� ������� ��������, �� �������� ����� � �������
	if (res) return _len < s._len;
	i--;
	// ���� ������� ����� ���������, �� ������� ������
	// ������� �������� �����
	return *(_allocator + i) < *(s._allocator + i);
}

// ��������, �� *this <= s
bool String::operator<=(const String& s) const
{
	return *this == s ? true : *this < s;
}

bool String::operator>(const String& s) const
{
	return !(*this < s);
}

bool String::operator>=(const String& s) const
{
	return *this == s ? true : *this > s;
}

// �������� ��������� � �������������
String& String::operator+=(const String& s)
{
	const size_t len = _len + s._len; // ������� ���������� ������������
	// ReSharper disable once CppUseAuto
	char* newAllocator = new char[len + 1]; // �������� ���� �� ���������
	strcpy(newAllocator, _allocator); // ���������� ������� �����
	// �� ���� ����
	delete[] _allocator; // ���������� ���� ������������ ������������
	_allocator = newAllocator; // ��������������� �������� �� �����
	strcpy(_allocator + _len, s._allocator); // ����������� ������� �����
	// � ����� ��������������� ����
	_len = len; // �����'���������� ������� ������ �����
	return *this; // ����� ��� ��������� ����������
}

String& String::operator+=(const string& s)
{
	const String tempS(s);
	return (*this += tempS);
}

// �������� ������������, ��������� �� ���������
// ��������� ���������
String String::operator+(const String& s) const
{
	// ReSharper disable CppUseAuto
	String res(*this);
	// ReSharper restore CppUseAuto
	return res += s;
}

// ��������� ������������ �� �-������
String& String::operator+=(const char* ps)
{
	if (ps == nullptr) return *this; // ������������ ������� ��������
	// ReSharper disable once CppLocalVariableMayBeConst
	// ReSharper disable once CppUseAuto
	size_t len = strlen(ps); // ���������� ������� ����� ps
	// ReSharper disable once CppUseAuto
	char* newAllocator = new char[len + _len + 1]; // �������� ���� ��
	// ���������
	strcpy(newAllocator, _allocator); // ���������� ������� �����
	// �� ���� ����
	delete[] _allocator; // ���������� ���� ������������ ������������
	_allocator = newAllocator; // ��������������� �������� �� �����
	strcpy(_allocator + _len, ps); // ����������� ������� �����
	// � ����� ��������������� ����
	_len += len; // �����'���������� ������� ������ �����
	return *this; // ����� ��� ��������� ����������
}

// ����������� � ��������� string �� String
String::String(const string& s) :
	_len(s.length()), _allocator(new char[s.length() + 1])
{
	strcpy(_allocator, s.c_str());
	return;
}

// �������� ������������ ���� String �� string
// ReSharper disable once CppConstValueFunctionReturnType
// ReSharper disable once CppInconsistentNaming
const string String::STL_string() const
{
	return string(_allocator);
}

// ̳��� ������������ ����� �������� ���� ��� �������
const char* String::c_str() const
{
	return _allocator;
}

size_t String::length() const
{
	return _len;
}

bool String::empty() const
{
	return _len == 0;
}

void String::clear()
{
	delete[] _allocator;
	_len = 0;
	_allocator = new char[1];
	_allocator[0] = '\0';
}
