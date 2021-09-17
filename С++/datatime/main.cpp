#include <iostream>

using std::cout; using std::cin; using std::endl;

class sTime 
{ 
private:
	int s; int m; int ch;
public:
	void set( int ch, int m, int s);
	void read(); 
	void print();
};		   
sTime t;


struct sData 
{
private:
	int day; int mouse; int year; 
public:
	void set(int day, int mouse, int year);
	void read(); 
	void print();
}; 
sData d;


int main()
{
		setlocale(LC_ALL, "Rus");

	int ch = 15; int m = 26; int s = 59;
	t.set(ch, m, s); t.print();
	t.read (); t.print();
	
	int day = 5; int mouse = 6; int year = 2020;
	d.set(day, mouse, year); 	d.print();
	d.read(); d.print();
}

void sTime::set(int hor, int min, int sek)
{
	ch = hor; m = min; s = sek;
}
void sTime::read()
{
	cout << "¬ведите количество часов:"; cin >> ch;
	cout << "¬ведите количество минут:"; cin >> m;
	cout << "¬ведите количество секунд:"; cin >> s;
}
void sTime::print()
{
		cout << ch << ":" << m << ":" << s << endl;
}
void sData::set(int d, int m, int y)
{
	day = d; mouse = m; year = y;
}
void sData::read()
{
	cout << "¬ведите день:";  cin >> day;
	cout << "¬ведите мес€ц:"; cin >> mouse;
	cout << "¬ведите год:";   cin >> year;
}
void sData::print()
{
	cout << day << ":" << mouse << ":" << year << endl;
}
