#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void zero_check(char s[], size_t l);
void print_arr(int a[], size_t l);
void StringToInt(char c[],int a[],int l, int k);
void IntToString(char c[], int a[], int l);

int main()
{
	char sa[1024];char sb[1024]; char* zero = "0"; int l, k;
	printf("Enter 1 string: "); scanf( "%s", sa);
	printf("Enter 2 string: "); scanf("%s", sb);
	size_t la = strlen(sa); 	size_t lb = strlen(sb);
	zero_check(sa, la); zero_check(sb, lb);
	la = strlen(sa); lb = strlen(sb);
	
	if (la == 0 && lb == 0)  return zero;

	l = la + 1;

	if (la >= lb)
	{
		k = la - lb;
		int* a = (int*)calloc(l, sizeof(int));
		int* b = (int*)calloc(l, sizeof(int));
		char* s = (char*)calloc(l, sizeof(char));
		StringToInt(sa, a, l, 0); StringToInt(sb, b, l, k);
		//print_arr(a, l); print_arr(b, l);
		for (int ix = la; ix > 0; ix--)
		{
			b[ix] += a[ix]; b[ix - 1] += (b[ix] / 10); b[ix] %= 10;
		}
		//printf("b[0] = %d, l = %d\n",b[0],l);
		if (b[0] == 0)
		{
			for (int i = 0; i < l; i++)
				b[i] = b[i+1];
			l--;
		}
			
		//printf("b[0] = %d, l = %d\n", b[0], l);
		//print_arr(b, l);
		
		IntToString( s,b, l);
		//free(a);	free(b);
		printf("sF = %s\n", s);
		return s;

	}

	system("pause");
}
void zero_check(char s[], size_t l)
{
	for (size_t i = 0; i < l; i++)
	{
		if (s[0] == 48)
		{
			for (size_t j = 0; j < l; j++)
				s[j] = s[j + 1];
			i--;
		}
	}
}


void print_arr(int a[], size_t l)
{
	for (size_t i = 0; i < l; i++)
		printf("%d", a[i]);
	printf("\n");
}
void StringToInt(char c[],int a[],int l, int k)
{
	int i;
	for ( i = 0; i < l; i++) 
		a[i + 1 + k] = c[i] - 48;
}
void IntToString(char c[], int a[], int l)
{
	int i;
	for (i = 0; i < l; i++)
		c[i] = a[i] + 48;
	c[i] = '\0';
}