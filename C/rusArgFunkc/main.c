//русификация и аргументы функции main()
#include <stdio.h>

const char* rus(const char* s)
{
    static char b[2048]; //статический массив не ун
    int i;
    for (i = 0; b[i] = s[i]; ++i)
        if (b[i] >= 'А' && b[i] <= 'п') b[i] -= 0x40;
        else if (b[i] >= 'р' && b[i] <= 'я') b[i] -= 0x10;

    return b;
}

int main(int argc, const char** argv, const char** env)
{
    int i;
    if (argc == 1)
    {
        puts("Use: prog.exe param1 param2");
        return 0;
    }

    while (*argv) puts(rus(*argv++));

    puts("\nEnviroment variables:\n");
    while(*env) puts(*env++);
    
    printf(rus("Привет русскоязычным программистам %d раз!\n\n"));

}