#include<iostream>
#include"Line.h"

using namespace std;

Line::Line()
{
	flag = 0;
}
Line::Line(int len, char ch, bool fl) :Shape(len, ch)
{
	flag = fl;
}


Line Line::operator + (Line& l)
{
	Line np = l;

	np.setflag(this->getflag() + l.getflag());
	np.setlen(this->getlen() + l.getlen());
	np.setch('*');
	return np;
}

Line Line::operator ++(int)
{
	Line l = *this;
	int temp = l.getlen();
	l.setlen(temp++);
	return l;
}

Line Line::operator --()
{
	Line l = *this;
	int temp = l.getlen();
	l.setlen(temp--);
	return l;
}

bool Line:: operator==(Line& l)
{
	bool flag = false;
	int l1 = l.getlen();
	int l2 = this->getlen();
	char c1 = l.getch();
	char c2 = this->getch();
	if (this->flag == l.flag && l1 == l2 && c1 == c2)
	{
		flag = true;
	}
	return flag;
}

bool Line::operator!=(Line& l)
{
	bool flag = false;
	int l1 = l.getlen();
	int l2 = this->getlen();
	char c1 = l.getch();
	char c2 = this->getch();
	if (this->flag != l.flag || l1 != l2 || c1 != c2)
	{
		flag = true;
	}
	return flag;
}

int Line::getlen()
{
	int length = Shape::getlen();

	return length;
}

void Line::setlen(int l)
{
	Shape::setlen(l);
}

void Line::setch(char c)
{
	Shape::setch(c);
}

char Line::getch()
{
	char c = Shape::getch();
	return c;
}


void Line::setflag(bool fl)
{
	flag = fl;
}

bool Line::getflag()
{
	return flag;
}

void Line::Read()
{
	int len;
	char c = '\0';
	bool flag;
	cout << "Enter Line Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	cin >> len >> c;
	cout << "Enter 0 if Line is Horizontal or 1:";
	cin >> flag;
	setflag(flag);
	setlen(len);
	setch(c);
}

void Line::display()
{
	cout << "<Shape:" << this->getlen() << " " << this->getch() << "/>" << endl;
	cout << "<Line:" << this->getflag() << "/>" << endl;
}

void Line::render()
{
	if (flag == 1)
	{
		for (int i = 0; i < getlen(); i++)
		{
			cout << getch();
		}
		cout << endl;
	}
	else
	{
		for (int i = 0; i < getlen(); i++)
		{
			cout << getch() << endl;
		}
	}
}