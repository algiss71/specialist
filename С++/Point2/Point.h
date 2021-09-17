#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(const Point&);//конструктор копирования
	
	Point();//конструктор по умолчанию
	Point(int, int);//параметрический конструктор
	explicit Point(int);//конструктор явного (explicit) преобразования
	
	//Point(int = 0, int = 0);//3 конструктора в одном
	~Point();//деструктор
	void Print()const;
private:
	int x;
	int y;
};

#endif // !POINT_H

