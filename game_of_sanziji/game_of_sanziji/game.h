#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//��ʼ��Ԫ��
void Initboard(char arr[ROW][COL], int j, int k);
//��ӡ����
void Display(char arr[ROW][COL], int row, int col);
//�û�����
void Playermove(char arr[ROW][COL], int row, int col);
//�ж���Ӯ
int judgement(char arr[ROW][COL], int row, int col);
//��������
int Computer(char arr[ROW][COL], int row, int col);
//ƽ���ж�
int judgement2(char arr[ROW][COL], int row, int col);
