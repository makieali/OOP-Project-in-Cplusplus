#include<iostream>
#include"Rectangle.h"

using namespace std;

Rectangle::Rectangle()
{

}
Rectangle::Rectangle(int len, char ch, int w, bool flg) :Shape(len, ch)
{
	width = w;
	flag = flg;
}


Rectangle Rectangle::operator + (Rectangle& t)
{
	Rectangle np = t;

	np.setflag(false);
	np.setlen(this->getlen() + t.getlen());
	np.setch('*');
	np.setWidth(this->getWidth() + t.getWidth());
	return np;
}

Rectangle Rectangle::operator ++(int)
{
	Rectangle l = *this;
	int temp = l.getlen();
	l.setlen(temp++);
	l.setch('*');
	return l;
}

Rectangle Rectangle::operator --()
{
	Rectangle l = *this;
	int temp = l.getlen();
	l.setlen(temp--);
	l.setch('*');
	return l;
}

bool Rectangle::operator==(Rectangle& r)
{
	bool flag = false;
	int l1 = r.getlen();
	int l2 = this->getlen();
	char c1 = r.getch();
	char c2 = this->getch();
	if (this->flag == r.flag && l1 == l2 && c1 == c2)
	{
		flag = true;
	}
	return flag;
}

bool Rectangle::operator!=(Rectangle& r)
{
	bool flag = false;
	int l1 = r.getlen();
	int l2 = this->getlen();
	char c1 = r.getch();
	char c2 = this->getch();
	if (this->flag != r.flag || l1 != l2 || c1 != c2)
	{
		flag = true;
	}
	return flag;
}

int Rectangle::getlen()
{
	int length = Shape::getlen();

	return length;
}

void Rectangle::setlen(int l)
{
	Shape::setlen(l);
}

void Rectangle::setch(char c)
{
	Shape::setch(c);
}

char Rectangle::getch()
{
	char c = Shape::getch();
	return c;
}

void Rectangle::setflag(bool fl)
{
	flag = fl;
}

bool Rectangle::getflag()
{
	return flag;
}

void Rectangle::setWidth(int w)
{
	width = w;
}
int Rectangle::getWidth()
{
	return width;
}

void Rectangle::Read()
{
	int len;
	char c = '\0';
	bool flag;
	int Width = 0;
	cout << "Enter Rectangle Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	cin >> len >> c;
	cout << "Enter Width:";
	cin >> Width;
	cout << "Enter 1 for shadded and 0 for not shadded:";
	cin >> flag;

	setflag(flag);
	setWidth(Width);
	setlen(len);
	setch(c);
}

void Rectangle::display()
{
	cout << "<Shape:" << this->getlen() << " " << this->getch() << "/>" << endl;
	cout << "<Rectangle:" << this->getWidth() << " " << this->getflag() << "/>" << endl;
}

void Rectangle::render()
{
	if (flag == 0)
	{
		for (int i = 0; i < width; i++)
		{
			if (i == 0 || i + 1 == width)
			{
				for (int j = 0; j < getlen(); j++)
				{
					cout << getch();
				}
			}
			else
			{
				for (int i = 0; i < getlen(); i++)
				{
					if (i == 0 || i + 1 == getlen())
					{
						cout << getch();
					}
					else
					{
						cout << " ";
					}


				}
			}
			cout << endl;


		}
	}
	else
	{
		for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < getlen(); j++)
			{
				cout << getch();
			}
			cout << endl;
		}
	}
}