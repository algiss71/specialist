//Определение класса Point
/*
GetX , GetY , SetX, SetY - минимальный интерфейс класса
 Move - относительное перемещение 
 Print, Read
 Dist - растояние
*/
#ifndef POINT_H
#define POINT_H

class Point
{

public:
	Point(const Point&);//конструктор копирования
	Point();//конструктор по умолчанию
	~Point();//деструктор
	int GetX()const{ return x; }//получить х inline по умолчанию
	int GetY()const;//вынесена за пределы класса
	void SetX(int);//установить х 
	void SetY(int);//вынесена за пределы файла (Point.cpp)
	void Print()const;
	void Move(int delta_x, int delta_y);
	void Read();
	double Dist(const Point&) const;
	friend double fDist(const Point&, const Point&);//жружественная функция
	//Point();
	//~Point();
private:
	int x;//координаты
	int y;// точки

};
class Line
{

public:
	
	void SetA(int, int);
	void SetB(int,int);
	void Print();
	
	void Read();
	double Length();
	
	//Point();
	//~Point();
private:
	Point a;//координаты
	Point b;// точки

};


inline int Point::GetY() const
{
	 return y; 
}
/*Point::Point()
{
}

Point::~Point()
{
}*/
#endif // !POINT_H
