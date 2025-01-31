#include "contact.h"
#define   _CRT_SECURE_NO_WARNINGS

static int Findname(con* pc, char name[])
{
	assert(pc);
	for (int i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}
void Inittongxun(con* pc)
{
	assert(pc);
	pc->count = 0;
	memset(pc->data, 0, sizeof(pc->data));
}

void ADD(con* pc)
{
	assert(pc);
	if (pc->count == MAX)
	{
		printf("通讯录已满，无法存入");
		return;
	}
	printf("请输入姓名\n");
	scanf("%s", pc->data[pc->count].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("添加完成\n");
}

void ShowBoard( con* pc)
{
	assert(pc);
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n","姓名","性别","年龄","电话","住址");
	for (int i = 0; i < pc->count; i++)
	{
		printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\t\n", pc->data[i].name,
			                                       pc->data[i].sex,
			                                       pc->data[i].age,
			                                       pc->data[i].tele,
			                                       pc->data[i].address);
	}
	
	
}

void Delet(con* pc)
{
	assert(pc);
	printf("请输入要删除联系人的姓名：\n");
	char tem_name[MAX];
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("联系人不存在\n");
		return;
	}
	//删除、覆盖
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除完成\n");
}

//修改
void Modify(con* pc)
{
	assert(pc);
	char tem_name[MAX_NAME];
	printf("请输入要修改人的名字：\n");
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("该联系人不存在\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\t\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].address);
	printf("该联系人已找到，请输入：\n");
	printf("请输入姓名\n");
	scanf("%s", pc->data[pos].name);
	printf("请输入年龄\n");
	scanf("%d", &(pc->data[pos].age));
	printf("请输入性别\n");
	scanf("%s", pc->data[pos].sex);
	printf("请输入电话\n");
	scanf("%s", pc->data[pos].tele);
	printf("请输入地址\n");
	scanf("%s", pc->data[pos].address);
	
	printf("修改完成\n");
}

//查找联系人
void search(con* pc)
{
	assert(pc);
	char tem_name[MAX_NAME];
	printf("请输入要修改人的名字：\n");
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("该联系人不存在\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "姓名", "性别", "年龄", "电话", "住址");
	printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\t\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].address);
	printf("该联系人已找到\n");
}


//排序
int sort_by_name(const void* e1, const void* e2)
{
	return strcmp(((conpeo*)e1)->name,((conpeo*)e2)->name);
}
int sort_by_age(const void* e1, const void* e2)
{
	return ((conpeo*)e1)->age - ((conpeo*)e2)->age;
}
void sort(con* pc)
{
	assert(pc);
	int tem;
	do
	{
		printf("请输入排序方式：\n");
		printf("*************************************\n");
		printf("******* 1.name     2. age      ******\n");
		printf("*************************************\n");
		scanf("%d", &tem);
	} while (tem != 1 && tem != 2);
	
	int (*fun[])(const void*, const void*) = { sort_by_name,sort_by_age };
	qsort(pc->data,pc->count,sizeof(conpeo),fun[tem-1]);
	printf("排序成功\n");
}
