#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int add(int x, int y)
{
	return x + y;
}
int jian(int x, int y)
{
	return x - y;
}
int mul(int x, int y)
{
	return x * y;
}
int div(int x, int y)
{
	return x / y;
}
int yu(int x, int y)
{
	return x % y;
}
int mi(int x, int y)
{
	return x ^ y;
}
void menu()
{
	printf("****************************************\n");
	printf("****** 1.��   2.��    3.��    **********\n");
	printf("****** 4.��   5.ȡ��  6.��  ************\n");
	printf("****** 0.�˳�             **************\n");
	printf("****************************************\n");
	printf("��ѡ��ģʽ��\n");
}
int main()
{
	int input = 0;
	do
	{
		int (*calculate[6])(int, int) = { add,jian,mul,div,yu,mi };
		menu();
		int x;
		int y;
		scanf("%d", &input);
		if (input >= 1 && input <= 6)
		{
			printf("�������������ݣ�\n");
			scanf("%d %d", &x, &y);
			int ret = calculate[input - 1](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("���˳�\n");
			
		}
		else
			printf("���벻�Ϸ�\n");

	} while (input);
	
	return 0;
}