#pragma once
#include <string>
#include <iostream>

using namespace std;

// Array.
template <size_t n, typename T>
class Array
{
private:
	size_t _size;
	T* _elements;
	Array(const Array& other);
	Array& operator=(const Array& other);

public:
	explicit Array();

	

	Array(Array&& other) noexcept;


	~Array();

	
	Array& operator=(Array&& other) noexcept;

	size_t size() const;

	T& operator [](size_t index);

	class BadArray;
};


// Exceptions Array.
template <size_t n, typename T>
class Array<n, T>::BadArray // NOLINT(cppcoreguidelines-special-member-functions, hicpp-special-member-functions)
{
private:
	const string _reason;
	const size_t _index;
public:
	explicit BadArray(string reason = "Unsigned exception", size_t index = 0);
	~BadArray();

	void diagnose() const;
};


// Constructor.
template <size_t n, typename T>
Array<n, T>::Array() : _size(n), _elements(new T[_size])
{
#ifndef NDEBUG
	cout << "Constructor array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif
}


// Destructor.
template <size_t n, typename T>
Array<n, T>::~Array()
{
	if (_elements != nullptr)
	{
		delete[] _elements;
		_elements = nullptr;
	}

#ifndef NDEBUG
	cout << "Destructor array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif
}


// Copy constructor.
template <size_t n, typename T>
Array<n, T>::Array(const Array& other): _size(other._size),
                                        _elements(new T[other.size()])
{

	copy(other._elements, other._elements, _elements);

#ifndef NDEBUG
	cout << "Copy Constructor array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif
}


// Move constructor.
template <size_t n, typename T>
Array<n, T>::Array(Array&& other) noexcept: _size(0),
                                            _elements(nullptr)
{
	_elements = other._elements;
	_size = other._size;

	other._elements = nullptr;
	other._size = 0;

#ifndef NDEBUG
	cout << "Move constructor array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif
}


// Copy assignment operator.
template <size_t n, typename T>
Array<n, T>& Array<n, T>::operator=(const Array& other)
{
	if (this == &other)
	{
		return *this;
	}

	delete[] _elements;
	_size = other.size();
	_elements = new T[_size];

	copy(other._elements, other._elements, _elements);

#ifndef NDEBUG
	cout << "Copy assignment array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif

	return *this;
}


// Move assignment operator.
template <size_t n, typename T>
Array<n, T>& Array<n, T>::operator=(Array&& other) noexcept
{
	if (this == &other)
		return *this;

	delete[] _elements;

	_elements = other._elements;
	_size = other._size;

	other._elements = nullptr;
	other._size = 0;


#ifndef NDEBUG
	cout << "Move assignment array size:" << n << "| type: " << typeid(_elements).name() << endl;
#endif


	return *this;
}


// Selector of arrays length
template <size_t n, typename T>
size_t Array<n, T>::size() const
{
	return _size;
}


// Arrays operator.
template <size_t n, typename T>
T& Array<n, T>::operator[](size_t index)
{
	if (index >= this->size() || index < 0)
	{
		throw BadArray("Bad index", index);
	}

	return _elements[index];
}


// Constructor. 
template <size_t n, typename T>
Array<n, T>::BadArray::BadArray(string reason, const size_t index) : _reason(std::move(reason)), _index(index)
{
}

// Destructor
template <size_t n, typename T>
Array<n, T>::BadArray::~BadArray()
= default;


// Reason of the exception with wrong index
template <size_t n, typename T>
void Array<n, T>::BadArray::diagnose() const
{
	cerr << _reason << ": " << _index << endl;
}
