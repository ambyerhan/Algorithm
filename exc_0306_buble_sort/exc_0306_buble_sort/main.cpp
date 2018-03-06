
# include <stdio.h>
# include <stdlib.h>

# define LEN 100

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void buble_sort(int *arr, int len)
{
	if (!arr)
	{
		printf("Error!");
		return;
	}
	int d = len;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < d - 1; ++j)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
		d -= 1;
	}
}

void test(int n, int *arr, int len)
{
	printf("[%d]", n);
	buble_sort(arr, len);
	for (int i = 0; i < len; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

void test1()
{
	int arr[LEN] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	test(1, arr, 10);
}

void test2()
{
	int arr[LEN] = { 1 };
	test(2, arr, 1);
}

void test3()
{
	int arr[LEN] = { 6, 9, 7, 5, 10, 1, 4, 2, 8, 3 };
	test(3, arr, 10);
}
int main(int argc, int *argv[])
{
	test1();
	test2();
	test3();

	system("pause");
	return 0;
}
