#define _CRT_SECURE_NO_WARNINGS
#include "game.h"


void CleanBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';//此时该用单引号还是双引号
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
			{
				printf(" %c ", board[i][j]);//printf 打印字符串得用%c 而不是用%d
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j < col - 1)
					printf("---|");
				else
				{
					printf("---");
				}
			}
			printf("\n");
		}
		
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	//判断坐标的合法性
	while (1)
	{
		printf("请玩家输入落子位置：");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋
			//判断位置是否被占用
			if (board[x - 1][y - 1] ==  ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标已被占用请重新输入\n");
			}
		}
		else
		{
			printf("坐标非法,超过范围,请重新输入\n");
		}
	}
}


void AIMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("AI落子\n");
	
	while (1)
	{
		x = rand() % row + 1;
		y = rand() % col + 1;
		//判断位置是否被占用
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
	}
}

int Full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;//棋盘没有满
			}
				
		}
	}
	return 1;
}

char GameOver(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断三行是否相等
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
			return board[i][0];
	}
	//判断三列是否相等
	for (j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[0][j];
	}

	//判断斜对角线是否相等
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
	{
		return board[1][1];
	}

	//判断是否平局
	int ret = Full(board, row, col);
	if (ret == 1)
	{
		return 'D';
	}
	
	//继续
	return 'C';
}