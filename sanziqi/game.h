#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
void huizhi(char board[ROW][COL], int row, int col);
void display(char board[ROW][COL], int row, int col);
void player(char board[ROW][COL], int row, int col);
void comput(char board[ROW][COL], int row, int col);
char jiance(char board[ROW][COL], int row, int col);
int full(char board[ROW][COL], int row, int col);