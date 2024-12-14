#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//初始化元素
void Initboard(char arr[ROW][COL], int j, int k);
//打印棋盘
void Display(char arr[ROW][COL], int row, int col);
//用户下棋
void Playermove(char arr[ROW][COL], int row, int col);
//判断输赢
int judgement(char arr[ROW][COL], int row, int col);
//电脑下棋
int Computer(char arr[ROW][COL], int row, int col);
//平局判定
int judgement2(char arr[ROW][COL], int row, int col);
