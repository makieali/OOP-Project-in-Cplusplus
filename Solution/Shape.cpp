#include<iostream>
#include"Shape.h"

using namespace std;

Shape::Shape()
{
	length = 0;
	ch = 0;
}
Shape::Shape(int len, char c)
{
	length = len;
	this->ch = c;
}

int Shape::getlen()
{

	return length;
}

void Shape::setlen(int l)
{
	length = l;
}

char Shape::getch()
{
	return ch;
}

void Shape::setch(char c)
{
	ch = c;
}