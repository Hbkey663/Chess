#include"Chess.h"

void Init_board(char board[ROW][COL], int row, int col)
{
	memset(&board[0][0], ' ', sizeof(board[0][0])*row*col);
}

void Display_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i<row; i++)
	{
		printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
		if (i < row - 1)
		{
			printf("---|---|---\n");

		}
	}
}

void menu()
{
	printf("***************************\n");
	printf("****   Welcome Chess   ****\n");
	printf("***************************\n");
	printf("****  1.play   0.exit  ****\n");
	printf("***************************\n");
}

void Player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������,");
	while (1)
	{
		printf("���������꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y>=1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'X';
				break;
			}
			else
			{
				printf("�������������ӣ�\n");
			}
		}
		else
		{
			printf("��������겻���ڣ�\n");
		}
	}
}

void Computer_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�������壺\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '0';
			break;
		}
	}
}

int Check_full(char board[COL][ROW], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char Check_win(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] )
			return board[i][0];
	}
	for (int i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			return board[0][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[0][0];
	}
	if (board[2][0] == board[1][1] && board[1][1] == board[0][2])
	{
		return board[2][0];
	}
	if (Check_full(board, row, col))
		return 'f';
	else
		return ' ';
}

void Game()
{
	char board[ROW][COL] = { 0 };
	char ret = '0';
	Init_board(board, ROW, COL);
	Display_board(board, ROW, COL);
	while (1)
	{
		Player_move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = Check_win(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		printf("\n");
		Computer_move(board, ROW, COL);
		Display_board(board, ROW, COL);
		ret = Check_win(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
	}
	if (ret == 'X')
	{
		printf("���������ֵܣ���Ӯ�ˣ�\n");
	}
	else if (ret == '0')
	{
		printf("����Ӯ�ˣ�����һ����\n");
	}
	else if (ret == 'f')
	{
		printf("ƽ�֣�����һ�ְɣ���\n");
	}
}

void Test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			printf("�˳���\n");
			break;
		default:
			printf("������ˣ����������룺\n");
			break;
		}
	} while (input);
}