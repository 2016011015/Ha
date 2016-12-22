#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h> 
#include<stdlib.h> 
#include<conio.h> 
#include<time.h> 
#include<Windows.h>
int code[4][4] = { 0,0,0,0,
0,0,0,0,
0,0,0,0,
0,0,0,0 };
int temp[5];
int move = 0;
int score = 0;

void Move(int code[4][4],unsigned __int8 ui8Move)
{
	int iLast, iBack;
	int iResult[4][4];
	unsigned __int8 ui8Loop1,ui8Loop2;
	memcpy_s(iResult, 16 * sizeof(int), code, 16 * sizeof(int));

	memset(code, 0, 16 * sizeof(int));
	switch (ui8Move)
	{
	case 0:
		for (ui8Loop1 = 0; ui8Loop1 < 4; ++ui8Loop1)
		{
			iLast = 0;
			iBack = 0;
			for (ui8Loop2 = 0; ui8Loop2 < 4; ++ui8Loop2)
			{
				if (iResult[ui8Loop1][ui8Loop2])
				{
					if (!iBack || iBack == iResult[ui8Loop1][ui8Loop2])
					{
						code[ui8Loop1][iLast]+= iResult[ui8Loop1][ui8Loop2];
						if (iBack)
						{
							++iLast;
							iBack = 0;
						}
						else
						{
							iBack = code[ui8Loop1][iLast];
						}
					}
					else
					{
						iBack= code[ui8Loop1][++iLast] = iResult[ui8Loop1][ui8Loop2];
					}
				}
			}
		}
		break;
	case 1:
		for (ui8Loop1 = 0; ui8Loop1 < 4; ++ui8Loop1)
		{
			iLast = 3;
			iBack = 0;
			for (ui8Loop2 = 3; ui8Loop2 < 4; --ui8Loop2)
			{
				if (iResult[ui8Loop1][ui8Loop2])
				{
					if (!iBack || iBack == iResult[ui8Loop1][ui8Loop2])
					{
						code[ui8Loop1][iLast] += iResult[ui8Loop1][ui8Loop2];
						if (iBack)
						{
							--iLast;
							iBack = 0;
						}
						else
						{
							iBack = code[ui8Loop1][iLast];
						}
					}
					else
					{
						iBack = code[ui8Loop1][--iLast] = iResult[ui8Loop1][ui8Loop2];
					}
				}
			}
		}
		break;
	case 2:
		for (ui8Loop1 = 0; ui8Loop1 < 4; ++ui8Loop1)
		{
			iLast = 0;
			iBack = 0;
			for (ui8Loop2 = 0; ui8Loop2 < 4; ++ui8Loop2)
			{
				if (iResult[ui8Loop2][ui8Loop1])
				{
					if (!iBack || iBack == iResult[ui8Loop2][ui8Loop1])
					{
						code[iLast][ui8Loop1] += iResult[ui8Loop2][ui8Loop1];
						if (iBack)
						{
							++iLast;
							iBack = 0;
						}
						else
						{
							iBack = code[iLast][ui8Loop1];
						}
					}
					else
					{
						iBack = code[++iLast][ui8Loop1] = iResult[ui8Loop2][ui8Loop1];
					}
				}
			}
		}
		break;
	case 3:
		for (ui8Loop1 = 0; ui8Loop1 < 4; ++ui8Loop1)
		{
			iLast = 3;
			iBack = 0;
			for (ui8Loop2 = 3; ui8Loop2 < 4; --ui8Loop2)
			{
				if (iResult[ui8Loop2][ui8Loop1])
				{
					if (!iBack || iBack == iResult[ui8Loop2][ui8Loop1])
					{
						code[iLast][ui8Loop1] += iResult[ui8Loop2][ui8Loop1];
						if (iBack)
						{
							--iLast;
							iBack = 0;
						}
						else
						{
							iBack = code[iLast][ui8Loop1];
						}
					}
					else
					{
						iBack = code[--iLast][ui8Loop1] = iResult[ui8Loop2][ui8Loop1];
					}
				}
			}
		}
		break;
	};
}

