#include <iostream>
#include "Point.h"
using std::cout; using std::cin; using std::endl;
const Point &test(const Point &q)
{
	return q;
}

int main()
{

	Point a;
	Point c(100, 200);//или
	Point c1 = Point(101, 201);
	Point d(999);//или
	Point d1 = Point(111);//или
	//Point d2 = 12;
	Point b = a;
	
	Point* p  = new Point;
	Point* p1 = new Point(55);
	Point* p2 = new Point(44,444);
	delete p;
	delete p1;
	delete p2;
	
	test(c);
	test(static_cast<Point>(777));
	//test(77.7);
	//test('7');
	//test("7");
	Point arr[4] = {Point(1,2),Point(4),};

	//cout << sizeof a << endl;
}