#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
#include<string.h>


void strcopy(char* t, const char* s);
void zero_chek(char A[], int N);
void str_int_rev(int A[], const char* s, int N, int k);
void int_str_rev(int A[], char* s, int N);
//void sum(int A[], int B[], int *N);
void print_arr(int A[], int N);

char* strsum(const char* aS, const char* bS)
{
    const int aN = strlen(aS); const int bN = strlen(bS);
    char* str = (char*)malloc((aN) * sizeof(char));
    char* str1 = (char*)malloc((bN) * sizeof(char));
    strcopy(str, aS); strcopy(str1, bS);
    int l, la, lb, k;
    char* zero = "0";
    la = strlen(str); lb = strlen(str1);
    zero_chek(str, la);  zero_chek(str1, lb);
    la = strlen(str); lb = strlen(str1);
    
    printf("str = %s\n", str); printf("str1 = %s\n", str1);
    printf("la = %d\n", la); printf("lb = %d\n", lb);
    
    if (la ==0 && lb == 0)  return zero;
    
    l = la + 1;
    
    if (la >= lb)
    {
        k = la - lb;
        int* a = (int*)calloc(l, sizeof(int));
        int* b = (int*)calloc(l, sizeof(int));
        char* s = (char*)calloc(l, sizeof(char));
        print_arr(a, l); print_arr(b, l);
                
        str_int_rev(a, str, l, 0); str_int_rev(b, str1, l, k);
        print_arr(a, l); print_arr(b, l);
        for (int ix = 0; ix < l; ix++)
        {
            b[ix] += a[ix]; b[ix + 1] += (b[ix] / 10); b[ix] %= 10;
        }
        if (b[l - 1] == 0) l--;
        print_arr(b, l);
        //printf("k = % d\n", k);
        int_str_rev(b, s, l);
        printf("sF = %s\n", s);
        return s;

    }

    if (lb > la)
    {
        k = lb - la;
        l = lb + 1;
        int* a = (int*)calloc(l, sizeof(int));
        int* b = (int*)calloc(l, sizeof(int));
        char* s = (char*)calloc(l, sizeof(char));
        
        str_int_rev(a, str, l, k); str_int_rev(b, str1, l, 0);
        
        for (int ix = 0; ix < l; ix++)
        {
            b[ix] += a[ix]; b[ix + 1] += (b[ix] / 10); b[ix] %= 10;
        }
        if (b[l - 1] == 0) l--;
        printf("k = % d\n", k);
        int_str_rev(b, s, l);
        printf("sF = %s\n", s);
        return s;

    }
        
}

int main()
{
    char str[1024], str1[1024];
    printf("Enter 1 value: "); scanf("%100s", str);
    printf("Enter 2 value: "); scanf("%100s", str1);
    printf("s = %s",strsum(str, str1));
    system("pause");
}

void strcopy(char* t, const char* s)
{
    while (*t++ = *s++);
}

void zero_chek(char A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        if (A[0] == 48)
        {
            for (int j = 0; j < N; j++)
            {
                A[j] = A[j + 1];
            }
            i--;
        }
    }
}
void str_int_rev(int A[], const char* s, int N, int k)
{
    for (int i = 1; i < N; i++)
    {
        if (s[i - 1] != 48)
        {
            A[N - i - 1 - k] = s[i - 1] - 48;
            //printf("a[%d] = %d\n", i, A[i]);
        }
        
    }
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

    
    
