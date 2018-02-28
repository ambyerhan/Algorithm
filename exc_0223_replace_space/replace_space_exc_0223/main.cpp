
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define LEN 100

void replaceSpace(char *str)
{
	if (str == NULL)
	{
		printf("Error!\n");
		system("pause");
		exit(-1);
	}

	int scnt = 0, len = 0;
	for (int i = 0; '\0' != str[i]; ++i)
	{
		if (str[i] == ' ')
			scnt += 1;
		len += 1;
	}

	int length = len + 2 * scnt;
	int tail = length - 1;
	int ptr = len - 1;

	if (tail + 1 > LEN) // err: new len must be shorter than max-len
		return;

	for (; ptr > -1 && tail > ptr; --ptr, --tail) // tail > ptr --> means if there is no space anymore then we should stop
	{
		if (str[ptr] == ' ')
		{
			str[tail--] = '0';
			str[tail--] = '2';
			str[tail/*--*/] = '%'; // err: there is dsc in for
			//--ptr; // err: there is dsc in for
		}
		else
			str[tail] = str[ptr];
	}
	str[length] = '\0';
}

void test(int n, char *str)
{
	replaceSpace(str);
	if (str == NULL)
		printf("Test%d: NULL", n);
	else
		printf("Test%d: %s\n", n, str);
}

void test1()
{
	char str[LEN] = "we are happy!";
	test(1, str);
}

void test2()
{
	char str[LEN] = "we are ";
	test(2, str);
}

void test3()
{
	char str[LEN] = " we are";
	test(3, str);
}

void test4()
{
	char str[LEN] = "we  are";
	test(4, str);
}

void test5()
{
	char str[LEN] = "";
	test(5, str);
}

void test6()
{
	char str[LEN] = "  ";
	test(6, str);
}


void test7()
{
	char str[LEN] = "  ";
	test(7, NULL);
}

int main(void)
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	
	system("pause");
	return 0;
}
