#include <iostream>
#include "Point.h"
using std::cout; using std::cin; using std::endl;

Point::Point(const Point& other)
	:x(other.x), y(other.y)//������ �������������
{
	//x = other.x;
	//y = other.y;
	cout << "Point(const Point& other): "; Print(); cout << endl;//��� �������
}
Point::Point(int _x, int _y)
{
	x = _x;//����� ��������� �� ������������
	y = _y;//Set ������(��������)

	cout << "Point(int,int): "; Print(); cout << endl;//��� �������
}


Point::Point()
{
	x = y = 0;
	
	cout << "Point(): "; Print(); cout<< endl;//��� �������
}
Point::Point(int _x)
{
	x = _x;//����� ��������� �� ������������
	y = 0;//Set ������(��������)
	cout << "Point(int): "; Print(); cout << endl;//��� �������
}



Point::~Point()
{
	cout << "~Point(): "; Print(); cout << endl;//��� �������
}
void Point::Print()const
{
	cout << '(' << x << " ," << y << ')';
}