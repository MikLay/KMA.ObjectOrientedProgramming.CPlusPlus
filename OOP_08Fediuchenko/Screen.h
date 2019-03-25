#pragma once
#include <ostream>

using namespace std;

//�������������� ���� ��� ������ � ��������� �������.

//

//��������� ����� ������������ �������

//maxHeigh � maxWidth

//

class Screen

{
public:

	//����� ������������ ������ pc,

	//���� �� �������, ������ �� ������������

	//������������ _filler

	Screen(int, int, const char* pc = 0);

	~Screen();


	//����������������������

	//��������� ������ �� ������� ������

	const Screen& home() const;

	Screen& home();


	//�������� ������ �� ���� ������ ������

	const Screen& move() const;

	Screen& move();


	//�������� ������ �� ���� ������ ����

	const Screen& back() const;

	Screen& back();


	//������������������

	const Screen& show() const;

	Screen& show();


	//��������� ������ �� ������ �������

	const Screen& move(int, int) const;

	Screen& move(int, int);


	//�������� �����

	Screen& clear();


	//�������� ������, �� ����� ����������� ������

	const Screen& showCurrent() const;


	//��������

	char get() const
	{
		return _wContent[_cursor];
	}

	int width() const { return _width; }
	int height() const { return _height; }
	const char* content() const { return _wContent; }


	//�����������

	Screen& set(char);


	//��������� ������ �� �����������
	Screen(const Screen&) = delete;

	Screen& operator=(const Screen&) = delete;


private:

	//����������� ������ ������

	static const int maxHeight;

	//����������� ������ ������

	static const int maxWidth;

	//����������

	static const char _filler;


	//�������� ������ ������

	int _height;

	//�������� ������ ������

	int _width;

	//���������� ������

	char* _wContent;

	//������

	mutable int _cursor;
};


ostream& operator<<(std::ostream&, const Screen&);


typedef const Screen& (Screen::* const ConstAction)() const;

typedef Screen& (Screen::* const NonConstAction)();


void doActionConst(const Screen& s, ConstAction act, int n);

void doActionNonConst(Screen& s, NonConstAction act, int n);
