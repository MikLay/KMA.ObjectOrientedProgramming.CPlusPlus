#pragma once
#include "Array.h"
#include <ostream>

template <class T>
class Sequence
{
private:
	size_t _size;
	size_t _capacity;
	static const size_t _default = 1;

	Array<T>* _allocator;

	T* _start;
	T* _end;
	mutable T* _current;

	void reduce(const size_t times = 2);
	void enlarge(const size_t times = 2);
	void update();

	Sequence& doinsert(const T&, const size_t);
	Sequence& doremove(const size_t);

public:
	explicit Sequence(const size_t capacity);

	~Sequence()
	{
	};

	size_t capacity() const { return _capacity; }
	size_t size() const { return _size; }
	bool empty() const { return size() == 0; }
	bool full() const { return size() == capacity(); }

	Sequence& clear();
	const T& operator[](const size_t index) const;
	T& operator[](const size_t index);

	Sequence& add(const T&);
	Sequence& insert(const T&, const size_t index);
	Sequence& cut();
	Sequence& remove(const size_t index);

	bool contains(const T&);

	Sequence& operator=(const Sequence&) = delete;
	Sequence(const Sequence&) = delete;

	void start() const { _current = _start; }
	void next() const { ++_current; }
	bool stop() const { return (_current == _end); }
	const T& getCurrent() const { return *_current; }
};

template <class T>
void Sequence<T>::reduce(const size_t times)
{
	size_t new_capacity = (capacity() / 2);

	if (new_capacity <= 0)
	{
		new_capacity = _default;
	}

	Array<T>* new_arr = new Array<T>(new_capacity);

	for (size_t i = 0; i < size(); ++i)
	{
		(*new_arr)[i] = (*_allocator)[i];
	}

	delete _allocator;
	_allocator = new Array<T>(new_capacity);

	for (size_t i = 0; i < size(); i++)
	{
		(*_allocator)[i] = (*new_arr)[i];
	}

	_capacity = new_capacity;
}

template <class T>
void Sequence<T>::enlarge(const size_t times)
{
	size_t new_capacity = capacity() * times + capacity();
	Array<T>* new_arr = new Array<T>(new_capacity);

	for (size_t i = 0; i < size(); ++i)
	{
		(*new_arr)[i] = (*_allocator)[i];
	}

	delete _allocator;
	_allocator = new Array<T>(new_capacity);

	for (size_t i = 0; i < size(); ++i)
	{
		(*_allocator)[i] = (*new_arr)[i];
	}

	_capacity = new_capacity;
}

template <class T>
void Sequence<T>::update()
{
	_start = &(*_allocator)[0];

	if (size() == 0)
	{
		_end = _start;
	}
	else
	{
		_end = &(*_allocator)[size() - 1];
	}
}

template <class T>
Sequence<T>& Sequence<T>::doinsert(const T& element, const size_t index)
{
	while (full())
	{
		enlarge();
	}

	for (size_t i = size(); i > index; --i)
	{
		(*this)[i] = (*this)[i - 1];
	}

	(*this)[index] = element;
	++_size;

	return *this;
}

template <class T>
Sequence<T>& Sequence<T>::doremove(const size_t index)
{
	for (size_t i = index; i < size(); ++i)
	{
		(*this)[i] = (*this)[i + 1];
	}

	--_size;

	return *this;
}

template <class T>
Sequence<T>::Sequence(const size_t my_capacity) : _capacity(my_capacity), _size(0),
                                                  _allocator(new Array<T>(my_capacity)),
                                                  _start(&(*_allocator)[0]), _end(&(*_allocator)[capacity() - 1])
{
	return;
}

template <class T>
Sequence<T>& Sequence<T>::clear()
{
	delete _allocator;
	_size = 0;
	_capacity = 0;

	return *this;
}

template <class T>
const T& Sequence<T>::operator[](const size_t index) const
{
	return (*_allocator)[index];
}

template <class T>
T& Sequence<T>::operator[](const size_t index)
{
	return (*_allocator)[index];
}

template <class T>
Sequence<T>& Sequence<T>::add(const T& element)
{
	while (full())
	{
		enlarge();
	}

	(*_allocator)[size()] = element;
	++_size;
	update();

	return *this;
}

template <class T>
Sequence<T>& Sequence<T>::insert(const T& element, const size_t index)
{
	doinsert(element, index);
	update();

	return *this;
}

template <class T>
Sequence<T>& Sequence<T>::cut()
{
	doremove(size() - 1);
	update();

	return *this;
}

template <class T>
Sequence<T>& Sequence<T>::remove(const size_t index)
{
	doremove(index);
	update();

	return *this;
}

template <class T>
bool Sequence<T>::contains(const T& element)
{
	start();

	while (stop())
	{
		if (getCurrent() == element)
		{
			return true;
		}

		next();
	}

	return false;
}

template <class T>
std::ostream& operator<<(ostream& os, const Sequence<T>& s)
{
	if (s.empty())
	{
		os << "Sequence is empty" << endl;
	}
	else
	{
		int i = 0;
		s.start();

		while (!s.stop())
		{
			os << "Sequence[" << i++ << "] : " << s.getCurrent() << endl;
			s.next();
		}

		os << "Sequence[" << i << "] : " << s.getCurrent() << endl;
	}

	return os << "Sequence size : " << s.size() << endl;
}
