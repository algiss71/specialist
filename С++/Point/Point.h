//����������� ������ Point
/*
GetX , GetY , SetX, SetY - ����������� ��������� ������
 Move - ������������� ����������� 
 Print, Read
 Dist - ���������
*/
#ifndef POINT_H
#define POINT_H

class Point
{

public:
	Point(const Point&);//����������� �����������
	Point();//����������� �� ���������
	~Point();//����������
	int GetX()const{ return x; }//�������� � inline �� ���������
	int GetY()const;//�������� �� ������� ������
	void SetX(int);//���������� � 
	void SetY(int);//�������� �� ������� ����� (Point.cpp)
	void Print()const;
	void Move(int delta_x, int delta_y);
	void Read();
	double Dist(const Point&) const;
	friend double fDist(const Point&, const Point&);//������������� �������
	//Point();
	//~Point();
private:
	int x;//����������
	int y;// �����

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
	Point a;//����������
	Point b;// �����

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
