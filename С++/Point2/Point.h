#ifndef POINT_H
#define POINT_H

class Point
{
public:
	Point(const Point&);//����������� �����������
	
	Point();//����������� �� ���������
	Point(int, int);//��������������� �����������
	explicit Point(int);//����������� ������ (explicit) ��������������
	
	//Point(int = 0, int = 0);//3 ������������ � �����
	~Point();//����������
	void Print()const;
private:
	int x;
	int y;
};

#endif // !POINT_H