#define abs(x) ((x)>=0?(x):(-(x)))
#define d(x,y) ((x)>(y)?(x)/(y):(y)/(x))

int Calc(int code[4][4])
{
	int iResult=0;
	unsigned __int8 i, j;
	for (i=0;i<4;++i)
		for (j = 0; j < 3; ++j)
		{
			if (code[i][j] && code[i][j + 1])
				iResult += d(code[i][j], code[i][j + 1]);
			else
				iResult += 2;
			if (code[j][i] && code[j + 1][i])
				iResult += d(code[j][i], code[j + 1][i]);
			else
				iResult += 2;
		}
	return iResult;
}

char AI2(int code[4][4])
{
	int space[4][4];
	char cLast = 0;
	int iBest = INT_MAX;
	int iSpace;
	unsigned __int8 r = 0;
	for (unsigned __int8 i = 0; i < 4; ++i)
	{
		memcpy_s(space, 16 * sizeof(int), code, 16 * sizeof(int));
		Move(space,i);
		if (memcmp(space, code, 16 * sizeof(int))&&(iSpace = Calc(space)) < iBest)
		{
			iBest = iSpace;
			r = i;
		}
	}
	switch (r)
	{
	case 0:
		return 'w';
	case 1:
		return 's';
	case 2:
		return 'a';
	case 3:
		return 'd';
	}
	return 'w';
}
char AI(int move)
{
	//Sleep(100);
	switch (move % 4)
	{
	case 1:
		return 'a';
	case 3:
		return 'd';
	default:
		return 'w';
	}
}
void print(void)
{
	int i, j;
	system("cls");
	printf("Score:%d Move:%d\n", score, move);
	printf("|--------------------------------------|\n");
	for (i = 0; i <= 3; i++)
	{
		for (j = 0; j <= 3; j++)
		{
			if (code[i][j] == 0)
			{
				printf("      ");
			}
			else
			{
				printf("%6d", code[i][j]);
			}
		}
		printf("|\n|--------------------------------------|\n");
	}
}

int add(void)
{
	int i;
	int t = 0;
	int change = 0;
	do
	{
		for (i = 0; i <= 3; i++)
		{
			if (temp[i] == 0)
			{
				if (temp[i] != temp[i + 1])
					change = 1;
				temp[i] = temp[i + 1];
				temp[i + 1] = 0;
			}
		}
		t++;
	} while (t <= 3);
	for (i = 1; i <= 3; i++)
	{
		if (temp[i] == temp[i - 1])
		{

			if (temp[i] != 0)
			{
				change = 1;
				score +=temp[i];
			}
			temp[i - 1] = temp[i - 1] * 2;
			temp[i] = 0;
		}
	}
	do
	{
		for (i = 0; i <= 3; i++)
		{
			if (temp[i] == 0)
			{
				temp[i] = temp[i + 1];
				temp[i + 1] = 0;
			}
		}
		t++;
	} while (t <= 3);
	return change;
}

