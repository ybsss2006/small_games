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
	printf("****** 1.加   2.减    3.乘    **********\n");
	printf("****** 4.除   5.取余  6.幂  ************\n");
	printf("****** 0.退出             **************\n");
	printf("****************************************\n");
	printf("请选择模式：\n");
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
			printf("请输入两个数据：\n");
			scanf("%d %d", &x, &y);
			int ret = calculate[input - 1](x, y);
			printf("%d\n", ret);
		}
		else if (input == 0)
		{
			printf("已退出\n");
			
		}
		else
			printf("输入不合法\n");

	} while (input);
	
	return 0;
}