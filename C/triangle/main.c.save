//Найти площадь треугольника
#include <wchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>

int main()
{
    double x1,y1,x2,y2,x3,y3,//координаты вершин
           a, b, c,          //стороны треугольника
           p,                //полупериметр
           S;                //площадь

    setlocale(LC_CTYPE, ".866");//для кириллицы

    //ввод исходных данных
    wprintf(L"Введите координаты 3-х вершин -> ");
    scanf("%lf %lf %lf %lf %lf %lf",
          &x1, &y1, &x2, &y2, &x3, &y3);
    //вычисления
    a = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
    b = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    c = sqrt(pow(x2-x3,2)+pow(y2-y3,2));

    p = (a + b + c) / 2;

    S = sqrt(p*(p-a)*(p-b)*(p-c));

    //Вывод результатов в общем формате
    wprintf(L"\nПлощадь = %.3g\n\n", S);




    printf("Hello world!\n");
    return 0;
}
