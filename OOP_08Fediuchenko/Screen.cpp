#define _CRT_SECURE_NO_WARNINGS
//#define  NDEBUG

#include "Screen.h"
#include <iostream>
using namespace std;

const int Screen::maxHeight = 60;
const int Screen::maxWidth = 60;
const char Screen::_filler = '+';

Screen::Screen(int width, int height, const char* pc) : _height(height), _width(width), _cursor(0)
{
	if (_height > Screen::maxHeight)
	{
		_height = Screen::maxHeight;
	}

	if (_width > Screen::maxWidth)
	{
		_width = Screen::maxWidth;
	}


	_wContent = new char[_width * _height + 1];

	if (pc == 0)
	{
		for (int i = 0, length = _width * _height; i < length; ++i)
		{
			_wContent[i] = Screen::_filler;
		}

		_wContent[_width * _height] = '\0';
	}
	else
	{
		strcpy(_wContent, pc);
	}
#ifndef NDEBUG
	cout << "Screen has been created: " << this << endl;
#endif
	return;
}

Screen::~Screen()
{
	delete[] _wContent;
#ifndef NDEBUG
	cout << "Screen has been removed: " << this << endl;
#endif

	return;
}

const Screen& Screen::home() const
{
	_cursor = 0;

	return *this;
}

Screen& Screen::home()
{
	_cursor = 0;

	return *this;
}

const Screen& Screen::move() const
{
	if ((_width * _height) < (++_cursor))
	{
		_cursor = 0;
	}

	return *this;
}

Screen& Screen::move()
{
	if ((_width * _height) < (++_cursor))
	{
		_cursor = 0;
	}

	return *this;
}

const Screen& Screen::back() const
{
	if (--_cursor < 0)
	{
		_cursor = (_width * _height - 1);
	}

	return *this;
}

Screen& Screen::back()
{
	if (--_cursor < 0)
	{
		_cursor = (_width * _height - 1);
	}

	return *this;
}

const Screen& Screen::show() const
{
	home();

	for (auto i = 0; i < _height; ++i)
	{
		for (auto j = 0; j < _width; ++j)
		{
			cout << get();
			move();
		}

		cout << endl;
	}

	return *this;
}

Screen& Screen::show()
{
	home();
	cout << "___________________________\n";
	for (int i = 0; i < _height; ++i)
	{
		for (int j = 0; j < _width; ++j)
		{
			cout << get();
			move();
		}

		cout << endl;
	}
	cout << "___________________________\n";

	return *this;
}

const Screen& Screen::move(int i, int j) const
{
	if ((i >= _height) || (j >= _width))
	{
		_cursor = 0;
	}
	else
	{
		_cursor = (i * j);
	}

	return *this;
}

Screen& Screen::move(int i, int j)
{
	if ((i >= _height) || (j >= _width))
	{
		_cursor = 0;
	}
	else
	{
		_cursor = (i * j);
	}

	return *this;
}

Screen& Screen::clear()
{
	for (int i = 0, length = _width * _height; i < length; ++i)
	{
		_wContent[i] = Screen::_filler;
	}

	_wContent[_width * _height] = '\0';

	return *this;
}

const Screen& Screen::showCurrent() const
{
	cout << _wContent[_cursor];

	return *this;
}


Screen& Screen::set(char ch)
{
	_wContent[_cursor] = ch;

	return *this;
}

ostream& operator<<(ostream& os, const Screen& s)
{
	return os << endl << "|Width: " << s.width() << "|\n|Height: " << s.height() << "|\n|Content: " << s.content() <<
		"|\n";
}

void doActionConst(const Screen& s, ConstAction act, int n)
{
	for (auto i = 0; i < n; i++)
	{
		(s.*act)();
	}
}

void doActionNonConst(Screen& s, NonConstAction act, int n)
{
	for (auto i = 0; i < n; i++)
	{
		(s.*act)();
	}
}
