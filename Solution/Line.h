#pragma once

#include"Shape.h"
#include<iostream>

using namespace std;

class Line :public Shape {

private:
	bool flag;

public:
	Line();
	Line(int len, char ch, bool fl);

	friend ostream& operator << (ostream& out, Line& l);
	friend istream& operator >> (istream& in, Line& l);

	Line operator + (Line& l);

	Line operator ++(int);

	Line operator --();

	bool operator==(Line& l);

	bool operator!=(Line& l);

	int getlen();

	void setlen(int l);

	void setch(char c);

	char getch();


	void setflag(bool fl);

	bool getflag();

	void Read();

	void display();

	void render();
};
