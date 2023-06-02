#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//���ŵĶ���
#define ROW 3 
#define COL 3

//����������
void CleanBoard( char board[ROW][COL], int row, int col);

void PrintBoard( char board[ROW][COL], int row, int col);

void PlayerMove( char board[ROW][COL], int row, int col);

void AIMove(char board[ROW][COL], int row, int col);

char GameOver(char board[ROW][COL], int row, int col);