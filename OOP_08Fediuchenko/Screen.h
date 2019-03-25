#pragma once
#include <ostream>

using namespace std;

//Запрограмувати меню для роботи з текстовим екраном.

//

//Текстовий екран максимальним розміром

//maxHeigh х maxWidth

//

class Screen

{
public:

	//Екран заповнюється рядком pc,

	//якщо він заданий, інакше він наповнюється

	//наповнювачем _filler

	Screen(int, int, const char* pc = 0);

	~Screen();


	//Сталітаїмоднойменніметоди

	//Перевести курсор на початок екрану

	const Screen& home() const;

	Screen& home();


	//Посунути курсор на один символ вправо

	const Screen& move() const;

	Screen& move();


	//Посунути курсор на один символ вліво

	const Screen& back() const;

	Screen& back();


	//Показативмістекрану

	const Screen& show() const;

	Screen& show();


	//Перенести курсор на задану позицію

	const Screen& move(int, int) const;

	Screen& move(int, int);


	//Очистити екран

	Screen& clear();


	//Показати символ, на якому знаходиться курсор

	const Screen& showCurrent() const;


	//Селектор

	char get() const
	{
		return _wContent[_cursor];
	}

	int width() const { return _width; }
	int height() const { return _height; }
	const char* content() const { return _wContent; }


	//Модифікатор

	Screen& set(char);


	//Копіювання екранів не передбачене
	Screen(const Screen&) = delete;

	Screen& operator=(const Screen&) = delete;


private:

	//Максимальна висота екрану

	static const int maxHeight;

	//Максимальна ширина екрану

	static const int maxWidth;

	//Наповнювач

	static const char _filler;


	//Фактична висота екрану

	int _height;

	//Фактична ширина екрану

	int _width;

	//Наповнення екрану

	char* _wContent;

	//Курсор

	mutable int _cursor;
};


ostream& operator<<(std::ostream&, const Screen&);


typedef const Screen& (Screen::* const ConstAction)() const;

typedef Screen& (Screen::* const NonConstAction)();


void doActionConst(const Screen& s, ConstAction act, int n);

void doActionNonConst(Screen& s, NonConstAction act, int n);
