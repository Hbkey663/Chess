#pragma once
#ifndef __Game_H__
#define __Game_H__
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


#define ROW 3
#define COL 3

void Init_board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void Player_move(char board[ROW][COL], int row, int col);
void Computer_move(char board[ROW][COL], int row, int col);
int Check_full(char board[COL][ROW], int row, int col);
char Check_win(char board[ROW][COL], int row, int col);



#endif //__Game_H__