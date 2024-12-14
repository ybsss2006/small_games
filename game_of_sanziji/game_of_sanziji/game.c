#include "game.h"
void Initboard(char arr[ROW][COL], int j, int k)
{
	for (int i = 0; i < j; i++)
	{
		for (int ii = 0; ii < k; ii++)
		{
			arr[i][ii] = ' ';
		}
	}
}

void Display(char arr[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		
		for (int k = 0; k < col; k++)
		{
			if (k != col - 1)
				printf(" %c |", arr[i][k]);
			else
				printf(" %c \n",arr[i][k]);
		}
		//printf(" %c | %c | %c \n", arr[i][0], arr[i][1], arr[i][2]);
		if (i < (row - 1))
		{
			for (int k = 0; k < col; k++)
			{
				if (k != col - 1)
					printf("---|");
				else
					printf("---\n");
			}
		}
	}
}

void Playermove(char arr[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	
	while (1)
	{
		printf("玩家请下棋（输入坐标）：\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (arr[x-1][y-1] == ' ')
			{
				arr[x-1][y-1] = '*';
				break;
			}
			else
				printf("该格已被占用，请重输\n");
		}
		else
			printf("输入格式错误！\n");

	}
}
int judgement2(char arr[ROW][COL], int row, int col)
{
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 1;
			}
		}
	}
	printf("平局\n");
	return 0;
}
int judgement(char arr[ROW][COL], int row, int col)
{  //行判断
	for (int i = 0; i < row; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '*')
		{
			printf("玩家获胜！\n");
			return 0;
		}
		else if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] == '#')
		{
			printf("电脑获胜！\n");
			return 0;
		}

	}
   //列判断
	for (int i = 0; i < col; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == '*')
		{
			printf("玩家获胜！\n");
			return 0;
		}
		else if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] == '#')
		{
			printf("电脑获胜！\n");
			return 0;
		}
	}
	//对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == '*')
	{
		printf("玩家获胜！\n");
		return 0;
	}
	else if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] == '#')
	{
		printf("电脑获胜！\n");
		return 0;
	}
	else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == '*')
	{
		printf("玩家获胜！\n");
		return 0;
	}
	else if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] == '#')
	{
		printf("电脑获胜！\n");
		return 0;
	}

	

	return 1;
}
int Computer(char arr[ROW][COL], int row, int col)
{
	//行堵
	if (arr[0][0] == arr[0][1] && arr[0][2] == ' ' && arr[0][0] != ' ')
	{
		arr[0][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][0] == arr[0][2] && arr[0][1] == ' ' && arr[0][0] != ' ')
	{
		arr[0][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][1] == arr[0][2] && arr[0][0] == ' ' && arr[0][1] != ' ')
	{
		arr[0][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[1][0] == arr[1][1] && arr[1][2] == ' ' && arr[1][0] != ' ')
	{
		arr[1][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[1][0] == arr[1][2] && arr[1][1] == ' ' && arr[1][0] != ' ')
	{
		arr[1][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[1][1] == arr[1][2] && arr[1][0] == ' ' && arr[1][1] != ' ')
	{
		arr[1][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[2][0] == arr[2][1] && arr[2][2] == ' ' && arr[2][0] != ' ')
	{
		arr[2][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[2][0] == arr[2][2] && arr[2][1] == ' ' && arr[2][0] != ' ')
	{
		arr[2][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[2][1] == arr[2][2] && arr[2][0] == ' ' && arr[2][1] != ' ')
	{
		arr[2][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	//列堵
	if (arr[1][0] == arr[2][0] && arr[0][0] == ' ' && arr[1][0] != ' ')
	{
		arr[0][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][0] == arr[2][0] && arr[1][0] == ' ' && arr[2][0] != ' ')
	{
		arr[1][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][0] == arr[1][0] && arr[2][0] == ' ' && arr[0][0] != ' ')
	{
		arr[2][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[1][1] == arr[2][1] && arr[0][1] == ' ' && arr[1][1] != ' ')
	{
		arr[0][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][1] == arr[2][1] && arr[1][1] == ' ' && arr[2][1] != ' ')
	{
		arr[1][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][1] == arr[1][1] && arr[2][1] == ' ' && arr[0][1] != ' ')
	{
		arr[2][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[1][2] == arr[2][2] && arr[0][2] == ' ' && arr[1][2] != ' ')
	{
		arr[0][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][2] == arr[2][2] && arr[1][2] == ' ' && arr[2][2] != ' ')
	{
		arr[1][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][2] == arr[1][2] && arr[2][2] == ' ' && arr[0][2] != ' ')
	{
		arr[2][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	//对角线
	if (arr[0][0] == arr[1][1] && arr[2][2] == ' ' && arr[0][0] != ' ')
	{
		arr[2][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[1][1] == arr[2][2] && arr[0][0] == ' ' && arr[1][1] != ' ')
	{
		arr[0][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[0][0] == arr[2][2] && arr[1][1] == ' ' && arr[0][0] != ' ')
	{
		arr[1][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[2][0] == arr[1][1] && arr[0][2] == ' ' && arr[2][0] != ' ')
	{
		arr[0][2] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[1][1] == arr[0][2] && arr[2][0] == ' ' && arr[1][1] != ' ')
	{
		arr[2][0] = '#';
		printf("电脑下棋\n");
		return 0;
	}
	if (arr[2][0] == arr[0][2] && arr[1][1] == ' ' && arr[2][0] != ' ')
	{
		arr[1][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}

	if (arr[1][1] == ' ')
	{
		arr[1][1] = '#';
		printf("电脑下棋\n");
		return 0;
	}


	else
	{
		while (1)
		{
			int x = 0;
			int y = 0;
			x = rand() % 3;
			y = rand() % 3;
			if (arr[x][y] == ' ')
			{
				arr[x][y] = '#';
				printf("电脑下棋\n");
				break;
			}
		}
	}
	return 0;
	
}
