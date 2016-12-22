#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include<time.h>
void main()
{
start:
	system("cls");
	printf("Piano\n");
	printf("Please choose:\n");
	printf("a.enter  e:example  h:help  q:quit\n");
	char choose;
	int pin1 = 1;
	int ttime = 200;
	while (pin1)
	{
		choose = _getch();
		if (choose == 'a' || choose == 'A')
			goto execute;
		else if (choose == 'e' || choose == 'E')
			goto againex;
		else if (choose == 'q' || choose == 'Q')
			goto out;
		else if (choose == 'h' || choose == 'H')
			goto help;
	}
help:
	system("cls");
	printf("Page 1\n");
	printf("The following numbers are the notes:\n");
	printf("d f g h j k l r(C1) t y u i o p 1(Ci) 2 3 4 5 6 7 8 9 0 - = \n");
	printf("n: I know   b:back to main\n");
	char choice1;
	while (1)
	{
		choice1 = _getch();
		if (choice1 == 'n' || choice1 == 'N')
			break;
		else if (choice1 == 'b' || choice1 == 'B')
			goto start;
	}
	system("cls");
	printf("Page 2\n");
	printf("To execute, please set the length of the note(speed and BPM have similar meanings).\n");
	printf("n:I know  b:back to page 1\n");
	while (1)
	{
		choice1 = _getch();
		if (choice1 == 'n' || choice1 == 'N')
			break;
		else if (choice1 == 'b' || choice1 == 'B')
			goto help;
	}
	goto start;
execute:
	system("cls");
	int pin0 = 0;
	char input;
	printf("b:back to menu  q:quit\n");
	Beep(512, 1000);
	printf("Please enter the freq(ms per beat)\n");
	scanf("%d", &ttime);
	while (!pin0)
	{
		input = _getch();
		switch (input)
		{
		case '1':
			Beep(512, ttime);
			break;
		case '2':
			Beep(576, ttime);
			break;
		case '3':
			Beep(640, ttime);
			break;
		case '4':
			Beep(688, ttime);
			break;
		case '5':
			Beep(784, ttime);
			break;
		case '6':
			Beep(880, ttime);
			break;
		case '7':
			Beep(976, ttime);
			break;
		case 'r':
			Beep(256, ttime);
			break;
		case 't':
			Beep(292, ttime);
			break;
		case 'y':
			Beep(324, ttime);
			break;
		case 'u':
			Beep(348, ttime);
			break;
		case 'i':
			Beep(396, ttime);
			break;
		case 'o':
			Beep(448, ttime);
			break;
		case 'p':
			Beep(496, ttime);
			break;
		case 'k':
			Beep(224, ttime);
			break;
		case 'j':
			Beep(208, ttime);
			break;
		case 'h':
			Beep(192, ttime);
			break;
		case 'l':
			Beep(240, ttime);
			break;
		case '8':
			Beep(1036, ttime);
			break;
		case '9':
			Beep(1156, ttime);
			break;
		case '0':
			Beep(1292, ttime);
			break;
		case '-':
			Beep(1364, ttime);
			break;
		case '=':
			Beep(1580, ttime);
			break;
		case '^':
			Beep(1796, ttime);
			break;
		case '&':
			Beep(2012, ttime);
			break;
		case '*':
			Beep(2120, ttime);
			break;
		case '(':
			Beep(2336, ttime);
			break;
		case ')':
			Beep(2552, ttime);
			break;
		case 'q':
			goto out;
		case 'b':
			goto start;
		default:;
		}
		printf("%c\r", input);
		Sleep(ttime);
	}
againex:
	Beep(512, 1000);
	printf("Example Start:\n");
	int flag = 1;
	DWORD start, end;
	start = GetTickCount();
	while (flag)
	{
		end = GetTickCount();
		if (end - start >= 3000)
			flag = 0;
		else if (end - start >= 2000)
			printf("1\r");
		else if (end - start >= 1000)
			printf("2\r");
		else
			printf("3\r");
	}
	system("cls");
	printf("MUSIC\n");
	Beep(640, 400);
	Beep(512, 400);
	Beep(576, 400);
	Beep(400, 800);
	Beep(400, 400);
	Beep(576, 400);
	Beep(640, 400);
	Beep(512, 800);
	printf("a:again  b:back  q:quit\n");
	char choice;
	int pin2 = 1;
	while (pin2)
	{
		choice = _getch();
		if (choice == 'q' || choice == 'Q')
			goto out;
		else if (choice == 'a' || choice == 'A')
			goto againex;
		else if (choice == 'b' || choice == 'B')
			goto start;
	}
out:
	system("cls");
	printf("Electronic Piano Version 1.0 by Zishuo");
	Sleep(3000);
}
