#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//符号的定义
#define ROW 3 
#define COL 3

//函数的声明
void CleanBoard( char board[ROW][COL], int row, int col);

void PrintBoard( char board[ROW][COL], int row, int col);

void PlayerMove( char board[ROW][COL], int row, int col);

void AIMove(char board[ROW][COL], int row, int col);

char GameOver(char board[ROW][COL], int row, int col);