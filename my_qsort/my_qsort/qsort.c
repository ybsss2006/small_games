#include<stdio.h>
#include<string.h>
#include<assert.h>

void* my_memcpy(void* dest, const void* src, int num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			dest=(char*)dest+1;
			src=(char*)src+1;
		}
	}
	else if (dest == src)
		return ret;
	else
	{
		while (num--)
		{
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}





//next数组实现
void next_cometure(const char* str2,int num,int* next)
{
	assert(str2 && next);
	int len = 0;//共同前后缀的长度
	next[0] = 0;
	int i = 1;
	while (i < num)
	{
		if (str2[len] == str2[i])
		{
			len ++;
			next[i] = len;
			i++;
		}
		else
		{
			if (len == 0)
			{
				next[i] = 0;
				i++;
			}
			else
				len = next[len - 1];
		}
	}
	
}
//KMP算法实现
char* kmp(const char* str1, const char* str2,int*next)
{
	assert(str1 && str2);
	const char* s1 = str1;//主串指针
	const char* s2 = str2;//子串指针
	const char* p = str1;
	int i = 0;//记录s2所指向子串的位置
	while (*s1)
	{
		
		p = s1;//记录首地址
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
			i++;
		}
		if (*s2 == '\0')
			return (char*)p;
		else if (*s1 == '\0')
			return NULL;

		if (s2 == str2)
			s1++;
		else
		{
			s2 = str2 + next[i - 1];//指针回溯
			i = next[i - 1];//跟随s2
		}

		
	}
	return NULL;
}
//BF算法求子串
char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* p = str1;
	while (*p)
	{
		s1 = p;
		s2 = str2;
		while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
			return (char*)p;
		else if (*s1 == '\0')
			return NULL;

		p++;
	}
	return NULL;
}

char* my_strcpy(char* des, const char* source)
{
	assert(des && source);
	char* ret = des;
	while (*source != '\0')
	{
		assert(des && source);
		
		*des = *source;
		des++;
		source++;
	}
	*des = *source;
	return ret;
}
//int类型的数据比较
int cmp1(const void* bu1, const void* bu2)
{
	return *((int*)bu1) - *((int*)bu2);
}


void swap(char*nu1,char*nu2,int width)
{
	for (int i = 0; i < width; i++)
	{
		char temp = *nu1;
		*nu1 = *nu2;
		*nu2 = temp;
		nu1++;
		nu2++;
	}
}
//base 数组地址
//se  元素个数
//width 元素字节长度
//cmp判断函数
void my_qsort(void* base, int se, int width, int (*cmp)(const void* bu1, const void* bu2))
{
	for (int i = 0; i < se - 1; i++)
	{
		int pd = 1;
		for (int j = 0; j < se - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width)>0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
				pd = 0;
			}
		}
		if (pd == 1)
		{
			break;
		}
	}
}
int main()
{
	/*int arr1[] = { 5,7,1,8,9,5,4,8,4,5,7 };
	my_qsort(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), cmp1);
	for (int i = 0; i < sizeof(arr1) / sizeof(arr1[0]); i++)
	{
		printf("%d ", arr1[i]);
	}
	char ji[20] = { 0 };
	char iu[] = "ihsdfusohu";
	my_strcpy(ji, iu);
	strcpy(ji, iu);
	printf("%s\n", ji);*/
	//---------------------------------------------------------
	/*char a[] = "hhhuutffhdkuhdkkdjhdjjhhhhhgddgdg";
	char b[] = "hdkkdjhdjjhh";
	char* c = my_strstr(a, b);
	printf("%s\n", c);
	

	int next[50] ;
	next_cometure(b, (int)strlen(b), next);
	for (int i = 0; i < strlen(b); i++)
		printf("%d ", next[i]);
	printf("\n");
	char* ret = kmp(a, b, next);
	printf("%s\n", ret);*/
	//--------------------------------------------------------------
	/*char* c1 = "abcabcddc";
	int next[9];
	next_cometure(c1, strlen(c1), next);
	for (int i = 0; i < 9; i++)
		printf("%d\n", next[i]);*/
	//---------------------------------------------------------------
	int srr1[] = { 5,8,9,7,98,8,9,5,8,9,6,4,5,2,0,1,0,3,0 };
	my_memcpy(srr1 + 4, srr1, 16);
	for (int i = 0; i < 10; i++)
		printf("%d\n", srr1[i]);





	return 0;
}