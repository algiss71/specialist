//������ � ������������� ��������� �����
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 21

void PrintName(char* s[], int n);
void PutName(char** s, char buf);

int main()
{
	char* pName[N] = { NULL };
	int i = 0; 
	char buf[256];
	char yn;
	//1. ���� ������
A:
	printf("Input name: ");
	gets(buf);
	PutName(&pName[i], buf);//������ �����, ���� ��������
	//pName[i] - ��� �� ������, ��� ���������
	i++;//��������� ������� � ������� �� ���������
	printf("Enter :%s, \t dlina = %d",buf,strlen(buf));
	printf("\nAgain?(Y/N) :");
	scanf("%c", &yn);
	fflush(stdin);
	if (yn=='Y' || yn=='y')
	{
		goto A;
	}

	PrintName(pName, i);
	//SortName (pName, i);

	//4. ���������� ������

}

void PrintName(char* s[], int n)
{
	int i;
	printf("\n\n");
	for ( i = 0; i < n; i++)
	{
		puts(s[i]);
	}
}
void PutName(char** s, char buf)
{
	*s = (char*)malloc(strlen(buf) + 1);
	strcpy(*s, buf);
}
