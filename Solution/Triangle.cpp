#include"Triangle.h"


Triangle::Triangle(int len, char ch, int h, bool fg) :Shape(len, ch)
{
	height = h;
	flag = fg;
}


Triangle Triangle::operator + (Triangle& t)
{
	Triangle np = t;

	np.setflag(false);
	np.setlen(this->getlen() + t.getlen());
	np.setch('*');
	np.setHeight(this->getHeight() + t.getHeight());
	return np;
}

Triangle Triangle::operator ++(int)
{
	Triangle l = *this;
	int temp = l.getlen();
	l.setlen(temp++);
	l.setch('*');
	return l;
}

Triangle Triangle::operator --()
{
	Triangle l = *this;
	int temp = l.getlen();
	l.setlen(temp--);
	l.setch('*');
	return l;
}

bool Triangle::operator==(Triangle& t)
{
	bool flag = false;
	int l1 = t.getlen();
	int l2 = this->getlen();
	char c1 = t.getch();
	char c2 = this->getch();
	if (this->flag == t.flag && l1 == l2 && c1 == c2)
	{
		flag = true;
	}
	return flag;
}

bool Triangle::operator!=(Triangle& l)
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

int Triangle::getlen()
{
	int length = Shape::getlen();

	return length;
}

void Triangle::setlen(int l)
{
	Shape::setlen(l);
}

void Triangle::setch(char c)
{
	Shape::setch(c);
}

char Triangle::getch()
{
	char c = Shape::getch();
	return c;
}

void Triangle::setflag(bool fl)
{
	flag = fl;
}

bool Triangle::getflag()
{
	return flag;
}

void Triangle::setHeight(int h)
{
	height = h;
}
int Triangle::getHeight()
{
	return height;
}

void Triangle::Read()
{
	int len;
	char c = '\0';
	bool flag;
	int height = 0;
	cout << "Enter Triangle Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	cin >> len >> c;
	cout << "Enter Height:";
	cin >> height;
	cout << "Enter 1 for upsided and 0 for downsided:";
	cin >> flag;

	setflag(flag);
	setHeight(height);
	setlen(len);
	setch(c);

}

void Triangle::display()
{
	cout << "<Shape:" << this->getlen() << " " << this->getch() << "/>" << endl;
	cout << "<Triangle:" << this->getHeight() << " " << this->getflag() << "/>" << endl;
}
void Triangle::render()
{
	int len = getlen();
	int len2 = height;

	if (flag == 0)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cout << " ";
			}
			for (int k = 0; k < len2; k++)
			{
				cout << getch();
			}
			for (int j = 0; j < i; j++)
			{
				cout << " ";
			}
			len2 = len2 - 1;
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < len2; j++)
			{
				cout << " ";
			}
			for (int k = 0; k <= i; k++)
			{
				cout << getch();
			}
			len2 = len2 - 1;
			cout << endl;
		}
	}
}