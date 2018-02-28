
# include <stdio.h>
# include <stdlib.h>

# define LEN 100


void mergeArr(int *a, int len1, int *b, int len2)
{
	int i = len1 - 1;
	int j = len2 - 1;
	int t = len1 + len2 - 1;

	while (i > -1 && j > -1)
	{
		if (a[i] >= b[j])
		{
			a[t] = a[i];
			--i;
		}
		else
		{
			a[t] = b[j];
			--j;
		}
		--t;
	}
}


void test(int n, int *a, int len1, int *b, int len2)
{
	mergeArr(a, len1, b, len2);

	printf("Test%d: ", n);
	for (int i = 0; i < len1 + len2; ++i)
		printf("%d ", a[i]);
	printf("\n--------------------------------\n");
}

void test1()
{
	int a[LEN] = { 1,2,3,4,5,6,7 };
	int b[] = { 3,4,5,6 };

	test(1, a, 7, b, 4);
}

void test2()
{
	int a[LEN] = { 1,2,3,4,5,6,7 };
	int b[] = { 8,9,10,11 };

	test(2, a, 7, b, 4);
}

void test3()
{
	int a[LEN] = { 5,6,7,8,9,10,11 };
	int b[] = { 1,2,3,4 };

	test(3, a, 7, b, 4);
}

int main(void)
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
