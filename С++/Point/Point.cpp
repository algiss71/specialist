//Реализация класса Point
#include <iostream>
#include <math.h>
#include "Point.h"

using namespace std;
Point::Point(const Point& other)
{
	x = other.x;
	y = other.y;
	cout << "Point(const Point& other): "; Print(); cout << endl;//для отладки
}

Point::Point()
{
	x = y = 0;

	cout << "Point(): "; Print(); cout << endl;//для отладки
}
Point::~Point()
{
	cout << "~Point(): "; Print(); cout << endl;//для отладки
}
void Point::SetX(int _x)
{
	x = _x >= 0 ? _x : 0;//координаты не могут быть отрицательными
}
void Point::SetY(int _y)
{
	y = _y >= 0 ? _y : 0;
}

void Point::Print()const
{
	cout << '(' << x << " ," << y << ')' ;
}
void Point::Move(int dx, int dy)
{
	SetX(x += dx);
	SetY(y += dy);
}
void Point:: Read()
{
	cout << "Введите координату x:"; cin >> x; SetX(x);
	cout << "Введите координату y:"; cin >> y; SetY(y);
	
}
double Point::Dist(  const Point &b) const//ссылка для эффективности
{
	return sqrt( pow (static_cast <double> (x - b.GetX()),2) + pow (static_cast<double> (y - b.GetY()),2) );

}

void Line::SetA(int _x, int _y)
{
	a.SetX(_x);
	a.SetY(_y);

}
void Line::SetB(int _x, int _y)
{
	b.SetX(_x);
	b.SetY(_y);
}

void Line::Print()
{
	cout << '(' << a.GetX() << " ," << a.GetY() << ')' << '(' << b.GetX() << " ," << b.GetY() << ')';
}
void Line::Read()
{
	int x1, y1, x2, y2;
	cout << "Введите координату x 1 точки:"; cin >> x1; 
	cout << "Введите координату y 1 точки:"; cin >> y1; 
	SetA(x1,y1);
	cout << "Введите координату x 2 точки:"; cin >> x2;
	cout << "Введите координату y 2 точки:"; cin >> y2;
	SetB(x2, y2);
}
double Line::Length()
{
	return sqrt(
		(a.GetX() - b.GetX()) *
		(a.GetX() - b.GetX()) +
		(b.GetY() - b.GetY()) *
		(b.GetY() - b.GetY())
	);
}

double fDist(const Point& a, const Point& b)
{
	return sqrt(pow(static_cast <double> (a.x - b.x), 2) + pow(static_cast<double> (a.y - b.y), 2));
}
