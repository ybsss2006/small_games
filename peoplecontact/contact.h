#pragma once
#define   _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#define MAX 100
#define MAX_NAME 15
#define MAX_sex 5
#define MAX_TELE 12
#define MAX_ADDRESS 20

typedef struct contact_people
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_sex];
	char tele[MAX_TELE];
	char address[MAX_ADDRESS];
}conpeo;

typedef struct con
{
	conpeo data[MAX];
	int count;
}con;

//��ʼ������
void Inittongxun(con* pc);
//�����ϵ��
void ADD(con* pc);
//��ӡͨѶ¼
void ShowBoard(con* pc);
//�޸�ͨѶ¼
void Modify(con* pc);
//ɾ����ϵ��
void Delet(con* pc);
//������ϵ��
void search(con* pc);
//����
void sort(con* pc);