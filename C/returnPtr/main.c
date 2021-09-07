#include <stdio.h>

int extern_var;

int* return_ptr(int* p, int choice)
{
    static int static_var = 100;
    int local_var = 100;
    switch (choice)
    {
    case 1:
        return &local_var;//ÃĞÓÁÅÉØÀß ÎØÈÁÊÀ - ÍÅËÜÇß ÂÎÇÂĞÀÙÀÒÜ ÀÄĞÅÑ ËÎÊÀËÜÍÎÉ ÏÅĞÅÌÅÍÍÎÉ
    case 2:
        return &static_var;
    case 3:
        return &extern_var;
    case 4:
        return p;
    case 5:
        return malloc(sizeof(int));

    }
    return NULL;
}

int main()
{
    int n = 0;
    int* p;

    p = return_ptr(&n, 4);
    printf("%p\n", p);
        //......
        return 0;
}