#include <iostream>
#include "Point.h"
using std::cout; using std::cin; using std::endl;

Point::Point(const Point& other)
	:x(other.x), y(other.y)//список инициализации
{
	//x = other.x;
	//y = other.y;
	cout << "Point(const Point& other): "; Print(); cout << endl;//для отладки
}
Point::Point(int _x, int _y)
{
	x = _x;//здесь следовало бы использовать
	y = _y;//Set методы(проверка)

	cout << "Point(int,int): "; Print(); cout << endl;//для отладки
}


Point::Point()
{
	x = y = 0;
	
	cout << "Point(): "; Print(); cout<< endl;//для отладки
}
Point::Point(int _x)
{
	x = _x;//здесь следовало бы использовать
	y = 0;//Set методы(проверка)
	cout << "Point(int): "; Print(); cout << endl;//для отладки
}



Point::~Point()
{
	cout << "~Point(): "; Print(); cout << endl;//для отладки
}
void Point::Print()const
{
	cout << '(' << x << " ," << y << ')';
}