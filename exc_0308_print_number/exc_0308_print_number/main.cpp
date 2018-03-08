
/*
big number
*/

# include <stdio.h>
# include <stdlib.h>
# include <iostream>

bool valid = true;
//----
int getMaxNDig(int n)
{
	int num = 1;
	for (int i = 0; i < n; ++i)
		num *= 10;

	return num;
}

void printN(int n)
{
	if (n <= 0)
	{
		valid = false;
		return;
	}

	int max = getMaxNDig(n);
	for (int i = 1; i < max; ++i)
		printf("%d ", i);
	printf("\n");
}
//----

// the answer

bool increment(char *num)
{
	int len = strlen(num);

	int carry = 0;
	for (int i = len - 1; i >= 0; --i)
	{
		int n = num[i] - '0' + carry; // n <= 10
		
		if (i == len - 1) // if the i point to the unit digit, then increase 1
			++n;
		if (n >= 10) // if there is a carry
		{
			if (i == 0) // if the highest digit is carried, then overflow
			{
				return true;
			}
			else // else, carry
			{
				carry = 1;
				n -= 10;
				num[i] = '0' + n;
			}
		}
		else // if there is no carry
		{
			carry = 0; // actually is verbose
			num[i] = '0' + n;
			break; // no need to go far
		}
	}

	return false;
}

void print(const char *num)
{
	int i = 0;
	while (num[i] == '0')
		++i;

	for (; num[i] != '\0'; ++i)
		printf("%c", num[i]);
	printf(" ");
}

void printN_(int n)
{
	if (n <= 0)
	{
		valid = false; // unvalid input
	}

	char *number = (char *)malloc(sizeof(char) * (n + 1));
	memset(number, '0', n);
	number[n] = '\0';

	while (!increment(number))
		print(number);

	free(number);
	printf("\n");
}

void test(int i, int n)
{
	printf("Test[%d]", i);
	printN_(n);
}

void test1()
{
	test(1, 1);
}

void test2()
{
	test(2, 2);
}

void test3()
{
	test(3, 3);
}

int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
