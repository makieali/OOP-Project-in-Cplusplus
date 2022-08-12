#pragma once

#include<iostream>
#include"Shape.h"

using namespace std;

class Rectangle :public Shape {
private:
	int width;
	bool flag;
public:
	Rectangle();
	Rectangle(int len, char ch, int w, bool flg);

	friend ostream& operator << (ostream& out, Rectangle& l);
	friend istream& operator >> (istream& in, Rectangle& r);

	Rectangle operator + (Rectangle& t);

	Rectangle operator ++(int);

	Rectangle operator --();

	bool operator==(Rectangle& r);
	bool operator!=(Rectangle& r);

	int getlen();

	void setlen(int l);

	void setch(char c);

	char getch();

	void setflag(bool fl);

	bool getflag();

	void setWidth(int w);
	int getWidth();

	void Read();
	void display();

	void render();

};
