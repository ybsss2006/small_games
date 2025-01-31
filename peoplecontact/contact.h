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

//初始化函数
void Inittongxun(con* pc);
//添加联系人
void ADD(con* pc);
//打印通讯录
void ShowBoard(con* pc);
//修改通讯录
void Modify(con* pc);
//删除联系人
void Delet(con* pc);
//查找联系人
void search(con* pc);
//排序
void sort(con* pc);