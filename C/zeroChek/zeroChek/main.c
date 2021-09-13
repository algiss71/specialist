#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void zero_check(char s[], size_t l);
void str_int_rev(int a[], const char* s, size_t l, int k);
void print_arr(int a[], size_t l);
int main()
{
	char sa[1024]; //= { 0 };
	char sb[1024]; //= { 0 };
	printf("Enter 1 string: "); 
	scanf( "%s", sa);
	printf("Enter 2 string: "); 
	scanf("%s", sb);
	size_t la = strlen(sa);
	size_t lb = strlen(sb);
	
	printf("%s\n",sa);printf("%s\n", sb);
		
	zero_check(sa,la);zero_check(sb, lb);
	printf("%s\n", sa);printf("%s\n", sb);
	
	la = strlen(sa); lb = strlen(sb);
	int l, k = la - lb ;
	if (k >= 0)
	{
		l = la;
	}
	if (k < 0)
	{
		l = lb;
		k = lb - la;
	}
	
	printf("la = %d, lb = %d, l = %d, k = %d\n", la, lb, l, k);
	int* a = (int*)calloc(l, sizeof(int));
	int* b = (int*)calloc(l, sizeof(int));
	char* s = (char*)calloc(l, sizeof(char));
	str_int_rev(a, sa, l, k);str_int_rev(b, sb, l, k);
	print_arr(a, l);print_arr(b, l);

}
void zero_check(char s[], size_t l)
{
	for (size_t i = 0; i < l; i++)
	{
		if (s[0] == 48)
		{
			for (size_t j = 0; j < l; j++)
			{
				s[j] = s[j + 1];
			}
			i--;
		}
	}

}

void str_int_rev(int a[], const char* s, size_t l, int k)
{
	for (int i = 1; i < l; i++)
	{
		printf("s[%d] = %d\n, ",i,s[i]);
		if (s[i - 1] != 48)
		{
			a[l - i - 1 - k] = s[i - 1] - 48;
		}
	}
}

void print_arr(int a[], size_t l)
{
	for (int i = 0; i < l; i++)
		printf("%d", a[i]);
	printf("\n");
}