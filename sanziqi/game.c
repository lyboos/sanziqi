#define  _CRT_SECURE_NO_WARNINGS 
#include"game.h"
void huizhi(char board[ROW][COL], int row, int col)
{
	int i, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j=0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void display(char board[ROW][COL], int row, int col)
{
	int j,i = 0;
	for (; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
			printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n"); 
		}
		/*printf(" %c | %c | %c \n", board[i][0],board[i][1],board[i][2]);
		if (i == row-1)
			break;
		printf("---|---|---\n");    反面案例*/
	}
}
void player(char board[ROW][COL], int row, int col)
{
	int x, y;
	printf("*your turn\n");
	while (1) {
		printf("输入要下的坐标:");
		scanf("%d %d",&x,&y);
		if (x >= 1 && x <= ROW && y >= 1 && y <= COL)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else printf("坐标处已有棋子！\n");
		}
		else printf("坐标非法\n");
	}

}
void comput(char board[ROW][COL], int row, int col)
{
	printf("#computer's turn\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}
int full(char board[ROW][COL], int row, int col)
{
	int i=0;
	int j = 0;
	for ( i = 0; i < row; i++)
	{
		for (j = 0; j< col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
char jiance(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for ( i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];

		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i]!=' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return  board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	if (1==full(board, ROW, COL))
		return 'Q';
	else return 'C';
}
