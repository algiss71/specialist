//����������� � ��������� ������� main()
#include <stdio.h>

const char* rus(const char* s)
{
    static char b[2048]; //����������� ������ �� ��
    int i;
    for (i = 0; b[i] = s[i]; ++i)
        if (b[i] >= '�' && b[i] <= '�') b[i] -= 0x40;
        else if (b[i] >= '�' && b[i] <= '�') b[i] -= 0x10;

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
    
    printf(rus("������ ������������� ������������� %d ���!\n\n"));

}