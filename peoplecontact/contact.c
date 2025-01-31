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
		printf("ͨѶ¼�������޷�����");
		return;
	}
	printf("����������\n");
	scanf("%s", pc->data[pc->count].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pc->count].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pc->count].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pc->count].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pc->count].address);
	pc->count++;
	printf("������\n");
}

void ShowBoard( con* pc)
{
	assert(pc);
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n","����","�Ա�","����","�绰","סַ");
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
	printf("������Ҫɾ����ϵ�˵�������\n");
	char tem_name[MAX];
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("��ϵ�˲�����\n");
		return;
	}
	//ɾ��������
	for (int i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("ɾ�����\n");
}

//�޸�
void Modify(con* pc)
{
	assert(pc);
	char tem_name[MAX_NAME];
	printf("������Ҫ�޸��˵����֣�\n");
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\t\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].address);
	printf("����ϵ�����ҵ��������룺\n");
	printf("����������\n");
	scanf("%s", pc->data[pos].name);
	printf("����������\n");
	scanf("%d", &(pc->data[pos].age));
	printf("�������Ա�\n");
	scanf("%s", pc->data[pos].sex);
	printf("������绰\n");
	scanf("%s", pc->data[pos].tele);
	printf("�������ַ\n");
	scanf("%s", pc->data[pos].address);
	
	printf("�޸����\n");
}

//������ϵ��
void search(con* pc)
{
	assert(pc);
	char tem_name[MAX_NAME];
	printf("������Ҫ�޸��˵����֣�\n");
	scanf("%s", tem_name);
	int pos = Findname(pc, tem_name);
	if (-1 == pos)
	{
		printf("����ϵ�˲�����\n");
		return;
	}
	printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\t\n", "����", "�Ա�", "����", "�绰", "סַ");
	printf("%-15s\t%-5s\t%-5d\t%-12s\t%-20s\t\n", pc->data[pos].name,
		pc->data[pos].sex,
		pc->data[pos].age,
		pc->data[pos].tele,
		pc->data[pos].address);
	printf("����ϵ�����ҵ�\n");
}


//����
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
		printf("����������ʽ��\n");
		printf("*************************************\n");
		printf("******* 1.name     2. age      ******\n");
		printf("*************************************\n");
		scanf("%d", &tem);
	} while (tem != 1 && tem != 2);
	
	int (*fun[])(const void*, const void*) = { sort_by_name,sort_by_age };
	qsort(pc->data,pc->count,sizeof(conpeo),fun[tem-1]);
	printf("����ɹ�\n");
}
