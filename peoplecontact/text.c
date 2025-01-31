#define   _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("*************************************\n");
	printf("******* 1.add     2. delete    ******\n");
	printf("******* 3.show    4.modify     ******\n");
	printf("******* 0.exit    5.sort       ******\n");
	printf("******* 6.search               ******\n");
	printf("*************************************\n");
}
int main()
{
	int input;
	con tongxun;//创建通讯录
	Inittongxun(&tongxun);//初始化通讯录
	do
	{ 
		menu();
		printf("请进行选择-->:\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			ADD(&tongxun);
			break;
		case 2:
			Delet(&tongxun);
			break;
		case 3:
			ShowBoard(&tongxun);
			break;
		case 4:
			Modify(&tongxun);
			break;
		case 5:
			sort(&tongxun);
			break;
		case 6:
			search(&tongxun);
			break;
		default:
			printf("输入错误\n");
			break;
		}


	} while (input);
	return 0;
}