int main(void)
{
	int gameover = 0;
	int i, j;
	int codejudge[4][4] = { 90,90,90,90,
		90,90,90,90,
		90,90,90,90,
		90,90,90,90 };
	int codejudge2[4][4] = { 0,0,0,0,
	0,0,0,0,
	0,0,0,0,
	0,0,0,0 }; 
	int change = 1;
	char input;
	int gameoverjudge = 1;
	srand((unsigned)time(NULL));
	printf("0.AI     Not 0:User\n");
	int ai;
	int round = 1;
	scanf("%d", &ai);
	int shsh = 0;
	while (gameover == 0)
	{
		if (change >= 1)
		{
			do
			{
				i = ((unsigned)rand()) % 4;
				j = ((unsigned)rand()) % 4;
			} while (code[i][j] != 0);
			if (((unsigned)rand()) % 6 == 0)
			{
				code[i][j] = 4;
			}
			else
			{
				code[i][j] = 2;
			}
			move++;
		}
		print();
	shshs:
		if (ai != 0)
			input = _getch();
		else if (shsh != 1)
		{
			//input = AI2(code);
		iq:
			input = AI(round);
		}
		else
			input = 's';
		change = 0;
		switch (input)
		{
		case '0':
			printf("Are you sure to exit?(y/n)");
			input = getchar();
			if (input == 'y' || input == 'Y')
				exit(0);
			else
				printf("\r                                                   \r");
			break;
		case 'W':
		case 'w':
		case 0x48:
			for (j = 0; j <= 3; j++)
			{
				for (i = 0; i <= 3; i++)
				{
					temp[i] = code[i][j];
				}
				temp[4] = 0;
				change = change + add();
				for (i = 0; i <= 3; i++)
				{
					code[i][j] = temp[i];
				}
			}
			break;
		case 'A':
		case 'a':
		case 0x4b:
			for (i = 0; i <= 3; i++)
			{
				for (j = 0; j <= 3; j++)
				{
					temp[j] = code[i][j];
				}
				temp[4] = 0;
				change = change + add();
				for (j = 0; j <= 3; j++)
				{
					code[i][j] = temp[j];
				}
			}
			break;
		case 'S':
		case 's':
		case 0x50:
			for (j = 0; j <= 3; j++)
			{
				for (i = 0; i <= 3; i++)
				{
					temp[i] = code[3 - i][j];
				}
				temp[4] = 0;
				change = change + add();
				for (i = 0; i <= 3; i++)
				{
					code[3 - i][j] = temp[i];
				}
			}
			break;
		case 'D':
		case 'd':
		case 0x4d:
			for (i = 0; i <= 3; i++)
			{
				for (j = 0; j <= 3; j++)
				{
					temp[j] = code[i][3 - j];
				}
				temp[4] = 0;
				change = change + add();
				for (j = 0; j <= 3; j++)
				{
					code[i][3 - j] = temp[j];
				}
			}
			break;
		}
		gameover = 1;
		for (i = 0; i <= 3; i++)
			for (j = 0; j <= 3; j++)
				if (code[i][j] == 0)
					gameover = 0;
		if (gameover == 1)
		{
			int m,n;
			gameoverjudge = 1;
			for (m = 0; m < 4; m+=1)
			{
				for (n = 0; n < 4; n+=1)
				{
					if (codejudge[m][n] != code[m][n])
						gameoverjudge = 0;
				}
			}
			if (gameoverjudge == 1)
				goto gameover;
			else
			{
				int p, q;
				for (p = 0; p < 4; p+=1)
				{
					for (q = 0; q < 4; q+=1)
					{
						codejudge[p][q] = code[p][q];
					}
				}
				gameover = 0;
			}
		}
		int k,l;
		int AIdownjudge = 1;
		for (k = 0; k < 4; k += 1)
		{
			for (l = 0; l < 4; l += 1)
			{
				if (codejudge2[k][l] != code[k][l])
					AIdownjudge = 0;
			}
		}
		if (AIdownjudge == 1)
		{
			shsh = 1;
			goto shshs;
		}
		else
		{
			int p, q;
			for (p = 0; p < 4; p += 1)
			{
				for (q = 0; q < 4; q += 1)
				{
					codejudge2[p][q] = code[p][q];
				}
			}
		}
		round += 1;
		if (shsh == 1 && input == 's' && (round % 4 == 0 || round % 4 == 2))
			goto shshs;
		else if (shsh == 1 && input == 's')
			goto iq;
	}
gameover:
	printf("Game over!\n");
	fseek(stdin, 0, SEEK_END);
	getchar();
	Sleep(10000);
	return 0;
}