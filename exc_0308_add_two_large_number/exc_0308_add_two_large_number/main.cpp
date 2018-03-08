
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

bool valid = true;

char *reverse_num(const char *num)
{
	int len = strlen(num);
	char *rnum = (char *)malloc(sizeof(char) * (len + 1));
	rnum[len] = '\0';

	for (int i = 0; i < len; ++i)
	{
		if (num[len - i - 1] >= '0' && num[len - i - 1] <= '9')
			rnum[i] = num[len - i - 1];
		else
		{
			printf("Error! not a number!\n");
			system("pause");
			exit(-1);
		}
	}

	return rnum;
}

char *addLargeNum(char const *num1, char const *num2)
{
	if (!num1 || !num2)
	{
		valid = false;
		return NULL;
	}

	int l1 = strlen(num1);
	int l2 = strlen(num2);

	if (l1 <= 0 || l2 <= 0)
	{
		valid = false;
		return NULL;
	}

	char *rnum1 = reverse_num(num1); // if we dont reverse, then we use three pointers to point each num, i.e., num1, num2, rslt
	char *rnum2 = reverse_num(num2);

	int max = (l1 > l2) ? l1 : l2;
	char *rslt = (char *)malloc(sizeof(char) * (max + 2));
	memset(rslt, '0', max + 1);
	rslt[max + 1] = '\0';

	int carry = 0;
	for (int i = 0; i < max + 1; ++i)
	{
		int n1 = 0, n2 = 0;
		if (i < l1)
			n1 = rnum1[i] - '0';
		if (i < l2)
			n2 = rnum2[i] - '0';

		int n = n1 + n2 + carry;

		if (n >= 10)
		{
			carry = 1;
			n -= 10;
		}
		else
		{
			carry = 0;
		}
		rslt[i] = n + '0';
	}

	return rslt;
}

void test(int n, char const *num1, char const *num2)
{
	printf("Test[%d] ", n);
	char *rslt = addLargeNum(num1, num2);
	if (valid)
	{
		bool isBegin = true;
		int len = strlen(rslt);
		for (int i = len - 1; i >= 0; --i)
		{
			if (isBegin && rslt[i] == '0')
				continue;
			else
			{
				isBegin = false;
				printf("%c", rslt[i]);
			}
		}
		printf("\n");
	}
	else
	{
		printf("Error!\n");
	}
}

void test1()
{
	char *n1 = "123";
	char *n2 = "1345";

	test(1, n1, n2);
}

void test2()
{
	char *n1 = "0";
	char *n2 = "999";

	test(2, n1, n2);
}

void test3()
{
	char *n1 = "1";
	char *n2 = "999";

	test(3, n1, n2);
}

void test4()
{
	char *n1 = "";
	char *n2 = "9f9";

	test(4, n1, n2);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();
	test4();

	system("pause");
	return 0;
}
