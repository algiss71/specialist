//Указатели - аргументы функций

#include <stdio.h>

void swap(int* a, int* b)
{
    int t = *a; *a = *b; *b = t;
}

void strcopy(char* t, const char* s)
{
    while (*t++ = *s++);
}

int sum(int* p, int n)
{
    int s = 0;
    while (n-- > 0)
        s += *p++;
    return s;
}

int main()
{
    int x = 5, y = 2;
    int a[] = { 1,2,3,4,5 };
    char s1[16], s0[] = "Hello!";

    swap(&x, &y);
    printf("x = %d, y = %d\n", x, y);

    strcopy(s1, s0);
    puts(s1);

    printf("sum = %d\n", sum(a, sizeof a / sizeof * a));
    return 0;
}