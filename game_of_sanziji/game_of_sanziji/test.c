
#include "game.h"
void menu()
{
	printf("**************************\n");
	printf("******* 1 play   *********\n");
	printf("******* 0 exit   *********\n");
	printf("**************************\n");
}
void game()
{
	int judge = 1;
	char board[ROW][COL];
	Initboard(board, ROW, COL);
	Display(board, ROW, COL);
	while (1)
	{
		int a;
		Playermove(board, ROW, COL);
		Display(board, ROW, COL);
		judge = judgement(board, ROW, COL);
		if (0 == judge)
			break;
		judge = judgement2(board, ROW, COL);
		if (0 == judge)
			break;
		a=Computer(board, ROW, COL);
		Display(board, ROW, COL);
		judge = judgement(board, ROW, COL);
		if (0 == judge)
			break;
		judge = judgement2(board, ROW, COL);
		if (0 == judge)
			break;

	}
	//Playermove(board, ROW, COL);
	//Display(board, ROW, COL);
}
int main()
{
	int input = 0;
	do
	{
		menu();
		srand((unsigned int)time(NULL));
		printf("«Î—°‘Ò\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÕÀ≥ˆ”Œœ∑\n");
			break;
		default:
			printf(" ‰»Î¥ÌŒÛ£°\n");
			break;
			
		}
	} while (input);
	return 0;
}