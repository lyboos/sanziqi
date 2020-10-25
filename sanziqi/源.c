#define  _CRT_SECURE_NO_WARNINGS 
#include"game.h"
void menu()
{
	printf("***********\n");
	printf("**1,play***\n");
	printf("**0,exit***\n");
	printf("***********\n");
}
void game()
{
	char stan = 0;
	srand((unsigned int)time(NULL));
	char board[ROW][COL] = { 0 };
	huizhi(board, ROW, COL);
	display(board, ROW, COL);
	while (1)
	{
		player(board,ROW,COL);
		display(board, ROW, COL);
		stan=jiance(board, ROW, COL);
		if (stan != 'C') 
		{ break; }
		comput(board, ROW, COL);
		display(board, ROW, COL);
		stan=jiance(board, ROW, COL);
		if (stan != 'C')
		{ break; }
	}
	if (stan == '*') printf("\nyou win!");
	else if (stan == '#') printf("\nyou lose!");
	else if (stan == 'Q') printf("\nDRAW");
	else if (stan == ' ') printf("\nERROR");
	printf("\nBack to main menu\n");
}
void start()
{
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("ÒÑÍË³ö");
			break;
		default:
			break;

		}
	} while (input);
}





int main()
{
	start();
	return 0;
}