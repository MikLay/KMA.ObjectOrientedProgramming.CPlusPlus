#define _CRT_SECURE_NO_WARNINGS
#include "String.h"
#include <utility>
#include <string>
#include <iostream>


// Конструктор порожнього рядка
String::String() : _len(0), _allocator(new char[1])
{
	_allocator[0] = '\0';
	return;
}

// Конструктор рядка за символьним указником
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

// Конструктор рядка з одного символу
String::String(const char c) : _len(1), _allocator(new char[2])
{
	_allocator[0] = c;
	_allocator[1] = '\0';
	return;
}


// Конструктор мультикопіювання
String::String(const String& s, int multiplayer) :
	// Обчислення довжини мультирядка
	_len(s._len * multiplayer),
	// Виділення пам’яті під multiplayer рядків
	_allocator(new char[_len + 1])
{
	// Ініціалізація указника для початку копіювання
	char* target = _allocator;
	for (int i = 0; i < multiplayer; i++)
	{
		strcpy(target, s._allocator); // Створення однієї копії
		target += s._len; // Переміщення указника для продовження копіювання
	}
	return;
}

String::~String()
{
	delete[] _allocator;
	_allocator = nullptr;
};

// Копіювальне присвоєння рядків
String& String::operator=(const String& s)
{
	if (this == &s) // Перевірка пристайності лівої та правої частин
		return *this;
	// Сюди потрапимо лише коли ліва та права частини різні
	delete[] _allocator; // Видалення старого рядка
	_len = s._len; // Нове значення довжини
	_allocator = new char[_len + 1]; // Виділення місця під нове значення
	strcpy(_allocator, s._allocator); // Копіювання рядка на нове місце
	return *this;
}

String& String::operator=(const string& s)
{
	const String temp_string(s);
	return (*this = temp_string);
}

String& String::operator=(const char* ps)
{
	if (ps == nullptr) // Якщо С-рядок невизначений,
		return *this; // то виходимо, не змінюючи this
	delete[] _allocator; // Видаляємо старий рядок
	for (_len = 0; ps[_len]; _len++); // Знаходимо нове значення довжини
	_allocator = new char[_len + 1]; // Виділяємо місце для нового значення
	strcpy(_allocator, ps); // Копіюємо рядок на нове місце
	return *this;
}

// Оператор присвоєння символу рядку
String& String::operator=(const char& c)
{
	delete[] _allocator; // Видаляємо старий рядок
	_len = 1; // Присвоюємо нове значення довжині
	_allocator = new char[2]; // Виділяємо місце для нового значення
	_allocator[0] = c; // Копіюємо рядок на нове місце
	_allocator[1] = '\0';
	return *this;
}

// Оператор індексування для модифікації символу
char& String::operator[](const size_t i)
{
	if (_len <= i) throw BadString("Bad index: ", i);
	return _allocator[i];
};

// Утиліта виведення
ostream& operator<<(ostream& os, const String& s)
{
	for (size_t i = 0; i < s.length(); i++) os << s[i];
	return os;
}

// Оператор індексування для читання символу
const char& String::operator[](const size_t i) const
{
	if (_len <= i) throw BadString("Bad index: ", i);
	return _allocator[i];
}

// Оператор перевірки на рівність
bool String::operator==(const String& s) const
{
	// Якщо довжини не однакові, то рядки не рівні
	bool equal = _len == s._len;
	for (size_t i = 0; (i < _len) && equal; i++)
		equal = *(_allocator + i) == *(s._allocator + i);
	return equal;
}

// Оператор перевірки на нерівність
bool String::operator!=(const String& s) const
{
	return !(*this == s);
}

// Перевірка, чи *this < s
bool String::operator<(const String& s) const
{
	// Припускаємо істинність
	bool res = true;
	size_t i = 0;
	// Доки не порушиться істинність і не вийдемо за межі одного з рядків
	while (res && (i < _len) && (i < s._len))
	{
		res = res && (*(_allocator + i) == *(s._allocator + i));
		i++;
	}
	// Якщо всі попередні символи збігалися, то коротший рядок – «менший»
	if (res) return _len < s._len;
	i--;
	// Якщо знайшли першу розбіжність, то «менший» символ
	// відповідає «меншому» рядку
	return *(_allocator + i) < *(s._allocator + i);
}

// Перевірка, чи *this <= s
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

// Оператор присвоєння з конкатенацією
String& String::operator+=(const String& s)
{
	const size_t len = _len + s._len; // Довжина результату конкатенації
	// ReSharper disable once CppUseAuto
	char* newAllocator = new char[len + 1]; // Виділення місця під результат
	strcpy(newAllocator, _allocator); // Переміщення першого рядка
	// на нове місце
	delete[] _allocator; // Вивільнення місця попереднього розташування
	_allocator = newAllocator; // Переспрямування указника на рядок
	strcpy(_allocator + _len, s._allocator); // Дописування другого рядка
	// в кінець зарезервованого місця
	_len = len; // Запам'ятовування довжини нового рядка
	return *this; // Вихід без копіювання результату
}

String& String::operator+=(const string& s)
{
	const String tempS(s);
	return (*this += tempS);
}

// Оператор конкатенації, реалізація за допомогою
// суміщеного присвоєння
String String::operator+(const String& s) const
{
	// ReSharper disable CppUseAuto
	String res(*this);
	// ReSharper restore CppUseAuto
	return res += s;
}

// Присвоєння конкатенації із С-рядком
String& String::operator+=(const char* ps)
{
	if (ps == nullptr) return *this; // Невизначений указник ігноруємо
	// ReSharper disable once CppLocalVariableMayBeConst
	// ReSharper disable once CppUseAuto
	size_t len = strlen(ps); // Обчислення довжини рядка ps
	// ReSharper disable once CppUseAuto
	char* newAllocator = new char[len + _len + 1]; // Виділення місця під
	// результат
	strcpy(newAllocator, _allocator); // Переміщення першого рядка
	// на нове місце
	delete[] _allocator; // Вивільнення місця попереднього розташування
	_allocator = newAllocator; // Переспрямування указника на рядок
	strcpy(_allocator + _len, ps); // Дописування другого рядка
	// в кінець зарезервованого місця
	_len += len; // Запам'ятовування довжини нового рядка
	return *this; // Вихід без копіювання результату
}

// Конструктор і конвертор string до String
String::String(const string& s) :
	_len(s.length()), _allocator(new char[s.length() + 1])
{
	strcpy(_allocator, s.c_str());
	return;
}

// Оператор перетворення типу String до string
// ReSharper disable once CppConstValueFunctionReturnType
// ReSharper disable once CppInconsistentNaming
const string String::STL_string() const
{
	return string(_allocator);
}

// Місце розташування рядка доступне лише для читання
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
