#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	//生成3X3棋盘
	char board[ROW][COL] ;

	//初始化棋盘
	CleanBoard( board, ROW, COL );

	//打印棋盘
	PrintBoard( board, ROW, COL );

	//接受下棋状态
	char whether = 0;
	
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		
		//判断是否获胜
		whether = GameOver(board, ROW, COL);
		if (whether != 'C')
		{
			break;
		}
		
		//电脑下棋
		AIMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);

		//判断是否获胜
		whether = GameOver(board, ROW, COL);
		if (whether != 'C')
		{
			break;
		}
	}
	if (whether == '*')
	{
		printf("玩家获胜！\n");
	}
	else if (whether == '#')
	{
		printf("AI获胜！\n");
	}
	else if (whether == 'D')
	{
		printf("双方平局！\n");
	}
	printf("本局游戏结束！\n\n\n");
}

void menu()
{
	printf("—————————————\n");
	printf("————1.开始游戏————\n");
	printf("————0.退出游戏————\n");
	printf("—————————————\n");
}

int main()
{
	int input = 1;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("下面我们开始游戏！\n");
			game();
		}
		else if (input == 0)
		{
			printf("已成功退出游戏！\n");
		}
		else
		{
			printf("输入非法数字，请重新选择！\n");
		}
	} while (input);
	

	return 0;
}