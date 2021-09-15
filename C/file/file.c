//пример работы с файлами
#define _CRT_SECURE_NO_WARNINGS
#define MAXLEN 32
#define MAXGRADES 3
	//структура студент (ФИО) сдавший 3 экзамена
typedef struct
{
	char last_name[MAXLEN];//ФИО
	int grade[MAXGRADES];//оценки

} student;
#include <stdio.h>
#include <stdlib.h>
#define VAR 9

int main()
{
#if VAR == 1
//создание текстового файла(последовательного доступа)
	FILE* file = fopen("test1.txt","wt");
	if (!file)
	{
		perror("test1.txt");
		exit(1);
	}
	fputc('*', file);//запись одного символа
	fputs("Hello, world!\n", file);//запись строки
	fprintf(file, "%d\n", 2011);//форматированная запись в файла по спецификации %
	

	fclose(file);
#endif
#if VAR == 2
	//чтение текстового файла(последовательного доступа)
	int x; char buf[256];
	FILE* file = fopen("test1.txt", "rt");
	if (!file)
	{
		perror("test.txt");
		exit(1);
	}
	x = fgetc(file);/*чтение одного символа из файла*/							putchar(x);//контрольная печать
	fgets(buf, sizeof buf, file);/*чтение строки из файла */					fputs(buf, stdout);//контрольная печать
	fscanf(file, "%d", &x);/*форматированное чтение из файла по спецификации%*/	printf(" % d\n", x);//контрольная печать
	
	fclose(file);
#endif
#if VAR == 3
	//чтение текстового файла(неизвестной структуры)
	int x; 
	FILE* file = fopen("file.c", "rt");
	if (!file)
	{
		perror("file.c");
		exit(1);
	}
	system("chcp 1251 > nul");
	while ((x = fgetc(file)) != EOF)//(!feof(file))- лишнняя итерация
	{
		putchar(x);
	}
	fclose(file);
#endif
#if VAR == 4
	//создание текстового файла(последовательного доступа)

	student group[] = 
	{
		{"Ivanov",      {5,4,4}},
		{"Petrashevcky",{4,3,4}},
		{"Kim",         {5,3,5}},
		{"Pupkin",      {4,2,3}},
		{"Kuzin",       {5,5,5}},
	};
		
	const int n = sizeof group / sizeof * group;
	int i;//индекс по студенту
	int j;//индекс по оценке
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
	//редактирование текстового файла(последовательного доступа)


	student x;
	int stud_id  = 3;//идентификатор студента которому необходимо исправить оценку Pupkin
	int grade_ig = 1;//идентификатор оценки которую необходимо исправить 2
	int value    = 3;//значение исправленной оценки
	int i;/*индекс по студенту*/ int j;/*индекс по оценке*/
	long pos;//позиция курсора в файле
	FILE* file = fopen("test2.txt", "r + t");//открытие файла для чтения и изменения
	if (!file)
	{
		perror("test2.txt");
		exit(1);
	}
	/*Считываем информацию*/
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
	/*Вносим изменения*/
	fprintf(file, "%s", x.last_name);
	for (j = 0; j < MAXGRADES; j++)
	{
		fprintf(file, "%2d", x.grade[j]);
	}
	//fprintf(file, "\n");
	fclose(file);
#endif
#if VAR == 6
		//создание текстового файла(прямого доступа)
	student group[] =
	{
		{"Ivanov",      {5,4,4}},
		{"Petrashevcky",{4,3,4}},
		{"Kim",         {5,3,5}},
		{"Pupkin",      {4,2,3}},
		{"Kuzin",       {5,5,5}},
	};

	const int n = sizeof group / sizeof * group;
	int i;//индекс по студенту
	int j;//индекс по оценке
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
	//редактирование текстового файла(прямого доступа)


	student x;
	int stud_id = 3;//идентификатор студента которому необходимо исправить оценку Pupkin
	int grade_ig = 1;//идентификатор оценки которую необходимо исправить 2
	int value = 5;//значение исправленной оценки
	//int i;/*индекс по студенту*/ 
	int j;/*индекс по оценке*/
	long pos;//позиция курсора в файле
	FILE* file = fopen("test3.txt", "r + t");//открытие файла для чтения и изменения
	if (!file)
	{
		perror("test3.txt");
		exit(1);
	}
	/*Считываем информацию*/
		pos = stud_id * (MAXLEN + 2 * MAXGRADES + 2) + MAXLEN;
		
		fseek(file, pos, SEEK_SET);
		
			for (j = 0; j < MAXGRADES; j++)
			{
				fscanf(file, "%2d", &x.grade[j]);
			}
			
		
		x.grade[grade_ig] = value;

		fseek(file, pos, SEEK_SET);
		/*Вносим изменения*/
		//fprintf(file, "%s", x.last_name);
		for (j = 0; j < MAXGRADES; j++)
		{
			fprintf(file, "%2d", x.grade[j]);
		}
		
		fclose(file);
		
#endif
		//====================================================================================
#if VAR==8
// создание бинарного файла прямого доступа
//строки одинаковые 
//c записями определенной структуры

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
		fwrite(&n, sizeof(int), 1, file);//добавляем количество записей
		fwrite(group, sizeof(student), n, file);
		//=========================================================
		fclose(file);
#endif

		//*****************************************************************************
#if VAR==9 // редактирование бинарного файла прямого доступа 
//c записями определенной структуры
		student x;
		int stud_id = 3;//Puokin
		int grade_id = 1;//исправил 2-ку 
		int value = 3;// на 3-ку
		long pos;//позиция в файле
		FILE* file = fopen("test4.dat", "r+b");
		if (!file)
		{
			perror("test4.dat not open.ERROR ");
			exit(1);
		}
		//===находим Pupkina=============================================
		pos = sizeof(int) + stud_id * sizeof(student);
		fseek(file, pos, SEEK_SET);
		fread(&x, sizeof(student), 1, file);
		//=========меняем значение=========================================
		x.grade[grade_id] = value;
		//==================записываем файл ==============================
		fseek(file, pos, SEEK_SET);
		fwrite(&x, sizeof(student), 1, file);
		//=========================================================
		fclose(file);
#endif
}
