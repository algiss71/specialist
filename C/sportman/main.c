/*
� ������ ���� ��������� �������� 10 ��.
� ������ ��������� ���� �� �������� �� 10% ��������� � ����������
������� �� �������� � 10 ����
� ����� ���� �� �������� ������ 20 ��
�� ������� ���� ��� ��������� ������ �������� 100 ��
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    float s = 10;
    float proc = 1.1;

    setlocale(LC_ALL, "Russian");

    for(int i = 1; i < 10;i++)
    {
        s *= proc;
        //printf("� %d ���� �� �������� %2f ��\n",i, s);
    }
    printf("\n� 10 ���� �� �������� %2f ��\n", s);

    //� ����� ���� �� �������� ������ 20 ��
    int i = 2;
    s = 10;
    do
    {
      s *= proc;
      //printf("\n� %d ���� �� �������� %2f ��\n",i, s);
      i++;
    }
    while(s < 20.0);

    printf("\n� %d ���� �� �������� ������ 20 ��\n", i-1);

    //�� ������� ���� ��� ��������� ������ �������� 100 ��
    i = 2;
    s = 10;
    int summ = s;
    do
    {

      s *= proc;
      //printf("\n� %d ���� �� �������� %2f ��\n",i, s);
      summ += s;
      i++;
    }
    while(summ < 100.0);
    printf("\n�� %d ���� ��� ��������� ������ �������� 100 ��\n", i-1);
    return 0;
}