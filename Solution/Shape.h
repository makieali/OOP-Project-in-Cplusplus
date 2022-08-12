#pragma once

class Shape {

private:
	int length;
	char ch;

public:
	//constructors
	Shape();
	Shape(int len, char c);

	int getlen();

	void setlen(int l);

	char getch();

	void setch(char c);

	virtual void Read()=0;
	virtual void display() = 0;
	virtual void render() = 0;



};
