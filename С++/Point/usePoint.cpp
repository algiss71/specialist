//Использование класса Point
#include <iostream>
#include "Point.h"

using namespace std;
Point g;// создание объекта extern
static Point sg;// создание объекта static
double gDist(const Point& a, const Point& b)
{
	return sqrt(pow(static_cast <double> (a.GetX() - b.GetX()), 2) + pow(static_cast<double> (a.GetY() - b.GetY()), 2));
}

int main()
{
	setlocale(LC_ALL, "Rus");
	/*static Point sl;// создание объекта static	
	Point a;// , b;// создание объекта в стеке
	a.SetX(10); a.SetY(20);
	cout << a.GetX() << ',' << a.GetY() << endl;
	a.Print(); cout << endl;
	a.Move(5, 10);
	a.Print(); cout << endl;
	a.Read();
	a.Print(); cout << endl;
	a.Read(); b.Read();
	cout<<"dist = "<<a.Dist(b)<<endl;
	*/
	
	Line c;
	c.SetA(2, 3); c.SetB(5, 6);
	c.Print(); cout << endl;
	c.Read();
	c.Print(); cout << endl;
	cout << "Length = " << c.Length() << endl;
	
	/*Point* p = new Point; // создание объекта в куче(динамической памяти)
	//здесь должна быть обработка ошибок при выделении памяти
	a.SetX(10); a.SetY(20);  a.Print(); cout << endl;
	p->SetX(20);p->SetY(30); p->Print(); cout << endl;
	cout << "dist = " << gDist(a, *p) << endl;
	cout << "dist = " << fDist(a, *p) << endl;
	cout << "dist = " << a.Dist(*p) << endl;
	delete p;//нельзя забывать!!!!
	*/
	system("pause");
}