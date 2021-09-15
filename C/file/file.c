//������ ������ � �������
#define _CRT_SECURE_NO_WARNINGS
#define MAXLEN 32
#define MAXGRADES 3
	//��������� ������� (���) ������� 3 ��������
typedef struct
{
	char last_name[MAXLEN];//���
	int grade[MAXGRADES];//������

} student;
#include <stdio.h>
#include <stdlib.h>
#define VAR 9

int main()
{
#if VAR == 1
//�������� ���������� �����(����������������� �������)
	FILE* file = fopen("test1.txt","wt");
	if (!file)
	{
		perror("test1.txt");
		exit(1);
	}
	fputc('*', file);//������ ������ �������
	fputs("Hello, world!\n", file);//������ ������
	fprintf(file, "%d\n", 2011);//��������������� ������ � ����� �� ������������ %
	

	fclose(file);
#endif
#if VAR == 2
	//������ ���������� �����(����������������� �������)
	int x; char buf[256];
	FILE* file = fopen("test1.txt", "rt");
	if (!file)
	{
		perror("test.txt");
		exit(1);
	}
	x = fgetc(file);/*������ ������ ������� �� �����*/							putchar(x);//����������� ������
	fgets(buf, sizeof buf, file);/*������ ������ �� ����� */					fputs(buf, stdout);//����������� ������
	fscanf(file, "%d", &x);/*��������������� ������ �� ����� �� ������������%*/	printf(" % d\n", x);//����������� ������
	
	fclose(file);
#endif
#if VAR == 3
	//������ ���������� �����(����������� ���������)
	int x; 
	FILE* file = fopen("file.c", "rt");
	if (!file)
	{
		perror("file.c");
		exit(1);
	}
	system("chcp 1251 > nul");
	while ((x = fgetc(file)) != EOF)//(!feof(file))- ������� ��������
	{
		putchar(x);
	}
	fclose(file);
#endif
#if VAR == 4
	//�������� ���������� �����(����������������� �������)

	student group[] = 
	{
		{"Ivanov",      {5,4,4}},
		{"Petrashevcky",{4,3,4}},
		{"Kim",         {5,3,5}},
		{"Pupkin",      {4,2,3}},
		{"Kuzin",       {5,5,5}},
	};
		
	const int n = sizeof group / sizeof * group;
	int i;//������ �� ��������
	int j;//������ �� ������
	FILE* file = fopen("test2.txt", "wt");
	if (!file)
	{
		perror("test2.txt");
		exit(1);
	}

	for ( i = 0; i < n; i++)
	{
		fprintf(file, "%s", group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d", group[i].grade[j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);
#endif
#if VAR == 5
	//�������������� ���������� �����(����������������� �������)


	student x;
	int stud_id  = 3;//������������� �������� �������� ���������� ��������� ������ Pupkin
	int grade_ig = 1;//������������� ������ ������� ���������� ��������� 2
	int value    = 3;//�������� ������������ ������
	int i;/*������ �� ��������*/ int j;/*������ �� ������*/
	long pos;//������� ������� � �����
	FILE* file = fopen("test2.txt", "r + t");//�������� ����� ��� ������ � ���������
	if (!file)
	{
		perror("test2.txt");
		exit(1);
	}
	/*��������� ����������*/
	for (i = 0; i <= stud_id; i++)
	{
		pos = ftell(file); //printf("%d = %d\n", i, pos);
		fscanf(file, "%s", x.last_name);
		//printf("s[%d] = %d\n", i, pos);
		for (j = 0; j < MAXGRADES; j++)
		{
			fscanf(file, "%2d", &x.grade[j]);
		}
		fscanf(file, "\n");
	}
	x.grade[grade_ig] = value;

	fseek(file, pos, SEEK_SET);
	/*������ ���������*/
	fprintf(file, "%s", x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d", x.grade[j]);
	}
	//fprintf(file, "\n");
	fclose(file);
#endif
#if VAR == 6
		//�������� ���������� �����(������� �������)
	student group[] =
	{
		{"Ivanov",      {5,4,4}},
		{"Petrashevcky",{4,3,4}},
		{"Kim",         {5,3,5}},
		{"Pupkin",      {4,2,3}},
		{"Kuzin",       {5,5,5}},
	};

	const int n = sizeof group / sizeof * group;
	int i;//������ �� ��������
	int j;//������ �� ������
	FILE* file = fopen("test3.txt", "wt");
	if (!file)
	{
		perror("test3.txt");
		exit(1);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(file, "%-*s", MAXLEN, group[i].last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d", group[i].grade[j]);
		}
		fprintf(file, "\n");
	}
	fclose(file);

#endif
#if VAR == 7
	//�������������� ���������� �����(������� �������)


	student x;
	int stud_id = 3;//������������� �������� �������� ���������� ��������� ������ Pupkin
	int grade_ig = 1;//������������� ������ ������� ���������� ��������� 2
	int value = 5;//�������� ������������ ������
	//int i;/*������ �� ��������*/ 
	int j;/*������ �� ������*/
	long pos;//������� ������� � �����
	FILE* file = fopen("test3.txt", "r + t");//�������� ����� ��� ������ � ���������
	if (!file)
	{
		perror("test3.txt");
		exit(1);
	}
	/*��������� ����������*/
		pos = stud_id * (MAXLEN + 2 * MAXGRADES + 2) + MAXLEN;
		
		fseek(file, pos, SEEK_SET);
		
			for (j = 0; j < MAXGRADES; j++)
			{
				fscanf(file, "%2d", &x.grade[j]);
			}
			
		
		x.grade[grade_ig] = value;

		fseek(file, pos, SEEK_SET);
		/*������ ���������*/
		//fprintf(file, "%s", x.last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d", x.grade[j]);
		}
		
		fclose(file);
		
#endif
		//====================================================================================
#if VAR==8
// �������� ��������� ����� ������� �������
//������ ���������� 
//c �������� ������������ ���������

		student group[] =
		{
			{"Ivanov",      {5,4,4}},
			{"Petroshevsky",{4,3,4}},
			{"Kim",         {5,3,5}},
			{"Pupkin",      {4,2,3}},
			{"Kuzin",       {5,5,5}}
		};

		const int n = sizeof group / sizeof * group;
		FILE* file = fopen("test4.dat", "wb");

		if (!file)
		{
			perror("test4.dat not open.ERROR ");
			exit(1);
		}
		//=========================================================
		fwrite(&n, sizeof(int), 1, file);//��������� ���������� �������
		fwrite(group, sizeof(student), n, file);
		//=========================================================
		fclose(file);
#endif

		//*****************************************************************************
#if VAR==9 // �������������� ��������� ����� ������� ������� 
//c �������� ������������ ���������
		student x;
		int stud_id = 3;//Puokin
		int grade_id = 1;//�������� 2-�� 
		int value = 3;// �� 3-��
		long pos;//������� � �����
		FILE* file = fopen("test4.dat", "r+b");
		if (!file)
		{
			perror("test4.dat not open.ERROR ");
			exit(1);
		}
		//===������� Pupkina=============================================
		pos = sizeof(int) + stud_id * sizeof(student);
		fseek(file, pos, SEEK_SET);
		fread(&x, sizeof(student), 1, file);
		//=========������ ��������=========================================
		x.grade[grade_id] = value;
		//==================���������� ���� ==============================
		fseek(file, pos, SEEK_SET);
		fwrite(&x, sizeof(student), 1, file);
		//=========================================================
		fclose(file);
#endif
}
