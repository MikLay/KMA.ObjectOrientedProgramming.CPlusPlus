#pragma once
//Доповнити наведену нижче специфікаію до власного класу рядків String,

//забезпечивши можливість виконання змішаних операцій

//над власними рядками, С-рядками і STL-рядками

#include <utility>
#include <string>
#include <iostream>
using namespace std;

class String

{
private:

	size_t _len;

	char* _allocator;


public:

	class BadString;

	String();

	explicit String(const char*);

	String(const char);

	explicit String(const string&);

	String(const String & s, int multiplayer = 1);


	~String();


	String& operator=(const char*);

	String& operator=(const char&);


	// ReSharper disable CppInconsistentNaming
	const string STL_string() const;
	// ReSharper restore CppInconsistentNaming

	// ReSharper disable once CppInconsistentNaming
	const char* c_str() const;

	size_t length() const;


	bool empty() const;

	void clear();


	char& operator[](size_t);

	const char& operator[](size_t) const;


	bool operator == (const String&) const;

	bool operator != (const String&) const;


	bool operator < (const String&) const;

	bool operator <= (const String&) const;

	bool operator > (const String&) const;

	bool operator >= (const String&) const;


	String operator+(const String&) const;

	String& operator=(const String&);

	String& operator=(const string&);

	String& operator+=(const char*);

	String& operator+=(const String&);

	String& operator+=(const string&);

};


ostream& operator<<(ostream&, const String&);


class String::BadString {
private:
	const string _reason; // Причина аварійної ситуації
	const size_t _index; // Символ, на обробці якого вона виникла
public:
	explicit BadString(string reason = "", const size_t index = 0) :
		_reason(std::move((reason))), _index(index) {
		return;
	}
	~BadString() = default;
	// Діагностичне повідомлення
	void diagnose() const
	{
		cerr << _reason << endl;
		if (_index != 0)
			cerr <<""<< _index << endl;
	}
};