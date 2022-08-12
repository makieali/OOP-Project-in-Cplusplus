#pragma once
#include<iostream>
#include"Shape.h"

using namespace std;

class Triangle :public Shape {

	int height;
	bool flag;

public:

	Triangle(int len, char ch, int h, bool fg);

	friend ostream& operator << (ostream& out, Triangle& l);
	friend istream& operator >> (istream& in, Triangle& t);

	Triangle operator + (Triangle& t);

	Triangle operator ++(int);

	Triangle operator --();

	bool operator==(Triangle& t);

	bool operator!=(Triangle& l);

	int getlen();

	void setlen(int l);

	void setch(char c);

	char getch();

	void setflag(bool fl);

	bool getflag();

	void setHeight(int h);
	int getHeight();
	void Read();
	void display();
	void render();
};
