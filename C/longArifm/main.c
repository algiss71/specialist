#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

void str_int_rev(int A[], const char* s, int N, int k);
void int_str_rev(int A[], char* s, int N);
void sum(int A[], int B[], int N);
void print_arr(int A[], int N);


int main()
{
    char str[100], str1[100];
    int l, la, lb, k;

    printf("Enter 1 value: "); scanf("%100s", str);
    printf("Enter 2 value: "); scanf("%100s", str1);

    la = strlen(str); lb = strlen(str1);

    if (la == lb)
    {
        l = la + 1;
        k = 0;
        int* a = (int*)calloc(l, sizeof(int));
        int* b = (int*)calloc(l, sizeof(int));
        char* s = (char*)calloc(l, sizeof(char));
        str_int_rev(a, str, l, k); str_int_rev(b, str1, l, k);
        sum(a, b, l);
        int_str_rev(b, s, l); printf("%s\n", s);
    }
    if (la > lb)
    {
        l = la + 1;
        k = la - lb;

        int* a = (int*)calloc(l, sizeof(int));
        int* b = (int*)calloc(l, sizeof(int));
        char* s = (char*)calloc(l, sizeof(char));

        str_int_rev(a, str, l, 0); str_int_rev(b, str1, l, k);

        for (int ix = 0; ix < l; ix++)
        {
            b[ix] += a[ix]; b[ix + 1] += (b[ix] / 10); b[ix] %= 10;
        }
        int_str_rev(b, s, l); printf("%s\n", s);
    }
    if (lb > la)
    {
        l = lb + 1; k = lb - la;

        int* a = (int*)calloc(l, sizeof(int));
        int* b = (int*)calloc(l, sizeof(int));
        char* s = (char*)calloc(l, sizeof(char));

        str_int_rev(a, str, l, k); str_int_rev(b, str1, l, 0);

        for (int ix = 0; ix < l; ix++)
        {
            b[ix] += a[ix]; b[ix + 1] += (b[ix] / 10); b[ix] %= 10;
        }
        int_str_rev(b, s, l); printf("%s\n", s);

    }
}


void str_int_rev(int A[], const char* s, int N, int k)
{
    for (int i = 1; i < N; i++)
    {
        if (s[i - 1] != 48)
        {
            A[N - i - 1 - k] = s[i - 1] - 48;
        }

    }
    print_arr(A, N);
}

    void sum(int A[], int B[], int N)
    {
        for (int ix = 0; ix < N; ix++)
        {
            B[ix] += A[ix]; B[ix + 1] += (B[ix] / 10); B[ix] %= 10;
        }
        if (B[N - 1] == 0) N--;
    }
    void int_str_rev(int A[], char* s, int N)
    {
        int i = 0;
        for (i = 0; i < N; i++)
        {
            s[i] = A[N - i - 1] + 48;
        }
        s[i] = '\0';
    }

    void print_arr(int A[], int N)
    {
        for (int i = 0; i < N; i++)
            printf("%d", A[i]);
        printf("\n");
    }

    
    
