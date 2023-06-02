#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void game()
{
	//����3X3����
	char board[ROW][COL] ;

	//��ʼ������
	CleanBoard( board, ROW, COL );

	//��ӡ����
	PrintBoard( board, ROW, COL );

	//��������״̬
	char whether = 0;
	
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);
		
		//�ж��Ƿ��ʤ
		whether = GameOver(board, ROW, COL);
		if (whether != 'C')
		{
			break;
		}
		
		//��������
		AIMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);

		//�ж��Ƿ��ʤ
		whether = GameOver(board, ROW, COL);
		if (whether != 'C')
		{
			break;
		}
	}
	if (whether == '*')
	{
		printf("��һ�ʤ��\n");
	}
	else if (whether == '#')
	{
		printf("AI��ʤ��\n");
	}
	else if (whether == 'D')
	{
		printf("˫��ƽ�֣�\n");
	}
	printf("������Ϸ������\n\n\n");
}

void menu()
{
	printf("��������������������������\n");
	printf("��������1.��ʼ��Ϸ��������\n");
	printf("��������0.�˳���Ϸ��������\n");
	printf("��������������������������\n");
}

int main()
{
	int input = 1;
	srand((unsigned int)time(NULL));

	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		if (input == 1)
		{
			printf("�������ǿ�ʼ��Ϸ��\n");
			game();
		}
		else if (input == 0)
		{
			printf("�ѳɹ��˳���Ϸ��\n");
		}
		else
		{
			printf("����Ƿ����֣�������ѡ��\n");
		}
	} while (input);
	

	return 0;
}