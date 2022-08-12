#include<iostream>
#include"Shape.h"
#include"Line.h"
#include"Rectangle.h"
#include"Triangle.h"


using namespace std;

istream& operator >> (istream& in, Rectangle& r)
{
	int len;
	char c = '\0';
	bool flag;
	int Width = 0;
	cout << "Enter Rectangle Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	in >> len >> c;
	cout << "Enter Width:";
	in >> Width;
	cout << "Enter 1 for shadded and 0 for not shadded:";
	in >> flag;

	r.setflag(flag);
	r.setWidth(Width);
	r.setlen(len);
	r.setch(c);
	return in;

}
istream& operator >> (istream& in, Line& l)
{
	int len;
	char c='\0';
	bool flag;
	cout << "Enter Line Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	in >> len >> c;
	cout << "Enter 0 if Line is Horizontal or 1:";
	in >> flag;
	l.setflag(flag);
	l.setlen(len);
	l.setch(c);
	return in;
}
istream& operator >> (istream& in, Triangle& t)
{
	int len;
	char c = '\0';
	bool flag;
	int height = 0;
	cout << "Enter Triangle Data :" << endl;
	cout << "Enter Shape Data :" << endl;
	cout << "Enter length and character :";
	in >> len >> c;
	cout << "Enter Height:";
	in >> height;
	cout << "Enter 1 for upsided and 0 for downsided:";
	in >> flag;

	t.setflag(flag);
	t.setHeight(height);
	t.setlen(len);
	t.setch(c);
	
	return in;
}

ostream& operator << (ostream& out, Rectangle& r)
{
	int len = r.getlen();
	char c = r.getch();
	out << "<Shape:" << len << " " << c << "/>" << endl;
	out << "<Rectangle:" << r.getWidth() << " " << r.getflag() << "/>" << endl;

	return out;

}

ostream& operator << (ostream& out, Triangle& t)
{
	int len = t.getlen();
	char c = t.getch();
	out << "<Shape:" << len <<" " << c << "/>" << endl;
	out << "<Triangle:"<<t.getHeight()<<" " << t.getflag() << "/>" << endl;

	return out;

}

ostream& operator << (ostream& out, Line& l)
{
	int len = l.getlen();
	char c = l.getch();
	out << "<Shape:" << len <<" " << c << "/>" << endl;
	out << "<Line:" << l.getflag() << "/>" << endl;

	return out;

}

int main()
{
	const int NUMBER = 6;

	Shape* shapes[NUMBER];
	shapes[0] = new Line(10, '*', true);
	shapes[1] = new Line(10, '+', false);
	shapes[2] = new Rectangle(10, '&', 5, false);
	shapes[3] = new Triangle(9, '%', 6, false);
	shapes[4] = new Rectangle(10, '@', 5, true);
	shapes[5] = new Triangle(9, '$', 6, true);

	cout << "** Line **\n";
	Line* pl = (Line*)shapes[0];
	Line l1 = *pl;

	cout << "Line one:" << l1;
	pl = (Line*)shapes[1];
	Line l2 = *pl;
	cout << "Line two:" << l2;

	Line L = l1 + l2;
	cout << " Line one + Line two = : " << L;

	L = l1++;

	cout << " L = l1++ = : " << L;
	L = --l1;
	cout << " L = --l1 = : " << L;
	cout << "l1 == l2: " << (l1 == l2)<< endl;
	cout << "l1 != l2: " << (l1 != l2)<< endl;
	cout << "** Triangle **\n";
	Triangle* pt =(Triangle*)shapes[3];
	Triangle t1 = *pt;
	cout << "Triangle one:" << t1;
	pt = (Triangle*)shapes[5];
	Triangle t2 = *pt;
	cout << "Triangle two:" << t1;
	Triangle T = t1 + t2;

	cout << "Triangle one + two:" << T;
	T = t1++;
	cout << "t1++ = " << T;
	T = --t1;
	cout << "--t1 = " << T;
	cout << "t1 == t2: " << (t1 == t2)<< endl;
	cout << "t1 != t2: " << (t1 != t2)<< endl;
	cout << "** Triangle **\n";
	Rectangle* pr =(Rectangle*)shapes[2];
	Rectangle r1 = *pr;
	cout << "Rectangle one:" << r1;
	pr = (Rectangle*)shapes[4];
	Rectangle r2 = *pr;
	cout << "Rectangle two:" << r2;
	Rectangle R = r1 + r2;
	cout << " Rectangle one + two = "
		<< R;
	R = r1++;
	cout << "R = r1++: " << R;
	R = --r1;
	cout << "R = --r1: " << R;
	cout << "r1 == r2: " << (r1 == r2)<< endl;
	cout << "r1 != r2: " << (r1 != r2)<< endl;

	

	// cin on Line, Rectangle andTriangle

		cin >> L >> R >> T;
		// cout on Line, Rectangle

		cout << L << R << T;
	// polymorphism
	cout << "Invoking through polymorphism: \n";
	for (int i = 0; i < NUMBER; i++)
	{
		shapes[i]->display();
		shapes[i]->render();
	}



	return 0;
}